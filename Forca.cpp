#include "Forca.h"
#include <cstdlib>

std::string Forca::Sortear()
{
    int n = rand() % TAM;
    return palavras[n];
}
std::string Forca::montarP2(int tam)
{
    std::string P2 = "";
    for (int i = 0; i < tam; i++)
    {
        P2 += "-";
    }
    return P2;
}
void Forca::mostra(std::string P2, std::string letras, int jogadas)
{
    system("clear");
    std::cout<<"Você pode errar mais "<<6-jogadas<<"x"<<std::endl;
    std::cout << "Palavra gerada:" << P2 << std::endl;
    std::cout << "Letras informadas:" << letras << std::endl;
}
std::string Forca::AchouLetra(std::string P1, std::string P2, char L, bool *achei)
{
    *achei = false;
    for (int i = 0; i < P1.length(); i++)
    {
        if (P1[i] == L)
        { // Se achar alguma letra
            P2[i] = L;
            *achei = true;
        }
    }
    return P2;
}
bool Forca::ComparaPalavras(std::string P1, std::string P2)
{
    int j = 0;
    for (int i = 0; i < P1.length(); i++)
    {
        if (P2[i] != P1[i])
        { // Vê sê tem hifem
            j++;
        }
    }
    //
    if (j == 0)
    {
        return true;
    }
    else
    {

        return false;
    }
}
char Forca::recebeLetra()
{
    char L;
    std::cout << "Informe a sua letra:";
    std::cin >> L;
    return L;
}
