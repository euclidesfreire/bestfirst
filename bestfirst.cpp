#include <stdio.h>
#include <stdlib.h>

int** criarGrafo();
void viewGrafo(int **m);
int procuraMenorDistancia(float *dist, int *visitado, int NV);
void dijkstra(int **m, int vertices, int arestas, int ini, int destino, int *ant, float *dist);
void sobre();
void menu();

void main() {
    int **m = criarGrafo();
    int op = -1, i, j, linhas, origem, destino, colunas, *ant, *pai;
    float *dist;
    FILE *arquivo = fopen("grafo.txt", "r");

    //PEGANDO OS VALORES DE LINHA E COLUNAS
    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        fscanf(arquivo, "%d %d\n", &linhas, &colunas);
	}

	fclose(arquivo);

   do {
    system("cls || clear");
    menu();
    scanf("%d",&op);

    switch (op) {
      case 1:
        viewGrafo(m);
        break;
      case 2:
        printf("\nDigite a origem: ");
        scanf("%d", &origem);
        printf("\nDigite a destino: ");
        scanf("%d", &destino);
        ant = (int *) malloc(linhas * sizeof(int));
        dist = (float *) malloc(linhas * sizeof(float));
        dijkstra(m, linhas, colunas, origem, destino, ant, dist);
        break;
      case 8:
        sobre();
        break;
      case 0:
        return;
    }

    printf("\n\nTECLE ENTER PARA VOLTAR ");
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}

int** criarGrafo(){
    int i, j, p, linhas, colunas;
    int **m;
    FILE *arquivo = fopen("grafo.txt", "r");

    //PEGANDO OS VALORES DE LINHA E COLUNAS
    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        fscanf(arquivo, "%d %d\n", &linhas, &colunas);
	}
	//ALOCANDO MEMORIA PARA A MATRIZ
    m = (int **) malloc(linhas * sizeof(int *));

    if(m != NULL){
        for(i = 0; i < linhas; i++){
            m[i] = (int *) malloc(colunas * sizeof(int));
            for(j=0; j<colunas; j++){
                m[i][j] = 0;
            }
        }
    }

    while((fscanf(arquivo, "%d %d %d\n", &i, &j, &p))!= EOF ){
            m[i][j] = p;
    }

    fclose(arquivo);
    return m;
}

void viewGrafo(int **m){
    int i, j, linhas, colunas;
    FILE *arquivo = fopen("grafo.txt", "r");

    //PEGANDO OS VALORES DE LINHA E COLUNAS
    if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        fscanf(arquivo, "%d %d\n", &linhas, &colunas);
        printf("\n");
        for(i = 0; i < linhas; i++){
            for(j = 0; j < colunas; j++){
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
	}
	fclose(arquivo);
}

void menu(){
  printf ("############################\n");
  printf ("========== GRAFOS ==========\n");
  printf ("############################\n\n");

  printf ("============ MENU ==========\n");
  printf ("1 - Matriz do Grafo\n");
  printf ("2 - Dijkstra\n");
  printf ("3 - Prim\n");
  printf ("4 - Kruskal\n");
  printf ("5 - Floyd-Warshall \n");
  printf ("\n");
  printf ("8 - Sobre \n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

void sobre(){
  system("cls || clear");

  printf ("#################################################\n");
  printf ("=================================================\n\n");
  printf ("DESENVOLVEDOR:  Euclides Freire da Silva Abreu\n");
  printf ("E-MAIL:         euclidesfreiresa@gmail.com\n");
  printf ("CURSO:          Engenharia de Computacao - UEMA\n");
  printf ("DISCIPLINA:     Estrutura de Dados Avancada\n");
  printf ("PROFESSOR:      Daniel de Sousa Moraes\n");
  printf ("DATA:           01/07/2017\n\n");
  printf ("O QUE E?: \n");
  printf (" A partir de um arquivo.txt pegar as dimensoes da\n");
  printf ("matriz gerar o grafo e mostrar o menor caminho de\n");
  printf ("acordo com a escolha do agoritmo heuristico.\n");
  printf ("\n=================================================\n");
  printf ("#################################################\n");
}
