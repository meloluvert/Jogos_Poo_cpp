#include "Velha.h"

void Velha::desenhaJogo(char (*v)[3],int jogadas)
{
    system("clear||cls");
    std::cout << "    1  2  3" << std::endl;
    for (int i = 0; i < 3; i++)
    { // loop mostra as linhas
        std::cout << i + 1 << "   ";
        for (int j = 0; j < 3; j++)
        {
            if (v[i][j] != '\0')
            {
                std::cout << " " << v[i][j] << "|";
            }
            else
            {
                std::cout << " " << v[i][j] << " |";
            }
        }
        if (i != 2)
        {
            std::cout << std::endl
                 << "     __ __ __\n"
                 << std::endl;
        }
    }
    std::cout << std::endl
         << "Jogadas restantes:" << 9 - jogadas << std::endl;
}
bool Velha::verificaSeGanhou(char (*v)[3],char jogador, int l, int c)
{
char jogo[3][3];
//RETIRAR PARTE NO JOGO DPS
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            jogo[i][j]=v[i][j];
        }
    }
    bool linha = (jogo[l][0] == jogador && jogo[l][1] == jogador && jogo[l][2] == jogador);
    bool coluna = (jogo[0][c] == jogador && jogo[1][c] == jogador && jogo[2][c] == jogador);
    bool diagP = (jogo[0][0] == jogador && jogo[1][1] == jogador && jogo[2][2] == jogador);
    bool diagS = (jogo[0][2] == jogador && jogo[1][1] == jogador && jogo[2][0] == jogador);

    if (linha || coluna || diagP || diagS)
    {
        return true;
    }

    // Se não houver vencedor, retornar false
    return false;
}
