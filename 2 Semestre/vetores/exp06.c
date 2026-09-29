#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	//Gerar 10 numero aleatórios inteiros de 0 a 10
	int numeros[10];
	//Pega o tempo atual
	srand(time(NULL));
	//Gera 10 o numero a partir do tempo
	for(int i = 0; i < 10; i++){
	   int x = rand() % 100;
	    numeros[i] = x;
	}
	//mostrar os numeros gerados
	for(int i = 0; i < 10; i++){
		printf("%d\n", numeros[i]);
	}
	
	getch();
}
    