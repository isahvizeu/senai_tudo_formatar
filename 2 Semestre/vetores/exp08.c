#include<stdio.h>
void main(){
	char nomes[7][50] = {
		"Jacinto Pena",
		"Jacinto PaiXão",
		"Jacinto Amor",
		"Osmar Motta",
		"Osmar Educado",
		"Osmar Dito",
		"Osmar Amado",
        };
        for(int i = 0; i < 7; i++){
        	printf("%s\n", nomes[i]);
		}
		getch();
	}