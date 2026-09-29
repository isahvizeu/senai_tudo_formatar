#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	//Gerar 10 números aleatórios inteiros de 20 a 50
	int numeros[10];
	//Pega o temp atual
	srand(time(NULL));
	//Gera 10 números a partir do tempo
	for(int i = 0; i < 10; i++){
		int x = (rand() % 31)+20;
		numeros[i] = x;
	}
	//Mostrar os números gerados
	for(int i = 0; i < 10; i ++){
		printf("%d\n", numeros[i]);
	}
	
}
    