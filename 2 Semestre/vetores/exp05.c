#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	//Gerar numero aleatórios
	float numeros[10];
	//Pega o tempo atual
	srand(time(NULL));
	//Gera o numero a partir do tempo
	for(int i = 0; i < 10; i++){
	    float x = rand();
	    numeros[i] = x;
	}
	//mostrar os numeros gerados
	for(int i = 0; i < 10; i++){
		printf("%.2f\n", numeros[i]);
	}
	
	getch();
}
    