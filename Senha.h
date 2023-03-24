#include <iostream>
class Senha 
{
    public:
        char palpites[10][4];

        char colors[4] = {'v', 'a', 'p', 'b'};
        char senha[4], palpite[4];
        void GerarSenha();
        int verificaAcertos();   
};