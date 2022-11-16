#include<stdio.h>
#include<stdlib.h>
typedef struct nodo{
	int dato; 
	struct nodo* sgt; 
}nodo;

typedef nodo* pila; 
int flag = 0; 

void insertar(pila* raiz, int valor){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo)); 
	if (nuevo != NULL){
		nuevo->dato = valor;
		if (flag == 0){
			nuevo->sgt = NULL; 
			*raiz = nuevo;
			flag = 1; 
			return; 
		}
		nuevo->sgt = *raiz;
		*raiz = nuevo; 
		return; 
	}
	printf("No hay suficiente memoria para alocar el nuevo puntero; ERROR\n"); 
}

void sacar(pila* raiz){
	if (*raiz != NULL){
		nodo* temp = *raiz; 
		*raiz = (*raiz)->sgt; 
		free(temp); //liberamos la memoria.
		return; 
	}else{/*seccion no testeado, borrar en caso de fallo:examen*/
		flag=0;
	}
	printf("No se pudo extrear el valor de una pila vacia...\n"); 
}

void mostrar(pila raiz){
	while (raiz != NULL){
		printf("%d-->", raiz->dato); 
		raiz = raiz->sgt; 
	}
	printf("NULL\n"); 
}


int main(){

	//prueba 
	pila p; 
	int i; 
	for (i = 0; i < 10; i++){
		insertar(&p, i); 
	}
	printf("datos: "); 
	printf("\n"); 
	mostrar(p); 
	printf("eliminando...\n"); 
	for (i = 0; i < 10; i++){
		sacar(&p); 
		mostrar(p); 
	}
	

	return 0; 
}

