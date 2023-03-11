
//g++ -std=c++11 -fdiagnostics-color=always -g main.cpp Forca.cpp Velha.cpp -o jogo_da_forca

#include "Forca.h"
#include "Velha.h"
#include <ctime>
using namespace std;

int main()
{
    Forca F;
    string p1, p2, letras;
    char L;
    bool achei, acertou;
    int op, jogadas = 0;
    srand(time(NULL));

    /*Universais*/
    char L;
    int jogadas = 0;

    Velha V;
    char v[3][3];
    bool j1, j2;
    int i, j;

    do
    {
        system("clear");
        cout << "(1) Jogo da forca" << endl;
        cout << "(2) Jogo da Velha" << endl;
        cout << "(3) Sair" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            p1 = F.Sortear();
            letras = "";
            p2 = F.montarP2(p1.length());
            acertou = false;
            do
            {
                /*Mostra o jogo*/
                F.mostra(p2, letras, jogadas);
                /*recebe a letra*/
                L = F.recebeLetra();
                /*coloca a letra na string letras*/
                letras += L;

                p2 = F.AchouLetra(p1, p2, L, &achei);
                if (!achei)
                {
                    jogadas++;
                }
                if (F.ComparaPalavras(p1, p2))
                {
                    acertou = true;
                }

            } while (jogadas < 6 && !acertou);
            if (acertou)
            {
                cout << "Parabéns";
            }
            else
            {
                cout << "Perdeu, a palavra era '" << p1 << "'" << endl;
            }
            break;


        case 2:


                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            v[i][j] = '\0';
                        }
                    }
                jogadas = 0; // zera as jogadas
                j1 = j2 = false;
                do
                {
                V.desenhaJogo(v,jogadas);
            do
            {
                cout << "J1, informe a posição:" << endl;
                cout << "Linha:";
                cin >> i;
                cout << "Coluna:";
                cin >> j;
            } while (v[i - 1][j - 1] != '\0');
            v[i - 1][j - 1] = 'X';
            jogadas++;
            if (V.verificaSeGanhou(v,'X', i - 1, j - 1))
            {
                V.desenhaJogo(v,jogadas);
                cout << "Parabéns J1!" << endl;
                j1 = true;
                break;
            }
            V.desenhaJogo(v, jogadas);
            if (jogadas == 9 && !j1 && !j2)
            {
                cout << "Deu véia";
                break;
            }
            do
            {
                cout << "J2, informe a posição" << endl;
                cout << "Linha:";
                cin >> i;
                cout << "Coluna:";
                cin >> j;
            } while (v[i - 1][j - 1] != '\0');
            v[i - 1][j - 1] = 'O';
            jogadas++;
            if (V.verificaSeGanhou(v,'O', i - 1, j - 1))
            {
                V.desenhaJogo(v, jogadas);
                cout << "Parabéns J2!";
                j2 = true;
                break;
            }
            // Acabou as jogadas e ninguém ganhou
            if (jogadas == 9 && !j1 && !j2)
            {
                cout << "Deu véia" << endl;
                break;
            }
             } while (jogadas < 9 && !j1 && !j2);
            break;
        case 3:
            cout<<"tchau";
        default:
            cout<<"opção inválida";
            break;
        } //vai pausar o jogo até continuarmos
    }while(op!=3);
    return 0;
}
