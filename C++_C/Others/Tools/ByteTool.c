#include <stdio.h>
#include <stdlib.h>

int GetFileSize(FILE* f) {
	fseek(f, 0, SEEK_END);
	int filesize = ftell(f);
	fseek(f, 0, SEEK_SET);

	return filesize;
}

typedef struct {
	int offset;
	int len;
	int view_width;
	int real_len;
	int modify;
}   int2;

int2 custom;
int option;
int2 ask_for_custom() {
	printf("0 -> start reading, 1 -> customize: ");
	scanf("%d", &option);

	if (option == 1) {
		printf("Start reding offset: ");
		scanf("%d", &custom.offset);

		printf("Much to read: ");
		scanf("%d", &custom.len);

		printf("View Width: ");
		scanf("%d", &custom.view_width);

		printf("You will modify(1/0): ");
		scanf("%d", &custom.modify);

		if (custom.view_width > 50) {
			printf("50 is the max for view_width.");
			custom.view_width = 50;
		}

		if (custom.offset + custom.len > custom.real_len) {
			int last_len = custom.len;
			custom.len = custom.real_len - custom.offset;

			printf("%d is overflow, assuming %d\n\n", last_len, custom.len);
		}
	}
	else {
		custom.offset = 0;
		custom.len = custom.real_len;
		custom.view_width = 16;
	}
	return custom;
}

char filename[128] = { ' ' };
int first_time = 0;
void displayFile() {
	FILE* f = fopen(filename, "rb");
	int fsz = GetFileSize(f);

	custom.real_len = fsz;
	if (first_time == 0) {
		custom = ask_for_custom();
		first_time++;
	}
	int viewWidth = custom.view_width;

	char view[50] = { ' ' };
	char view_n[50] = { ' ' };
	int busyLine = 0;

	printf("file size: %d\n\n", fsz);

	fseek(f, custom.offset, SEEK_SET);
	for (int i = 0; i < custom.len; i++) {
		char temp = fgetc(f);
		view_n[busyLine] = temp;

		if (temp != '\n' && temp != '\r' && temp != '\t')	view[busyLine] = temp;
		else				view[busyLine] = '.';

		if (temp < 32)   view[busyLine] = '.';

		if (temp == ' ')view[busyLine] = '.';
		else if (temp == 0)	view[busyLine] = '.';

		busyLine++;

		if (busyLine == viewWidth) {
			busyLine = 0;

			for (int A = 0; A < viewWidth; A++)
				printf("%c", view[A]);
			printf("    ");
			for (int A = 0; A < viewWidth; A++) {
				if (view_n[A] < -100)                       printf(" %d", view_n[A]);
				else if (view_n[A] < -10)                    printf("  %d", view_n[A]);
				else if (view_n[A] < 0 && view_n[A] > -10)  printf("   %d", view_n[A]);
				else if (view_n[A] < 10)                     printf("    %d", view_n[A]);
				else if (view_n[A] < 100)                    printf("   %d", view_n[A]);
				else if (view_n[A] > 100)                    printf("  %d", view_n[A]);
			}
			printf("\n");
		}
	}
	fclose(f);
}

int main() {
	printf("File name to view: ");
	scanf("%s", &filename);

	displayFile();

	int n_to_modify = 0;
	int offset_to_modify = 0;
	if (custom.modify == 1) {
		printf("\nexit: offset:-1, you just can modify until: %d\n", custom.len);
		while (custom.offset != -1) {
			printf("Get offset: ");
			scanf("%d", &offset_to_modify);	

			if (offset_to_modify < custom.len) {
				printf("Modify number(decimal [-255 : 255]) for: ");
				scanf("%d", &n_to_modify);

				FILE* f_modify = fopen(filename, "r+");
				fseek(f_modify, offset_to_modify, SEEK_SET);
				fputc(n_to_modify, f_modify);
				fclose(f_modify);

				displayFile();
			}
			else {
				printf("%d is overflow.\n", offset_to_modify);
			}
		}
		custom.modify = 0;
	}
	return 0;
}
