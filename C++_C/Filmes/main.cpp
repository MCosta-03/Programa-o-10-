#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void Limpar_ecran() {
    system("cls");
}

int Diz_me_o_melhor_filme(int avaliacao[4]){
    int maior_avaliacao = 0;
    int filme_com_maior_avaliacao = 0;
    for(int i = 0; i < 4; i++){
        if(maior_avaliacao < avaliacao[i]){
            filme_com_maior_avaliacao = i;
            maior_avaliacao = avaliacao[i];
        }
    }

    return filme_com_maior_avaliacao;
}

void Diz_me_todos_os_filmes(string filmes[4]){
    cout << "Todos os filmes:\n";
    for(int i = 0; i < 4; i++)
        cout << "O " << i+1 << "º filme foi: " << filmes[i] << ".\n";
    
    cout << "\n";
}

void Diz_me_as_avaliacoes(string filmes[4], int avaliacao[4]){
    cout << "As avaliações de todos os filmes:\n";

    for(int i = 0; i < 4; i++)
        cout << "O filme " << filmes[i] << " teve " << avaliacao[i] << " avaliações.\n";
    
    cout << "\n";
}

int main(){
	setlocale(LC_ALL, "Portuguese"); 

    /*ó espirito santo, acho que percebes certo? ou não? Eu acho que não 😊*/

    int avaliacao[4] = {0};
    string filmes[4], ator[4], atriz[4], foto[4], bandasonora[4];

    /*RAFA OLHA🚨, primeiro vamos recolher os dados, não é dentro do switch só para ficar mais clean😁*/
    cout << "Vou perguntar 4 filmes, melhores atores, atrizes, fotografias, e bandas sonoras...\n\n";
    for(int i = 0; i < 4; i++){
        cout << "Diz o " << i +1 << "º filme: ";
        getline(cin, filmes[i]);
    }

    for(int i = 0; i < 4; i++){
        cout << "Diz o melhor ator no filme " << filmes[i] << " :";
        cin >> ator[i];

        cout << "Diz a melhor atriz no filme " << filmes[i] << " :";
        cin >> atriz[i];

        cout << "Diz a melhor fotografia no filme " << filmes[i] << " :";
        cin >> foto[i];

        cout << "Diz a melhor banda sonora no filme " << filmes[i] << " :";
        cin >> bandasonora[i];

        while(avaliacao[i] < 1 || avaliacao[i] > 5){
            cout << "Diz a avaliação de 1 a 5 do filme " << filmes[i] << " :";
            cin >> avaliacao[i];
            
            if(avaliacao[i] < 1 || avaliacao[i] > 5)
                cout << "Avaliação inválida! Tenta outra vez...\n";
        }
        cout << "\n";
    }

    int escolha = 0;
    do {
        /*Um menu maravilhoso.*/
        cout << "O------------------------------------------O\n"
            "|  MENU de filmes.                         |\n"
            "O------------------------------------------O\n"
            "|  1 - Avaliações.                         |\n"
            "|  2 - Ver o nome de todos os Filmes.      |\n"
            "|  3 - Mostrar qual escolhido escolhido.   |\n"
            "|  0 - Sair.                               |\n"
            "O------------------------------------------O\n" << endl;
        cin >> escolha;

        /*Neste switch mágico tu só chamas as funções para ser mais clean*/
        switch (escolha)
        {
        case 1:
            Limpar_ecran();
            Diz_me_as_avaliacoes(filmes, avaliacao);
            break;
        case 2:
            Limpar_ecran();
           Diz_me_todos_os_filmes(filmes);
            break;
        case 3:
           Limpar_ecran();
            cout << "O melhor filme foi: " << filmes[Diz_me_o_melhor_filme(avaliacao)] << ".\n\n";
            break;
        case 0:
           return 0;
            break;
        default:
            Limpar_ecran();
            cout << "Opção inválida, tenta outra vez...\n";
            break;
        }
    } while (true);
	return 0;
}
