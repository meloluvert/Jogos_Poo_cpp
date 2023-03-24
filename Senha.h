#include <iostream>
class Senha 
{
    public:
        char palpites[10][4];
        
        char colors[4] = {'v', 'a', 'p', 'b'};
        char senha[4], palpite[4];
        int sequenciaDeAcertos[10]; //Exemplo, se o vetor for : 1,1,2; isso siginifca que ele acertou 1 da primeira e da segunda vez, 2 na terceira
        void GerarSenha();
        int verificaAcertos();
        void mostraJogo(int);   
};