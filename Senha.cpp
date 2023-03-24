#include "Senha.h"

void Senha::GerarSenha(){
    for(int i=0;i<4;i++){
        senha[i] = colors[rand() % 4]; //vai colocar na senha uma das cores
    }
}
int Senha::verificaAcertos(){
    int acerto = 0;
    for(int i =0;i<4;i++){
        if(palpite[i] == senha[i])
            acerto++;
    }
    return acerto;
}