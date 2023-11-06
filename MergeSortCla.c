#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge(int *v,int inicio,int meio, int fim,int tamanho){

  int *aux=malloc((tamanho)*sizeof(int));
  for(int i=inicio;i<=fim;i++)
  {
    aux[i]=v[i];
  }
  int i=inicio;
  int j=meio+1;
  int k=inicio;

  while(i<=meio && j<=fim)
  {
    if(aux[i]<=aux[j])
    {
      v[k] = aux[i];
      i++;
    }
    else
    {
      v[k]=aux[j];
      j++;
    }
    k++;
  }
  while(i<=meio)
  {
    v[k]=aux[i];
    i++;
    k++;
  }
  while(j<=fim)
  {
    v[k]=aux[j];
    j++;
    k++;
  }

  free(aux);

}

void mergesort(int *v,int inicio, int fim,int tamanho){

  if(inicio<fim)
  {
    int meio=(inicio+fim)/2;
    mergesort(v,inicio,meio,tamanho);
    mergesort(v,meio+1,fim,tamanho);
    merge(v,inicio,meio,fim,tamanho);

  }

}
int main(int argc, char **argv)
{
  int *v;
  int tamanho = 1000000;//Tamanho do vetor
  v=malloc((tamanho)*sizeof(int));

  clock_t inicio, fim;
  double tempo_execucao;

    // Marca o tempo de início
    inicio = clock();

  if(v==NULL)
  {
    printf("Não foi possivel alocar a memória!");
    exit(1);
  }

  // Abrir o arquivo de entrada
    FILE *arquivo;
    arquivo = fopen("a1000000.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        exit(1);
    }

    // Ler os valores do arquivo e armazenar no vetor
    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &v[i]);
    }

    // Fechar o arquivo
    fclose(arquivo);

  printf("Vetor lido do arquivo:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    mergesort(v, 0, tamanho - 1, tamanho);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    // Liberar a memória alocada
    free(v);
    fim = clock();

    // Calcula o tempo de execução em segundos
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %.6f segundos\n", tempo_execucao);


  return 0;
}