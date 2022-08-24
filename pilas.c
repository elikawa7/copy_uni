#include<stdio.h>
#include<stdlib.h>
typedef struct nodo{
	int dato; 
	struct nodo* sgt; 
}nodo;

typedef nodo* pila; 


void insertar(pila* raiz, int valor){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo)); 
	if (nuevo != NULL){
		nuevo->dato = valor;
		nuevo->sgt = *raiz;
		*raiz = nuevo; 
		return; 
	}
	printf("No hay suficiente memoria para alocar el nuevo puntero; ERROR\n"); 
}

int sacar(pila* raiz){
	if (raiz != NULL){
		int result =(*raiz)->dato; 
		nodo* temp = *raiz; 
		*raiz = (*raiz)->sgt; 
		free(temp); //liberamos la memoria.
		return result; 
	}
	printf("No se pudo extrear el valor de una pila vacia...\n"); 
	return NULL; 
}

void mostrarPila(pila raiz){
	if (raiz == NULL){
		printf("NO se puede recorrer una pila vacia\n"); 
		return; 
	}
	while (raiz != NULL){
		printf("%d-->", raiz->dato); 
		raiz = raiz->sgt; 
	}
	printf("NULL\n"); 
}

int buscar(pila raiz, int valor){
	int buscado = -45; 
	if (raiz == NULL){
		printf("No se puede buscar en una pila vacia...\n"); 
		return buscado; 
	}
	while (raiz != NULL){
		if (raiz->dato == valor){
			buscado = valor;  
			break; 
		}
		raiz = raiz->sgt; 
	}
	return buscado; 
}

void escribirenArchivo(const char* nombre, pila p){

	FILE *arch = fopen(nombre, "w"); 
	if (arch == NULL){
		printf("No se pudo abrir el archivo para escribir en el... \n"); 
		return; 
	}
	if (p == NULL){
		printf("No se puede escribir una pila vacia en un archivo...\n"); 
		fclose(arch); 
		return; 
	}

	while (p != NULL){
		fprintf(arch, "%d\n", p->dato); 
		p = p->sgt; 
	}

	printf("Archivo escrito en archivo: %s", nombre); 
	fclose(arch); 
}

int main(){
	pila p; 

	insertar(&p, 1); 
	insertar(&p, 2); 
	insertar(&p, 3); 
	insertar(&p, 4);
	insertar(&p, 5);
	mostrarPila(p);
	int b = buscar(p, 3);
	printf("%d el valor buscado: ", b); 
	mostrarPila(p); 
	

	return(0); 
}

