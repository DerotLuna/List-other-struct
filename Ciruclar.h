# List-other-struct
#pragma once
struct listaC
{
	int valor;
	listaC *prox;
};

bool vacioC(listaC *q)
{
	return (!(q));
}

void insertarC(listaC **q, int x)
{
	listaC *t = (*q);
	
	if (vacioC(*q))
	{
		listaC *aux = new listaC;
		aux->valor = x;
		aux->prox = aux;
		(*q) = aux;
	}

	else
	{
		while ((t->prox->valor != (*q)->valor))
			t = t->prox;
		listaC *aux = new listaC;
		aux->valor = x;
		t->prox = aux;
		aux->prox = (*q);
	}
}

void eliminarC(listaC **q, int x) 
{
	listaC *t = (*q);

	while ((t->prox->valor != (*q)->valor))
		t = t->prox;

	if ((*q)->valor == x) 
	{
		listaC *aux = (*q);
		(*q) = (*q)->prox;
		t->prox = (*q);
		delete aux;
	}

	else if (t->valor == x)
	{
		listaC *aux = (*q);
		while ((aux->prox->valor != t->valor))
			aux = aux->prox;
		aux->prox = (*q);
		delete t;
	}

	else
	{
		listaC *aux = (*q);
		while (1 == 1)
		{
			if (aux->prox->valor == x)
			{
				t = aux->prox;
				aux->prox = aux->prox->prox;
				delete t;
				break;
			}
			aux = aux->prox;
		}
	}
}

int buscar(listaC *q, int x)
{
	if (!(vacioC(q)))
	{
		listaC *aux = q;
		while (aux->prox)
		{
			if (aux->valor == x)
				return aux->valor;
			aux = aux->prox;
		}
	}
	return 0;
}
