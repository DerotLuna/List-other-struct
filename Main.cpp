# List-other-struct
#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"
#include "DoblementeEnlazada.h"
#include "DoblementeEnlazadaCircular.h"
#include "ConSaltosOrdenada.h"


void mostrarC(listaC *p) /*Muestra la lista principal completa.*/
{
	listaC *aux = p;
	int n = aux->valor;
	while (aux)
	{
		printf(" %i ->", aux->valor);
		aux = aux->prox;
		if (aux->valor == n)
			break;
	}
	printf(" NULL");
}

void mostrarD(doble *p) /*Muestra la lista principal completa.*/
{
	doble *aux = p;
	while (aux)
	{
		printf(" %i ->", aux->valor);
		aux = aux->prox;
	}
	printf(" NULL");
}

void mostrarDC(dobleC *r) /*Muestra la lista principal completa.*/
{
	if (!vacioDC(r))
	{
		printf(" %i ->", r->valor);
		dobleC *aux = r;
		while (aux->prox->valor != r->valor)
		{
			printf(" %i ->", aux->prox->valor);
			aux = aux->prox;
		}
	}
	printf(" NULL");
}


void main()
{
	int op = -1, n = 0;
	listaC *q = NULL;
	doble *p = NULL;
	dobleC *r = NULL;

	while (op != 0) {
		system("cls");
		printf("\n\n                              Menu principal! \n\n\n");
		printf("\n 1. Insertar en lista circular .");
		printf("\n 2. Insertar en la lista doblemente enlazada."); 
		printf("\n 3. Insertar en la lista doblemente enlazada circular.");
		printf("\n 4. Mostrar lista circular.");
		printf("\n 5. Mostrar lista doblemente enlazada."); 
		printf("\n 6. Mostrar lista doblemente enlazada circular.");
		printf("\n 7. Eliminar un elemento (x) de la lista circular.");
		printf("\n 8. Eliminar un elemento (x) de la lista doblemente enlazada."); 
		printf("\n 9. Eliminar un elemento (x) de la lista doblemente enlazada circular."); 
		printf("\n\n 0. Salir. \n\n");
		printf(" Indique opcion : ");
		op = 0;
		scanf("%i", &op);
		system("cls");
		printf("\n\n");
		switch (op)
		{
		case 1: printf("\n\n Indique el valor a ingresar : ");
			scanf("%i", &n);
			insertarC(&q, n);
			break;

		 case 2: printf("\n\n Numero a insertar en la lista :");
			scanf("%i", &n);
			insertarD(&p, n);
			break;

		 case 3: printf("\n\n Numero a insertar en la lista :");
			 scanf("%i", &n);
			 insertarDC(&r, n);
			 break;

		case 4: printf("\n\n Lista Circular \n\n ");
			mostrarC(q);
			break;

		case 5: printf("\n\n Lista Doblemente Enlazada \n\n ");
			mostrarD(p);
			break;

		case 6: printf("\n\n Lista Doblemente Enlazada Circular \n\n ");
			mostrarDC(r);
			break;

		case 7:
			printf("\n\n Numero a buscar para eliminar de la lista :");
			scanf("%i", &n);
			eliminarC(&q, n);
			break;

		case 8: printf("\n\n Numero a buscar para eliminar de la lista :");
			scanf("%i", &n);
			eliminarD(&p, n);
			break; 

		case 9: printf("\n\n Numero a buscar para eliminar de la lista :");
			scanf("%i", &n);
			eliminarDC(&r, n);
			break;
		}
		if (op)
		{
			printf("\n\n");
			system("pause");
			system("cls");
		}
	}
}
