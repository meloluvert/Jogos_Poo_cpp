
//   g++ -o Jogos_C++_POO Forca.* Velha.* Senha.* main.cpp


#include "Forca.h"
#include "Velha.h"
#include "Senha.h"

#include <ctime>
using namespace std;

int main()
{
    /*Forca*/
    Forca F;
    string p1, p2, letras;
    char L;
    bool achei, acertou;
    int op, jogadas;
    srand(time(NULL));

    /*Velha*/
    Velha V;
    bool j1, j2;
    int i, j;

    Senha S;
    int acertos = 0;
    do
    {

        // system("clear");
        cout << "(1) Jogo da Forca" << endl;
        cout << "(2) Jogo da Velha" << endl;
        cout << "(3) Jogo da Senha" << endl;
        cout << "(4) Sair" << endl;
        cin >> op;

        switch (op)
        {
        /*Forca*/
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
                F.mostra(p2, letras, jogadas);
                cout << "Parabéns"<<endl;
            }
            else
            {
                cout << "Perdeu, a palavra era '" << p1 << "'" << endl;
                cout << "---------------------------" << endl;
            }
            break;
        /*Velha*/
        case 2:

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    V.v[i][j] = '\0';
                }
            }
            jogadas = 0; // zera as jogadas
            j1 = j2 = false;
            do
            {
                V.desenhaJogo(jogadas);
                /*PEDE AS POSIÇÕES*/

                // posicoes = vetor linha, coluna
                // J1
                V.pedeXy('X');
                jogadas++;
                if (V.verificaSeGanhou('X', i - 1, j - 1))
                {
                    V.desenhaJogo(jogadas);
                    cout << "Parabéns J1!" << endl;
                    j1 = true;
                    break;
                }

                V.desenhaJogo(jogadas);
                if (V.verificaEmpate(jogadas, j1, j2))
                {
                    break;
                }

                // J2

                V.pedeXy('O');
                jogadas++;
                if (V.verificaSeGanhou('O', i - 1, j - 1))
                {
                    V.desenhaJogo(jogadas);
                    cout << "Parabéns J2!" << endl;
                    j1 = true;
                    break;
                }

                if (V.verificaEmpate(jogadas, j1, j2))
                {
                    break;
                }
            } while (jogadas < 9 && !j1 && !j2);
            cout << "---------------------------" << endl;
            break;

        /*Senha*/
        case 3:
            S.GerarSenha();
            jogadas = 1; //para o jogo não começar com jogada 0
            acertou = false;
            do{
                
                S.mostraJogo(jogadas);
                
                for(i=0;i<4;i++){
                        S.palpites[jogadas-1][i]= S.palpite[i];
                }
                
                S.sequenciaDeAcertos[jogadas-1] = acertos =  S.verificaAcertos();
                
                if(acertos==4){
                    acertou=true;
                }else{jogadas++;
                cout<<acertos<<"acertos"<<endl;}
            }while(jogadas<=10 && !acertou);

            if(acertou){
                cout<<"Parabéns! Obrigado por jogar!"<<endl;
            }else{
                cout<<"Não conseguiu! A senha era:";
            for(i=0;i<4;i++){
                cout<<S.senha[i]<<" ";
            }
             }

            break;
            
        case 4:
            cout << "Obrigado por testar!" << std::endl;
            break;
        default:
            cout << "Opção inválida";
            break;
        } // vai pausar o jogo até continuarmos
    } while (op != 4);
    return 0;
}
