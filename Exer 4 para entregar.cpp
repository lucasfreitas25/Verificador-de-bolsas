#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Registro

typedef struct TDisciplina{
    int semest;
    char displi[50];
    float nota;
    int carga;
    char displiRepro[100];
} TDisciplina;
typedef struct Taluno{
	char nome[40];
	int rga;
	float CRE;
	TDisciplina v[100];
} Taluno; 

//Programa
int main(int argc, char const *argv[])
{
	//QUANTIDADE DE CANDIDATOS
	int cand;
	printf("Quantidade de candidatos a bolsa: ");
	scanf(" %d", &cand);
	
	//VARIAVEIS LOCAIS
	char resp;
	int i,y,x,z,posicaoCRE,posicaoR,menorR,teste,r;
	int ultimo[100];
	float maiorCRE,somaden,somanum;
	int cont[100];
	int cont2[100];
	Taluno listaPessoas[cand];
	
	//LEITURA DOS DADOS DOS CANDIDATOS
	printf("|	CANDIDATOS A BOLSA DO PROFESSOR		|\n");
	for(i = 0;i < cand;i++)
	{
		resp = 'S';
		r = 0;
		z = 0;
		somaden = 0;
		somanum = 0;
		x = 0;
		teste = 0;
		printf("Nome da pessoa: ");
        scanf(" %[^\n]s", listaPessoas[i].nome);
        printf("RGA da pessoa: ");
        scanf(" %d", &listaPessoas[i].rga);
        printf("AVISO: SO SERA ACEITO NO MAXIMO 100 DISCIPLINAS E DE ORDEM CRESCENTE\n");
        while(resp == 'S')
        {
        	printf("Semestre da materia: ");
       		scanf(" %d", &listaPessoas[i].v[x].semest);
        	printf("Disciplina: ");
        	scanf(" %[^\n]s", listaPessoas[i].v[x].displi);
       		printf("Entre com a nota da materia: ");
        	scanf(" %f", &listaPessoas[i].v[x].nota);
        	if (listaPessoas[i].v[x].nota < 5)
        	{
        		z++;
        		cont[i] = z;
			}
			else
			{
				cont[i] = z;
			}
			if(teste <= listaPessoas[i].v[x].semest)
       		{
       		teste = listaPessoas[i].v[x].semest;	
       		ultimo[i] = teste;
			  if(listaPessoas[i].v[x].nota < 5)
			  {
			  	strcpy(listaPessoas[i].v[x].displiRepro, " ");
        		strcat(listaPessoas[i].v[x].displiRepro,listaPessoas[i].v[x].displi);
        		r++;
			  }	
			}
			cont2[i] = r;
        	printf("Digite a carga horaria da materia: ");
        	scanf(" %d", &listaPessoas[i].v[x].carga);
        	somaden = somaden + listaPessoas[i].v[x].carga;
			somanum = somanum + (listaPessoas[i].v[x].nota*listaPessoas[i].v[x].carga);
			listaPessoas[i].CRE = somanum/somaden;	
			printf("Deseja acrescentar mais[S/N]: ");
        	scanf(" %c", &resp);
        	x++;
		}
	
		printf(" \n");
	}
	
	//COMPARADOR DE CRE
	maiorCRE = 0;
	if(cand > 1)
	{
		for(i = 0; i < cand;i++)
		{
			for(y = 0; y < cand;y++)
			{
				if(listaPessoas[i].CRE > listaPessoas[y].CRE)
				{
					maiorCRE = listaPessoas[i].CRE;
					posicaoCRE = i;
				}
			}
		}
	}
	else
	{
		maiorCRE = listaPessoas[0].CRE;
		posicaoCRE = 0;
	}
	
	//COMPARADOR DE REPROVACAO
	if(cand > 1)
	{
		for(i = 0; i < cand;i++)
		{
			for(y = 0; y < cand;y++)
			{
				if(cont[i] < cont[y])
				{
					menorR = cont[i];
					posicaoR = i;
				}
			}
		}
	}
	else
	{
		menorR = cont[0];
		posicaoR = 0;
	}
	
	//LER OS VALORES PEDIDOS
	for(i = 0;i < cand;i++)
	{
		
		printf("O nome do aluno: %s\n", listaPessoas[i].nome);
		printf("RGA: %d\n", listaPessoas[i].rga);
		printf("O CRE do aluno em questao: %.2f\n", listaPessoas[i].CRE);
		printf("O numero de reprovacoes do alunos em questao: %d\n", cont[i]);
		for(x = 0; x < cont2[i]; x++ )
		{
			if(ultimo[i] = x)
			{
			printf("A materia reprovadas: %s\n", listaPessoas[i].v[x].displiRepro);
			}
		}
		printf("O semestre atual do aluno em questao: %d\n", ultimo[i]);
		printf(" \n");
		
	}
	//Mostrar o Maior CRE e Menor reprovaçao
	printf("A posicao do aluno com maior CRE e seu CRE: %d  %.2f \n", posicaoCRE, maiorCRE);
	printf("A posicao do aluno com menor reprovacao e sua quantidade: %d  %d \n", posicaoR, menorR);
}
