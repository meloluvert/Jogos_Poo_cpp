//g++ -std=c++11 -fdiagnostics-color=always -g main.cpp Forca.cpp -o jogo_da_forca

#include "Forca.h"
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
            } while ((jogadas < 6 && !acertou));
            if (acertou)
            {
                cout << "Parabéns";
            }
            else
            {
                cout << "Perdeu, a palavra era '" << p1 << "'" << endl;
            }
            break;
        case 3:
            cout<<"tchau";    
        default:
            cout<<"opção inválida";
            break;
        }
        cin.ignore().get(); //vai pausar o jogo até continuarmos
    }while(op!=3);
    return 0;
}
