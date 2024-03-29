
#include <stdlib.h>
#include "libfila.h"

fila_t *fila_cria()
{
	fila_t *fila;

    	/* Aloca um espaço em memoria do tamanho da estrutura fila_t. */
	if (!(fila = malloc(sizeof(fila_t))))
		return NULL;
	
	fila->cabeca = NULL;
	fila->cauda = NULL;

	fila->tamanho = 0;

	return fila;
}

int fila_tamanho(fila_t *fila)
{
	return fila->tamanho;
}

bool fila_vazia(fila_t *fila)
{
	if ( !(fila->cabeca) && (fila_tamanho(fila) == 0) )
		return true;
	return false;
}

int enqueue(fila_t *fila, int dado)
{
    /* Cria um nodo auxiliar. */
	nodo_t *aux;
    
	/* Aloca um espaço de memoria do tamanho do nodo_t. */
	if (!(aux = malloc(sizeof(nodo_t))))
        return 0;

    aux->dado = dado;
    aux->prox = NULL;

    /* Primeiro elemento da fila */
    if (fila_vazia(fila)){
        fila->cabeca = aux;
        fila->cauda = aux;
    }

    /* Torna o proximo elemento o ultimo da fila */
    fila->cauda->prox = aux;
    fila->cauda = fila->cauda->prox;
    fila->tamanho++;

    return 1;
}

int dequeue(fila_t *fila, int *dado)
{
	nodo_t *aux;

    if (fila_vazia(fila))
        return 0;

    *dado = fila->cabeca->dado;

    /* Remove o primeiro da fila e salva o anterior a ele */
    aux = fila->cabeca->prox;
    free(fila->cabeca);
    
    /* Torna o anterior o primeiro. */
    fila->cabeca = aux;
    fila->tamanho--;
    
    return 1;
}

void fila_destroi(fila_t **fila)
{
    nodo_t *aux;

    /* 
     * Anda na fila em direção a cauda e vai removendo ate ser null
    */
    while (!(fila_vazia((*fila)))){
        aux = (*fila)->cabeca;
        (*fila)->cabeca = (*fila)->cabeca->prox;
        (*fila)->tamanho--;
        free(aux);
    }

    free((*fila));
    (*fila) = NULL;
}
