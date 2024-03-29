/*
 * TAD fila
 * Versao com lista ligada com nodo cabeca
 * Usa apontadores para cabeca e cauda.
*/

#ifndef _LIBfila_t_H
#define _LIBfila_t_H

#include <stdbool.h>

typedef struct nodo {
    int dado;
    struct nodo *prox;
} nodo_t;

typedef struct fila {
    nodo_t *cabeca;
    nodo_t *cauda;
    int tamanho;
} fila_t;

/* 
 * Cria e retorna uma nova fila.
 * Retorna NULL em caso de erro de alocação.
*/
fila_t *fila_cria ();

/* Retorna o numero de elementos da fila, que pode ser 0. */
int fila_tamanho (fila_t *fila);

/* Retorna verdadeiro se fila vazia, falso em caso contrario. */ 
bool fila_vazia (fila_t *fila);

/* 
 * Insere dado no final da fila (politica FIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int enqueue (fila_t *fila, int dado);

/* 
 * Remove o elemento do inicio da fila (politica FIFO) e o retorna
 * no parametro dado. Nao confundir com o retorno da funcao.
 * A funcao retorna 1 em caso de sucesso e 0 no caso da fila estar vazia.
*/
int dequeue (fila_t *fila, int *dado);

/* Desaloca toda memoria da fila e faz fila receber NULL. */
void fila_destroi (fila_t **fila);

#endif
