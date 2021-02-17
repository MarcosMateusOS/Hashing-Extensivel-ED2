#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <vector>


using namespace std;

class Balde
{
private:
    
    //Tamanho Balde e sua profundidade
    int tamBalde;
    int profundidadeLocal;
    //Balde
    std::vector<string> balde;
   
    
public:
    Balde(int profundidadeLocal,int tamBalde);
    ~Balde();
    bool verifica_balde_cheio();
    bool verifica_espaco_balde();
    int insere_chave_balde(string psch);
    bool busca_pseudoch(string ch);
    int getprofundidadeLocal();
    int aumenta_profundidade_local();
    std::string valores(int ind);
    void apaga(string ch);
    bool baldevazio();
    int getSize();
    int gettam();
    void imprimeBalde();
    

};




