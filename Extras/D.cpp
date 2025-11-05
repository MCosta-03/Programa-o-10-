#include <iostream>

using namespace std;

int main() {
    int N;
    int pessoas = 0;
    int space = 0;
    int avaliable = 0;

    char n;

    cin >> N;
    cin >> pessoas;

    for (int Y = 0; Y < N; Y++) {
        for (int X = 0; X < N; X++) {
            cin >> n;
            if (n == '.') {
                space++;
            }
            if (n == '#') {
                space = 0;
            }

            if (pessoas == space) {
                space = 0;
                avaliable++;
            }
        }
    }
    cout << avaliable;

    return 0;
}