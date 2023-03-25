#include <iostream>
class Velha
{
public:
    char v[3][3];
    void desenhaJogo(int);
    bool verificaSeGanhou(char, int, int);
    bool verificaEmpate(int, bool, bool);
    void pedeXy(char);
};
