# List-other-struct
#pragma once
struct dobleC
{
	int valor;
	dobleC *prox; dobleC *prev;
};

bool vacioDC(dobleC *r)
{
	return (!(r));
}

int buscarDC(dobleC *r, int x)
{
	if (!(vacioDC(r)))
		if (r->valor == x)
			return x;
		else
		{
			dobleC *aux = r;
			while ((aux)->prox->valor != r->valor)
			{
				if (aux->prox->valor == x)
					return x;
				else
					aux = aux->prox;
			}
		}
	return 0;
}

void insertarDC(dobleC **r, int x) //problema con insertar.
{
	int re = buscarDC((*r), x);
	if (vacioDC(*r))
	{
		dobleC *t = new dobleC;
		t->valor = x;
		(*r) = t;
		(*r)->prev = (*r);
		(*r)->prox = (*r);
	}
	else if (re != x)
	{
		dobleC *t = new dobleC;
		t->valor = x;
		dobleC *aux = (*r);
		aux->prev = t;
		t->prox = aux;
		while (aux->prox->valor =! (*r)->valor)
			aux = aux->prox;
		t->prev = aux;
		aux->prox = t;
	}
}

void eliminarDC(dobleC **r, int x)
{
	bool afir = false;
	dobleC *t = (*r);
	while ((*r)->prox->valor != t->valor)
		(*r) = (*r)->prox;

	if ((*r)->valor == x)
	{
		dobleC *aux = (*r);
		(*r)->prev->prox = t;
		(*r) = (*r)->prev;
		t->prev = (*r);
		delete aux;
		afir = true;
		t = (*r);
	}

	int num = t->valor;

	while ((*r)->prev->valor != num)
		(*r) = (*r)->prev;

	if ((*r)->valor == x)
	{
		dobleC *aux = (*r);
		(*r)->prox->prev = t;
		(*r) = (*r)->prox;
		t->prox = (*r);
		delete aux;
	}

	else if (!afir)
	{
		dobleC *aux = (*r);
		while (1 == 1)
		{
			aux = aux->prox;
			if (aux->valor == x)
			{
				aux->prev->prox = aux->prox;
				aux->prox->prev = aux->prev;
				delete aux;
				break;
			}
		}
	}
}
