#include <iostream>
class Velha
{
public:
    void desenhaJogo(char[][3], int);
    bool verificaSeGanhou(char[][3], char, int, int);
    bool verificaEmpate(int, bool, bool);
    int *pedeXy(char, char[][3]);
};
