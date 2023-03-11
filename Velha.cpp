#include "Velha.h"

void Velha::desenhaJogo(char (*v)[3], int jogadas)
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
bool Velha::verificaSeGanhou(char (*v)[3], char jogador, int l, int c)
{

    bool linha = (v[l][0] == jogador && v[l][1] == jogador && v[l][2] == jogador);
    bool coluna = (v[0][c] == jogador && v[1][c] == jogador && v[2][c] == jogador);
    bool diagP = (v[0][0] == jogador && v[1][1] == jogador && v[2][2] == jogador);
    bool diagS = (v[0][2] == jogador && v[1][1] == jogador && v[2][0] == jogador);

    if (linha || coluna || diagP || diagS)
    {
        return true;
    }

    // Se não houver vencedor, retornar false
    return false;
}
int *Velha::pedeXy(char z, char (*v)[3])
{
    int i, j;
    int *posicoes = new int[2];
    do
    {
        if (z == 'X')
        {
            std::cout << "J1, informe a posição:" << std::endl;
        }
        if (z == 'O')
        {
            std::cout << "J2, informe a posição:" << std::endl;
        }
        std::cout << "Linha:";
        std::cin >> i;
        std::cout << "Coluna:";
        std::cin >> j;
    } while (v[i - 1][j - 1] != '\0');

    posicoes[0] = i;
    posicoes[1] = j;
    return posicoes;
}

bool Velha::verificaEmpate(int j, bool j1, bool j2)
{
    if (j == 9 && !j1 && !j2) // se tiver 9 jogadas e ninguém ganhou
    {
        std::cout << "Deu véia" << std::endl;
        return true;
    }
    return false;
}