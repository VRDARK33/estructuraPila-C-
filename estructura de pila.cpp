#include<stdlib.h>
#include<iostream>
#include "pilas.h"
using namespace std;



void menu(){
    cout<<"implementacion de pilas en c++\n\n";
    cout<<"1. apilar"<<endl;
    cout<<"2. desapilar"<<endl;
    cout<<"3. mostrar pila"<<endl;
    cout<<"4. destruir pila"<<endl;
    cout<<"5. invertir pila"<<endl;
    cout<<"6. buscar numero"<<endl;
    cout<<"7. orden de la pila"<<endl;
    cout<<"8. apilar dos pilas"<<endl;
    cout<<"9. pilas iguales"<<endl;
    cout<<"10 mostras ambas pilas"<<endl;
    cout<<"11 eliminar dato "<<endl;
    cout<<"12 agregar dato en pos  "<<endl;
    cout<<"\n ingrese opcion: ";
    
}    

int main(){

    ptrPila p = NULL;
    ptrPila p2 = NULL;
    int dato;
    int op;
    int x;
    system("color 0b");
    do{
        menu(); cin>>op;
        switch(op){
            case 1: 
              cout<<"numero a pila "; cin>>dato;
              push(p,dato);
              cout<<"\n\n\tnumero "<< dato<<" apilado \n\n";
              break;

            case 2:
              x = pop(p);
              cout<<"\n\n\tnumero "<< x <<" desapilado \n\n";
              break;

            case 3:
              cout<<"\n\n\t mostrando pila \n\n";
              if(p!= NULL ){
                mostrarPila(p);
              }else{
                cout<<"\n\n\t pila vacia "<<endl;
              }
              break;

            case 4:
              destruirPila(p);
              cout<<"\n\n\t\t pila eliminada \n\n";
              break;
              
            case 5:
              cout<<"\n\n\t\t pila invertida \n\n";
              invertirpila(p);
              break;
              
            case 6:
              cout<<"\n\n\t\t buscar numero \n\n";
              buscarNum(p);
			  break;
            	
            case 7:
            	cout<<"\n\n\t\t orden de la pila \n\n";
            	ordenPila(p);
            	break;
            	
            case 8:
            	cout<<"\n\n\t\t ingresar pilas \n\n";
                pushDosPilas(p,p2);
            	break;
            	
            case 9:
                iguales(p,p2);
            	break;
            
            case 10:
            	cout<<"\n\n\t mostrando pilas \n\n";
              if(p!= NULL && p2!= NULL){
                mostrarDosPilas(p, p2);
              }else{
                cout<<"\n\n\t pilas vacias "<<endl;
              }
            	break;
            	
            case 11:
            	cout<<"\n\n\t sacar dato de la pila \n\n";
				sacarDato(p,p2);
        
            case 12:
            	cout<<"\n\n\t ingresar dato de la pila \n\n";
				sacarDato(p,p2); 

        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }while(op!=13);

    return 0;
}
