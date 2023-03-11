
// g++ main.cpp Forca.cpp Velha.cpp -o Jogos_C++_POO

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
    int op, jogadas;
    srand(time(NULL));

    /*Universais*/

    Velha V;
    char v[3][3];
    bool j1, j2;
    int i, j;

    do
    {

        // system("clear");
        cout << "(1) Jogo da Forca" << endl;
        cout << "(2) Jogo da Velha" << endl;
        cout << "(3) Sair" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            // limpando as varíáveis, para recomençar o jogo, não dê erro
            p1 = p2 = letras = "";
            jogadas = 0;
            // sorteia a palavra
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
                cout << "Parabéns"<<endl;
            }
            else
            {
                cout << "Perdeu, a palavra era '" << p1 << "'" << endl;
                cout << "---------------------------" << endl;
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
                V.desenhaJogo(v, jogadas);
                /*PEDE AS POSIÇÕES*/

                // posicoes = vetor linha, coluna
                // J1
                int *posicoes = V.pedeXy('X', v);
                v[posicoes[0] - 1][posicoes[1] - 1] = 'X';
                jogadas++;
                if (V.verificaSeGanhou(v, 'X', i - 1, j - 1))
                {
                    V.desenhaJogo(v, jogadas);
                    cout << "Parabéns J1!" << endl;
                    j1 = true;
                    break;
                }
                // Excluindo o vetor alocado dinamicamente para evitar vazamento de memória
                delete[] posicoes;
                V.desenhaJogo(v, jogadas);
                if (V.verificaEmpate(jogadas, j1, j2))
                {
                    break;
                }

                // J2

                posicoes = V.pedeXy('O', v);
                v[posicoes[0] - 1][posicoes[1] - 1] = 'O';
                jogadas++;
                if (V.verificaSeGanhou(v, 'O', i - 1, j - 1))
                {
                    V.desenhaJogo(v, jogadas);
                    cout << "Parabéns J2!" << endl;
                    j1 = true;
                    break;
                }
                delete[] posicoes;

                if (V.verificaEmpate(jogadas, j1, j2))
                {
                    break;
                }
            } while (jogadas < 9 && !j1 && !j2);
            cout << "---------------------------" << endl;
            break;
        case 3:
            cout << "Obrigado por testar!" << std::endl;
            break;
        default:
            cout << "opção inválida";
            break;
        } // vai pausar o jogo até continuarmos
    } while (op != 3);
    return 0;
}
