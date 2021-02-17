 #include <iostream>
 #include <fstream>
 #include <string.h>
 #include <map>
 #include "Balde.h"

using namespace std;


Balde::Balde(int profundidadeLocal,int tamBalde){
    this->profundidadeLocal=profundidadeLocal;
    this->tamBalde=tamBalde;
}
 

 Balde::~Balde(){}


int Balde::getprofundidadeLocal(){

    return profundidadeLocal;

}

int Balde::gettam(){
    return tamBalde;

}


int Balde::aumenta_profundidade_local(){

    profundidadeLocal++;
    return profundidadeLocal;
}

std::string Balde::valores(int i){

   return balde[i];
    
}


int Balde::insere_chave_balde(string psCh){

    if(verifica_balde_cheio()){
        cout<<"Balde cheio"<<endl;
         return 0;
    }else if(baldevazio()){
        balde.push_back(psCh);
        return 2;

    }else if(busca_pseudoch(psCh)){
        cout<<"JA TEM NO BALDE"<<endl;
        return -1;
    }else{
        balde.push_back(psCh);
        return 1;
    }


 }

bool Balde::baldevazio(){

    if(balde.empty()){
        return true;
    
    }else{
        return false;
    }

}

int Balde::getSize(){
    return balde.size();
}
void Balde::apaga(string ch){

    int index;
  
    for(int i=0;i<tamBalde;i++){

            if(balde[i]==ch){
                cout<<"Apagada: "<<balde[i];
                index = i;
            }
    }
     cout<<"Apagada: "<<balde[index];
    balde.erase(balde.begin()+index);

}
void Balde::imprimeBalde(){

    for(int i=0;i<balde.size();i++){
        
        cout<<"["<<i<<"] "<<balde[i]<<endl;
        
    }
}
 bool Balde::verifica_balde_cheio(){

     if(balde.size()==tamBalde){
         return true;
     }else
     {
         return false;
     }
     
 }

bool  Balde::busca_pseudoch(string ch){


    if(!balde.empty()){
            
        for(int i=0;i<=tamBalde;i++){
            if(balde[i]==ch){
                cout<<"Inserido: "<<balde[i]<<endl;
            return true;
            }
    }
    }else
        return false;
    return false;
}  
 //inserir chave no balde
 //verficar se esta cheio
 //verifica profundidade do balde d --- numeros de d bits inicias
 
 //Iserir no balde utilizando o "map"

