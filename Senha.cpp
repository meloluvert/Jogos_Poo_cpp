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

void Senha::mostraJogo(int j){
    system("clear");
    std::cout<<"Você precisa acertar uma senha com as cores:  \n v - vermelho \n a - azul \n p - preto \n b - branco \n ==================== "<<std::endl;
    for(int i=0;i<j-1;i++){
        for(int j=0;j<4;j++){
                        std::cout<< palpites[i][j];
            }
                    std::cout<<"-"<<sequenciaDeAcertos[i]<<"acertos"<<std::endl;
            }
            
    std::cout<<" ==================== \nJogada "<<j<<std::endl;
    for(int i=0;i<4;i++){
        std::cout<<"Cor "<<i+1<<":";
        std::cin>>palpite[i];
    }
}