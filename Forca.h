#include <iostream>
class Forca
{
    


    public:
    void mostra(std::string, std::string, int);
        const int TAM = 89;
        /*essa classe string está dentro do espaço de nomes padrão*/
        
        std::string palavras[89] = {"sogra", "abacaxi", "banana", "melancia", "cachorro", "gato", "piano", "framboesa", "amora", "acerola", "caju", "frango", "galinha", "morango", "cereja", "kiwi", "porta", "tecnologia", "tatu", "resumo", "pipoca", "carambola", "abacate", "macaco", "laranja", "manga", "morcego", "papagaio", "jaca", "goiaba", "uva", "chocolate", "queijo", "bolo", "pipa", "casa", "mesa", "cadeira", "carro", "bicicleta", "barco", "navio", "peixe", "marisco", "lagosta", "caranguejo", "sushi", "pizza", "hamburguer", "arroz", "batata", "cenoura", "abobrinha", "berinjela", "couve", "alface", "tomate", "cebola", "alho", "salsa", "coentro", "chuchu", "vagem", "milho", "amendoim", "castanha", "noz", "pistache", "figo", "damasco", "nectarina", "margarida", "girassol", "rosa", "cravo", "lírio", "tulipa", "violeta", "cacto", "bambu", "pinheiro", "cedro", "jacarandá", "mangueira", "jambo", "cerejeira", "oliveira", "abacateiro", "jabuticabeira"};
        std::string Sortear();
        //só o tipo
        std::string montarP2(int); //mandar o p1.lenght()
        std::string AchouLetra(std::string,std::string,char,bool*);
        bool ComparaPalavras(std::string, std::string);
        char recebeLetra();
};
