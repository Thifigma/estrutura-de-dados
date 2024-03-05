#include <stdlib.h>
#include "libpilha.h"

pilha_t *pilha_cria ()
{
	pilha_t *p;

	if (!(p = malloc (sizeof(pilha_t))))
        	return NULL;
    
    	p->topo = NULL;
    	p->tamanho = 0;

	return p;
}

int pilha_tamanho (pilha_t *pilha)
{
	return pilha->tamanho;
}

bool pilha_vazia (pilha_t *p)
{
	if (!(p->topo) && (pilha_tamanho(p) == 0))
		return true;

	return false;
}

int pilha_topo (pilha_t *pilha, int *dado)
{
	if (pilha_vazia(pilha))
		return 0;
    
	*dado = pilha->topo->dado;

	return 1;
}

int push (pilha_t *pilha, int dado)
{
	nodo_t *aux;
    
   	if (!(aux = malloc(sizeof(nodo_t))))
    		return 0;
    
	/* Cria um novo item. */
	aux->dado = dado;

	/* Garante que o novo dado estará sempre apontando para o topo, 
	* ou seja, será sempre o topo. */
	aux->prox = pilha->topo;

	/*Primeiro item a ser incluso na pilha, ou seja, o item 0. */
	if (pilha_vazia(pilha))
    		pilha->topo = aux;

	/* Empilhamento*/
    	pilha->topo = aux;
	pilha->tamanho++;

	return 1;
}

int pop (pilha_t *pilha, int *dado)
{
	nodo_t *aux;

	if (pilha_vazia(pilha))
    		return 0;

    	*dado = pilha->topo->dado;
    
    	/* Salva o topo anterior, libera topo atual, e define o novo topo. */
   	aux = pilha->topo->prox;
   	free(pilha->topo);
   	pilha->topo = aux;
	pilha->tamanho--;

   	return 1;
}

void pilha_destroi (pilha_t **pilha)
{
	nodo_t *aux;

	/* laco inicia com o topo atualizado*/
	while ((*pilha)->topo ){
       		aux = (*pilha)->topo; /*Guarda o topo atual*/
       		(*pilha)->topo = (*pilha)->topo->prox; /*atualiza o topo*/
       		free (aux);
       		(*pilha)->tamanho--;
	}
		
	free ((*pilha));
	(*pilha) = NULL;
}	
