#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ALUNOS 50

typedef struct {
	char nome[50];
	float notas[4];
	int ativo;
} Aluno;
Aluno alunos[MAX_ALUNOS];

void menu();
void cadastrar();
void remover();
void reprovados();
void aprovados();
void pesquisar();
void listar();

int main(int argc, char const *argv[]) {
	menu();
	return 0;
}

void menu() {
	int op;
	do{
		system("cls");
		printf("\n1 - Cadastrar aluno\n2 - Pesquisar aluno\n3 - Alunos aprovados\n4 - Alunos reprovados\n5 - Listar alunos\n6 - Remover aluno\n0 - Sair\n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				cadastrar();
				break;
			case 2:
				pesquisar();
				break;
			case 3:
				aprovados();
				break;
			case 4:
				reprovados();
				break;
			case 5:
				listar();
				break;
			case 6:
				remover();
				break;		
			default:
				
				break;			
		}
		getchar();
	}while(op!=0);
}

void cadastrar() {
	char nome[50];
	float notas[4];
	int op;
	do{
		system("cls");
		printf("\nNome: ");
		fgets(nome, sizeof(nome),stdin);
		printf("\n1 Bimestre: ");
		scanf("%f", &notas[0]);
		printf("\n2 Bimestre: ");
		scanf("%f", &notas[1]);
		printf("\n3 Bimestre: ");
		scanf("%f", &notas[2]);
		printf("\n4 Bimestre: ");
		scanf("%f", &notas[3]);
		for(int i = 0; i<MAX_ALUNOS; i++) {
			if(alunos[i].ativo==0) {
				alunos[i].notas[0] = notas[0];
				alunos[i].notas[1] = notas[1];
				alunos[i].notas[2] = notas[2];
				alunos[i].notas[3] = notas[3];
				strcpy(alunos[i].nome, nome);
				alunos[i].ativo=1;
				break;
			}
		}
		
		
		printf("\n1 - Novo cadastro\n0 - Sair\n");
		scanf("%d", &op);
		getchar();
	}while(op!=0);
}

void remover() {
	int matricula;
	listar();
	printf("\nDigite a matricula do aluno a ser removido: \n");
	scanf("%d", &matricula);
	--matricula;
	alunos[matricula].ativo=0;
	printf("\nAluno removido com sucesso!");
	getchar();
}

void reprovados() {
	system("cls");
	float media;
	printf("\nLISTA DE ALUNOS REPROVADOS\n");
	for (int i = 0; i<MAX_ALUNOS; i++) {
		if(alunos[i].ativo==1){
			media = 0;
			media = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3];
			media = media/4;
			if(media<6.0) {
				printf("Matricula: %d\n", i+1);
				printf("Nome: %s\n", alunos[i].nome);
				printf("1 Bimestre: %0.2f\n", alunos[i].notas[0]);
				printf("2 Bimestre: %0.2f\n", alunos[i].notas[1]);
				printf("3 Bimestre: %0.2f\n", alunos[i].notas[2]);
				printf("4 Bimestre: %0.2f\n", alunos[i].notas[3]);
				printf("\n---------------\n");
			}
		}
	}
}

void pesquisar() {
	system("cls");
	char nome[50];
	int op;
	do{
	printf("\nDigite o nome do aluno: ");
	fgets(nome, sizeof(nome),stdin);
	for(int i = 0; i<MAX_ALUNOS; i++) {
		if(strstr(alunos[i].nome, nome)!=NULL){
			printf("Matricula: %d\n", i+1);
			printf("Nome: %s\n", alunos[i].nome);
			printf("1 Bimestre: %0.2f\n", alunos[i].notas[0]);
			printf("2 Bimestre: %0.2f\n", alunos[i].notas[1]);
			printf("3 Bimestre: %0.2f\n", alunos[i].notas[2]);
			printf("4 Bimestre: %0.2f\n", alunos[i].notas[3]);
			printf("\n---------------\n");
		}
	}
	printf("\n1 - Nova pesquisa\n0 - Sair\n");
	scanf("%d", &op);
	getchar();
	}while(op!=0);
	
}

void listar() {
	system("cls");
	printf("\nLISTA DE ALUNOS\n");
	for (int i = 0; i<MAX_ALUNOS; i++) {
		if(alunos[i].ativo==1){
			printf("Matricula: %d\n", i+1);
			printf("Nome: %s\n", alunos[i].nome);
			printf("1 Bimestre: %0.2f\n", alunos[i].notas[0]);
			printf("2 Bimestre: %0.2f\n", alunos[i].notas[1]);
			printf("3 Bimestre: %0.2f\n", alunos[i].notas[2]);
			printf("4 Bimestre: %0.2f\n", alunos[i].notas[3]);
			printf("\n---------------\n");
		}
	}
}

void aprovados() {
	system("cls");
	float media;
	printf("\nLISTA DE ALUNOS APROVADOS\n");
	for (int i = 0; i<MAX_ALUNOS; i++) {
		if(alunos[i].ativo==1){
			media = 0;
			media = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3];
			media = media/4;
			if(media>6.0) {
				printf("Matricula: %d\n", i+1);
				printf("Nome: %s\n", alunos[i].nome);
				printf("1 Bimestre: %0.2f\n", alunos[i].notas[0]);
				printf("2 Bimestre: %0.2f\n", alunos[i].notas[1]);
				printf("3 Bimestre: %0.2f\n", alunos[i].notas[2]);
				printf("4 Bimestre: %0.2f\n", alunos[i].notas[3]);
				printf("\n---------------\n");
			}
		}
	}
}

