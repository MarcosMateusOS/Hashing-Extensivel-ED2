#include <iostream>
#include <fstream>
#include <string.h>

#include <map>
#include <cmath>
#include <bitset>   
#include "Diretorio.h"
 

using namespace std;

Diretorio::Diretorio(int baldeTamanho){
    this->profundidadeGlobal=1;
    this->baldeTamanho=baldeTamanho;

    Balde *novoBalde=new Balde(0,baldeTamanho);

    for(int i=0;i<1<<profundidadeGlobal;i++){
        baldes.push_back(novoBalde);
       
    }

}






 int Diretorio::pega_Indice(int indexBalde, int profundidade){

     //retorna o Index do balde e sua profundidade
     return indexBalde^(1<<profundidade-1);
     
 }

void Diretorio::particionaDiretorio(){

    //Aumenta a profunidade global;
    profundidadeGlobal++; 
    for(int i = 0 ; i < 1<<(profundidadeGlobal-1); i++ ){ 
        //desloca o diretorio de acordo com os bits da profundidadeGlobal
        baldes.push_back(baldes[i]);
        } //adciona o valor no Balde na posicao i
    
}


void Diretorio::duplicaBalde(int index,string ch){

   
    
    
    int i=pega_Indice(index,profundidadeGlobal); 
    int index1=min(index,i);
    int index2=max(index,i);
   
   cout<<"Index1: "<<index1<<endl;
   cout<<"Index2: "<<index2<<endl;

  
    baldes[index]->imprimeBalde();
    

     //Crias dois novos baldes
    Balde *novo1=new Balde(baldes[index]->getprofundidadeLocal(),baldeTamanho);
    Balde *novo2=new Balde(baldes[index]->getprofundidadeLocal(),baldeTamanho);

    novo1->insere_chave_balde(ch);
    string bitEsquerda = ch.substr(0,profundidadeGlobal);

    int tam = novo1->gettam();
    for(int i=1;i<tam;i++){

        std::string s=baldes[index]->valores(i);
        cout<<" "<<s<<endl;
        std::string bitEsquerdaS = s.substr(0,profundidadeGlobal);

        if(bitEsquerdaS.compare(bitEsquerdaS)){
             novo1->insere_chave_balde(s);
        }else{
            novo2->insere_chave_balde(s);
        }



    }

    cout<<"Balde 1:"<<endl;

    novo1->imprimeBalde();

    cout<<"Balde 2:"<<endl;
    novo2->imprimeBalde();

       
    //Associa os novos baldes com os index correpondentes as suas chaves  no diretorio 
    string s1 = novo1->valores(1);
    string bitEsquerdaB1 = s1.substr(0,profundidadeGlobal);
    int indexCorrespondeB1 = std::stoi(bitEsquerdaB1, 0, 2);

    cout<<"S1: "<<s1<<endl;
    cout<<"IndexBalde1: "<<indexCorrespondeB1<<endl;

     string s2 = novo2->valores(1);
     string bitEsquerdaB2 = s2.substr(0,profundidadeGlobal);
    int indexCorrespondeB2 = std::stoi(bitEsquerdaB2, 0, 2);

    cout<<"S2: "<<s2<<endl;
    cout<<"IndexBalde2: "<<indexCorrespondeB2<<endl;



    
    baldes[indexCorrespondeB1]=novo1;
    baldes[indexCorrespondeB2]=novo2;

    //Aumenta a profundidade dos baldes
    baldes[indexCorrespondeB1]->aumenta_profundidade_local();
    baldes[indexCorrespondeB2]->aumenta_profundidade_local();
   
}

void Diretorio::inserir(string ch){

   
    cout<<"Chave: "<<ch<<endl; 
    string bitEsquerda = ch.substr(0,profundidadeGlobal);

    cout<<"Bits Esquerda "<<bitEsquerda<<endl;

    int index = std::stoi(bitEsquerda, 0, 2);
    cout<<"Index: "<<index<<endl;

    int test=baldes[index]->insere_chave_balde(ch);
    cout<<endl;
    

    if(test==0){

        if(baldes[index]->getprofundidadeLocal()==profundidadeGlobal){
                cout<<"DIRETORIO CHEIO"<<endl;
                particionaDiretorio();
                duplicaBalde(index,ch);

        }else if(baldes[index]->getprofundidadeLocal()<profundidadeGlobal){
            cout<<"Duplicando Balde apenas"<<endl;
            duplicaBalde(index,ch);
        }
    }

}
    
    
 

void Diretorio::imprime(){

    cout<<endl;
    cout<<endl;

    for(int i=0;i<baldes.size();i++){
        cout<<"Index: "<<i<<endl;
        baldes[i]->imprimeBalde();
    }
}
//Usar como estrutura vector
