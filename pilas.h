#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
    
};

typedef nodo *ptrPila; 

void push(ptrPila &p, int valor){

    ptrPila aux;
    aux = new(struct nodo);
    aux -> nro = valor;
    aux ->sgte = p;
    p = aux;
}

int pop ( ptrPila &p){

    int num;
    ptrPila aux;

    aux = p;
    num = aux->nro;
    p = aux -> sgte;
    delete(aux);
    return num;

    
}

void mostrarPila(ptrPila p){
    ptrPila aux;
    aux = p;

    while(aux != NULL){
        cout<<"\t"<<aux->nro<<endl;
        aux = aux->sgte;
    }
}

void destruirPila(ptrPila &p){
    ptrPila aux;

    while(p != NULL){
        aux = p;
        p = aux ->sgte;
        delete(aux);
    }
}

void invertirpila(ptrPila &p){
	
	ptrPila paux;
	paux = NULL;
	while(p != NULL){
		push(paux,pop(p));
	}
	p=paux;
	
	cout<<"\tpila invertida"<<endl;
	mostrarPila(p);
	
}

void buscarNum(ptrPila &p){
	
	int num,num2;
	
	cout<<"ingrese el numero que desea buscar: "; cin>>num;
	ptrPila aux;
	
	while(aux != NULL){
		
		aux = p;
		num2 = aux ->nro;
		if(num == num2){
			cout<<"el numero "<<num2<<" esta en la pila"<<endl;
		}
		p = aux->sgte;
	}
		
}

void ordenPila(ptrPila &p){
	bool creciente = false ;
	bool decreciente = false; 
	
	ptrPila aux = p;
	ptrPila aux2 = p->sgte ;

	
	while(aux2 != NULL){
		
		if(aux->nro < aux2->nro){
			creciente = true;
		}
		if(aux->nro > aux2->nro){
			decreciente = true;
		}
		aux = aux->sgte;
		aux2 = aux2->sgte;
	}
	
	if(creciente == true && decreciente == false){
		cout<<"la pila esta en forma creciente "<<endl;
	}else if(decreciente == true && creciente == false){
		cout<<"la pila esta en forma decreciente "<<endl;
	}else{
		cout<<"la pila esta desordenada "<<endl;
	}
}

void pushDosPilas(ptrPila &p, ptrPila &p2){ 
	int bandera = 0, num, con=0;
	
	
	ptrPila aux;
	ptrPila aux2;

	cout<<"para ingresar datos en la P1 oprimir #1, para P2 #2 y #3 para salir: "; cin>>bandera;
	do{
		if(bandera == 1){
			cout<<"numero a ingresar en la P1: "; cin>>num; 
			aux = new(struct nodo);
            aux -> nro = num;
            aux ->sgte = p;
            p = aux;
		}else if( bandera == 2){
			cout<<"numero a ingresar en la P2: "; cin>>num;
			aux2 = new(struct nodo);
            aux2 -> nro = num;
            aux2 ->sgte = p2;
            p2 = aux2;
		}
		cout<<"quiere ingresar mas datos en las pilas [1=P1,P2=2,salir=3]: "; cin>>bandera;
	}while(bandera != 3);
		
}

void iguales(ptrPila &p, ptrPila &p2){
	bool creciente = false ;
	bool decreciente = false; 
	bool creciente2 = false ;
	bool decreciente2 = false;
	
	ptrPila aux;
	ptrPila aux2;
	ptrPila faux;
	ptrPila faux2;
	
	aux = p;
	faux = p->sgte;
    aux2 = p2;
    faux2 = p2->sgte;
    
    while(faux != NULL){
		
		if(aux->nro < faux->nro){
			creciente = true;
		}
		if(aux->nro > faux->nro){
			decreciente = true;
		}
		if(aux2->nro < faux2->nro){
			creciente2 = true;
		}
		if(aux2->nro > faux2->nro){
			decreciente2 = true;
		}
		aux = aux->sgte;
		faux = faux->sgte;
		aux2 = aux2->sgte;
		faux2 = faux2->sgte;
	}
	
	if((creciente == true && decreciente == false) and (creciente2 == true && decreciente2 == false)){
		cout<<"la pila esta en forma creciente "<<endl;
	}else if((decreciente == true && creciente == false ) and (decreciente2 == true && creciente2 == false )){
		cout<<"la pila esta en forma decreciente "<<endl;
	}else{
		cout<<"la pila esta desordenada "<<endl;
	}
	
	
	int num2, num;
	bool igual = false;
	bool noIgual  = true;
	while(aux != NULL){
		aux2 = p2;
		aux = p;
		num = aux ->nro;
		num2 = aux2 ->nro;
		
		if(num == num2){
			igual = true;
			cout<<igual<<endl;
		}else{
			noIgual = false;
			cout<<noIgual<<endl;
		}
		
		p = aux -> sgte;
		p2 = aux2 ->sgte;
	}
	
}

mostrarDosPilas(ptrPila p, ptrPila p2){
	 ptrPila aux;
     aux = p;
     ptrPila aux2;
     aux2 = p2;

    while(aux != NULL){
        cout<<"\t"<<aux->nro<<" "<<aux2->nro<<endl;
        aux = aux->sgte; aux2 = aux2 = aux2->sgte;
    }
}



sacarDato(ptrPila &p, ptrPila &p2){
	ptrPila aux;
	int bandera = 0, num2,num,con = 1;
	aux = p;
	
	do{
		cout<<"ingrese el dato #"<<con<<" de la pila "; cin>>num;
		aux = new(struct nodo);
		aux -> nro = num;
        aux ->sgte = p;
        p = aux;
		cout<<"desea ingresar mas datos a la pila? si=1, no=2: "; cin>>bandera; 
		con++;
	}while(bandera != 2);
	
	
	
	 
	cout<<"que numero desea sacar de la pila?: "; cin>>num2;
	
	while(aux != NULL){
		num = aux->nro;
		if(num != num2){
				ptrPila aux2 = new(struct nodo);
		        aux2 -> nro = num;
                aux2 ->sgte = p2;
                p2 = aux2;
		}
		aux = aux->sgte;
	}
	mostrarPila(p);
	cout<<endl;
	mostrarPila(p2);
}




