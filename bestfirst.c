//#include <stdio.h>
//#include <stdlib.h>
#include "queue.c"

int** criarGrafo();
void viewGrafo(int **m);
void bestfirst(int **m, int vertices, int arestas, int ini, int destino);
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
        bestfirst(m, linhas, colunas, origem, destino);
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

void bestfirst(int **m, int vertices, int arestas, int ini, int destino){
	Dado d;
	node *tmp;
  	fila *FILA;
  	FILA = create();
    int i, j, k, cont, NV, ind, *visitado, vert, *vetor;
    
    cont = 0;
	NV = vertices;
    visitado = (int*) malloc(NV * sizeof(int));

    
    for(i=0; i < NV; i++){
        visitado[i] = 0;
    }
    
    
    while(cont<10){
        if(FILA->prox == NULL){
        	for(i=ini, j=0; j<vertices; j++){
        		if(m[i][j] != 0){
        			d.i = i;
        			d.j = j;
        			d.numero = m[i][j];
        			//Inserir nodo na Fila
        			insertNode(FILA, d);
				}
			}
			visitado[ini] = 1; 
		}else {
			tmp = remover(FILA);
			if(tmp->dado.i != destino){
					visitado[tmp->dado.i] = 1; 
				}
			if(tmp->dado.j == destino){
				printf("\nCusto da Melhor Escolha: %d", tmp->dado.numero);
				return;
			}
			printf("Origem = %d Destino = %d Peso = %d\n", tmp->dado.i, tmp->dado.j, tmp->dado.numero);
			if(tmp != NULL){ 
				for(i=tmp->dado.j, j=0; j<vertices; j++){
        			if((m[i][j] != 0) && (visitado[j] == 0)){
        				d.i = tmp->dado.j;
        				d.j = j;
        				d.numero = m[i][j] + tmp->dado.numero;
        				//Inserir nodo na Fila
        				insertNode(FILA, d);
					}
				}
			}
			
		}
		
		/*for(k=0; k<10; k++){
			if(visitado[k] == 1){
				cont++;
			}
		}*/
		
		ordenarFila(FILA);

    }
    
    node *pnode = FILA->prox;
    while(pnode->prox != NULL){
    	printf("%d ", pnode->dado.numero);
    	pnode = pnode->prox;
	}
}

void menu(){
  printf ("###############################################\n");
  printf ("========== BUSCA PELO MELHOR ESCOLHA ==========\n");
  printf ("###############################################\n\n");

  printf ("============ MENU ==========\n");
  printf ("1 - Matriz do Grafo\n");
  printf ("2 - Best First\n");
  printf ("\n");
  printf ("0 - Sair\n");
  printf ("Informe a opcao desejada: ");
}

