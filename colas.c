// colas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* sgte;
}nodo;

typedef nodo* cola;
nodo* atras; 


void insertar(cola* frente, int valor){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->dato = valor; 
	nuevo->sgte = NULL; 
	if (nuevo == NULL){
		printf("No se pudo alocar la memoria\n"); 
		exit(1); 
	}
	if (atras == NULL){
		*frente = nuevo; 
		atras = nuevo; 
	} else{
		atras->sgte = nuevo; 
		atras = nuevo; 
	}
}

void sacar(cola* frente){
	if (*frente == NULL){
		printf("No se puede sacar de una cola vacia\n");
		exit(1); 
	}
	nodo* temp = *frente; 
	*frente = (*frente)->sgte; 
	if (*frente == NULL){
		atras = NULL; 
	}
	free(temp); 
}

void mostrar(cola frente){
	while (frente != NULL){
		printf("%d--->", frente->dato);
		frente = frente->sgte; 
	}
	printf("NULL\n"); 
}

int main(){
//prueba
	cola c;
	int i = 0;
	for (i = 0; i < 10; i++){
		insertar(&c, i); 
	}
	printf("Valores iniciales\n"); 
	mostrar(c); 
	printf("Sacando de la cola○\n\n"); 
	for (i = 0; i < 10; i++){
		
			sacar(&c); 
			mostrar(c); 
			printf("\n\n"); 
	}
	return 0;
}