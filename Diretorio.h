#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <vector>
#include "Balde.h"

using namespace std;

class Diretorio
{

    private:
        int profundidadeGlobal;
        int baldeTamanho;
        std::vector <Balde*> baldes;
        float funcao_hash(int ch);      

    public:
        Diretorio(int baldeTamanho);
        void inserir(string ch);
        int pega_Indice(int indexBalde, int profundidadetGlobal);
        void particionaDiretorio();
        void duplicaBalde(int index,string ch);
        void imprime();
      
      

        




};