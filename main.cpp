#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include "Diretorio.h"

using namespace std;

//g++ -o hashing -O3 *.cpp    -> compila
//./hashing -> executa oq ta compilado

//Fase 1:
// 2)Implementar um "Tad" de balde
// 	-Armazenar pseudo-chaves("String")
	
// 3)Implementar um "Tad" para diretorio:
// 	-Inserir
// 	-Buscar
// 	-Dividir baldes
// 	-Duplica diretorio

void moduloTeste(int tam,int bits){


    Diretorio *diretorio = new Diretorio(tam);
    int escolha;
    std::string psdChaves;

    cout<<"[1]:Insercoes de N pseudo-chaves aleatorias"<<endl;
    cout<<"[2]:Insercoes de N pseudo-chaves escolhendo o bit inicial"<<endl;
    cin>>escolha;

    srand (time(NULL));


    if(escolha == 1){

        //Bits aletorio;
        for(int j=0;j<10;j++){

            for(int i=0;i<bits;i++){
                
                int teste=(rand()%100)%2;
                
                char o= teste;
                psdChaves+=std::to_string(teste);
            }

        diretorio->inserir(psdChaves); 
        psdChaves.clear();
        
        }
    cout<<"Termina"<<endl;
    diretorio->imprime();

    }if(escolha == 2){
        int primeirobit;
        cout<<"Escolha o primeiro bit da sua chave [0] e [1]"<<endl;
        cin>>primeirobit;
        
        //De acordo com a escolha do usuario o primeiro bit é fixo e o resto da chave aletoria entre 1 e 0
        char pri= primeirobit;
        psdChaves=std::to_string(primeirobit);

        for(int j=0;j<10;j++){

             psdChaves=std::to_string(primeirobit);


            for(int i=1;i<bits;i++){
                
                int teste=(rand()%100)%2;
                
                char o= teste;
                psdChaves+=std::to_string(teste);
            }

        diretorio->inserir(psdChaves); 
        psdChaves.clear();
        
        }

    }


}
	

int main() {

    cout<<"Teste MAIN "<<endl;


    int bits;
    int tamanhoBaldes;

    cout<<"Digite o tamanho do Balde: "<<endl;
    cin>>tamanhoBaldes;

    cout<<"Numero de de Bits para as  pseudo-chaves: "<<endl;
    cin>>bits;


    moduloTeste(tamanhoBaldes,bits);
   
   

    return 0;
}