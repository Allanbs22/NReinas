#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//valida si hay 2 reinas que pueden chocar entre sí
bool validar(int pos[],int tamano,int i,int valor){
	for(int k=0;k<tamano;k++){
		if(pos[k]!=-1 && k<i){
			if(pos[k]+i-k==valor || pos[k]-(i-k)==valor || pos[k]==valor)
				return false;
		}
	}
	return true;
}

//recibe el tamaño del tablero a generar
void reinas(int cantidad){
	//genera un tablero en forma de lista (una reina por columna)
	int posiciones[cantidad];
	bool fail = true;
	//inicializa las posiciones en -1
	for(int i=0;i<cantidad;i++)
		posiciones[i]=-1;
	//itera por el tablero
	for(int i=0;i<cantidad;i++){
		for(int j=0;j<cantidad;j++){
			if(j<=posiciones[i])
				j=posiciones[i]+1;
			posiciones[i]=j;
			if(j<cantidad && validar(posiciones,cantidad,i,j)){
				fail = false;
				j=cantidad;
			}
			else if(j>=cantidad-1){
				fail = true;
				posiciones[i]=-1;
			}
		}
		if(fail){
			i-=2;
		}
	}
	for(int i=0;i<cantidad;i++)
		cout<<posiciones[i]<<endl;
}

//prueba de main con 40 reinas
int main(){
	reinas(40);
	return 0;
}