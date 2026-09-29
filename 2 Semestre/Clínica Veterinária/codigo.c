#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 100
//Estrutura dos animais 
struct Animal{
int id;
char nome[50];
char especie[30];
char tutor[50];
int idade;
char vacina[50];
};
//Vetor de animais 
struct Animal animais[MAX];

//Controle de qualidade 
int total = 0;

//Função cadastrar
void cadastrarAnimal() {
	if(total >= MAX){
		printf("\nLimite de cadastro atingido!\n");
		return;
	}
	printf("\n--- CADASTRO DE ANIMAL ---\n");
	animais[total].id = total + 1;
	
	printf("Nome do animal: ");
	scanf(" %[^\n]", animais[total].nome);
	
	printf("Especie: ");
	scanf(" %[^\n]", animais[total].especie);
	
	printf("Nome do tutor: ");
	scanf(" %[^\n]", animais[total].tutor);
	
	printf("Idade: ");
	scanf(" %d", &animais[total].idade);
	
	printf("Ultima vacina: ");
	scanf(" %[^\n]", animais[total].vacina);
	
	total++;
	printf("\nAnimal cadastrado com sucesso!\n");
}
//Função consultar
void consultarAnimais() {
	if(total == 0) {
		printf("\nNenhum animal cadastrado.\n");
	}
	printf("\n--- ANIMAIS CADASTRADOS ---\n");
	for(int i = 0;  i <total; i++) {
		printf("\nID: %d\n", animais[i].id);
		printf("Nome: %s\n", animais[i].nome);
		printf("Especie: %s\n", animais[i].especie);
		printf("Tutor: %s\n", animais[i].tutor);
		printf("Idade: %d\n", animais[i].idade);
		printf("Vacina: %s\n", animais[i].vacina);
	}
}
// Função alterar
void alterarAnimal() {
	int id;
	int encontrado = 0;
	
	printf("\nDigite o ID do animal: ");
	scanf("%d", &id);
	for(int i = 0; i < total; i++) {
		if(animais[i].id == id) {
			printf("\n--- ALTERAR DADOS ---\n");
			
			printf("Novo nome: ");
			scanf(" %[^\n]", animais[i].nome);
			
			printf("Nova especie: ");
			scanf(" %[^\n]", animais[i].especie);
			
			printf("Novo tutor: ");
			scanf(" %[^\n]", animais[i].tutor);
			
			printf("Nova idade: ");
			scanf("%d", &animais[i].idade);
			
			printf("Nova vacina: ");
			scanf(" %[^\n]", animais[i].vacina);
			
			printf("\nDados alterados com secesso!\n");
			encontrado = 1;
		}
	}
	if(encontrado == 0) {
    printf("\nAnimal nao encontrado.\n");
	}
}
// Função excluir
void excluirAnimal() {
	int id;
	int encontrado = 0;
	
	printf("\nDigite o ID do animal para excluir: ");
	scanf("%d", &id);
	for(int i = 0; i < total; i++) {
		if(animais[i].id == id) {
			
			for(int j = i; j < total - 1; j++) {
				animais[j] = animais[j + 1];
			}
			total--;
			printf("\nAnimal excluido com sucesso!\n");
			
			encontrado = 1;
			break;
		}
	}
	if(encontrado == 0) {
        printf("\nAnimal nao encontrado.\n");
    }
}
	// Função principal
	int main() {
		SetConsoleOutputCP(65001);
		int opcao;
		do {
			printf("\n==============================");
			printf("\n CLINICA VETERINARIA VIDA ANIMAL");
			printf("\n==============================");
			printf("\n1 - Cadastrar Animal");
			printf("\n2 - Consultar Animais");
			printf("\n3 - Alterar Animal");
			printf("\n4 - Excluir Animal");
			printf("\n0 - Sair");
			printf("\nEscolha uma opcao: ");
			scanf("%d", &opcao);
			
			switch(opcao) {
				case 1: 
				cadastrarAnimal();
				break;
				
				case 2:
					consultarAnimais();
					break;
					
					case 3:
						alterarAnimal();
						break;
						
						case 4:
							excluirAnimal();
							break;
							
							case 0:
								printf("\nEncerrando sistema...\n");
								break;
								
								default:
									printf("\nOpcao invalida!\n");
			}
		} while(opcao != 0);
		return 0;
	}

