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

     //retorna o Index do balde de acordo com  sua profundidade
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


    
    //Crias dois novos baldes
    Balde *novo1=new Balde(baldes[index]->getprofundidadeLocal(),this->baldeTamanho);
    Balde *novo2=new Balde(baldes[index]->getprofundidadeLocal(),this->baldeTamanho);

    
    std::string bitEsquerda = ch.substr(0,profundidadeGlobal);
    novo1->insere_chave_balde(ch);

    
    for(int i=0;i<this->baldeTamanho;i++){

        std::string s=baldes[index]->valores(i);
        std::string bitEsquerdaS = s.substr(0,profundidadeGlobal);
        int compare=bitEsquerdaS.compare(bitEsquerda);

        if(compare==0){
             novo1->insere_chave_balde(s);
        }else{
         
          novo2->insere_chave_balde(s);
         
         }
    }   
           
          

   
    //Associa os novos baldes com os index correpondentes as suas chaves  no diretorio 
    
    
    
     for(int i=0;i<baldes.size();i++){

        if(!novo1->baldevazio()){

            std::string s1 = novo1->valores(0);
            std::string bitEsquerdaB1 = s1.substr(0,profundidadeGlobal);
            int indexCorrespondeB1 = std::stoi(bitEsquerdaB1, 0, 2);
            
            if(i==indexCorrespondeB1){
                 cout<<"B1:"<<endl;
                baldes[i]=novo1;
                baldes[i]->aumenta_profundidade_local();
                cout<<"P/Balde: "<<baldes[i]->getprofundidadeLocal();
                baldes[i]->imprimeBalde();
               break;
            }
           
        }else{
            int indexVazio=max(index,i);
            baldes[indexVazio]=novo1;
            baldes[indexVazio]->aumenta_profundidade_local();
            break;
        }
        
    }

    for(int i=0;i<baldes.size();i++){

        if(!novo2->baldevazio()){

            std::string s2 = novo2->valores(0);
            std::string bitEsquerdaB2 = s2.substr(0,profundidadeGlobal);
            int indexCorrespondeB2 = std::stoi(bitEsquerdaB2, 0, 2);

            if(i==indexCorrespondeB2){
                cout<<"B2:"<<endl;
                baldes[i]=novo2;
                baldes[i]->aumenta_profundidade_local();
                cout<<"P/Balde: "<<baldes[i]->getprofundidadeLocal();
                baldes[i]->imprimeBalde();
               break;

            }
           
        }else{
            int indexVazio=max(index,i);
            baldes[indexVazio]=novo2;
            baldes[indexVazio]->aumenta_profundidade_local();
            break;
        }


        
        }
        
        
}
   
    



void Diretorio::inserir(string ch){

   
    cout<<"Profundiade Mundial: "<<profundidadeGlobal<<endl;
    cout<<"Chave: "<<ch<<endl; 
    std::string bitEsquerda = ch.substr(0,profundidadeGlobal);
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
