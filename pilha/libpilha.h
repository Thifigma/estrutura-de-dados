/* TAD pilha. */

#ifndef _LIBpilha_t_H
#define _LIBpilha_t_H

#include <stdbool.h>

typedef struct nodo {
    int dado;
    struct nodo *prox;
} nodo_t;

typedef struct pilha {
    struct nodo *topo;
    int tamanho;
} pilha_t;

/* 
 * Cria e retorna uma nova pilha.
 * Retorna NULL em caso de erro de alocação.
*/
pilha_t *pilha_cria ();

/* Retorna o numero de elementos da pilha, que pode ser 0. */
int pilha_tamanho (pilha_t *pilha);

/* Retorna 1 se pilha vazia, 0 em caso contrario. */ 
bool pilha_vazia (pilha_t *pilha);

/* Similar ao pop, mas retorna o elemento dado sem remove-lo. */
int pilha_topo (pilha_t *pilha, int *dado); 

/* 
 * Insere dado na pilha (politica LIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int push (pilha_t *pilha, int dado);

/* 
 * Remove o topo (politica LIFO) e retorna o elemento 
 * no parametro dado. A funcao retorna 1 em caso de 
 * sucesso e 0 no caso da pilha estar vazia.
*/
int pop (pilha_t *pilha, int *dado);
 
 /* Desaloca toda memoria da pilha e faz pilha receber NULL. */
void pilha_destroi (pilha_t **pilha);


#endif
