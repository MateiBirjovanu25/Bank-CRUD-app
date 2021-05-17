#include <stdio.h>
#include<stdlib.h>
#include "tranzactie.h"
#include "repo.h"
#include "domain.h"



repo repoConstructor()
{
	repo repos;
	repos.v = (tranzactie*) malloc(sizeof(tranzactie));
	repos.n = 0;
	repos.cp = 1;
	return repos;
}

void resize(repo *repos)
{
	tranzactie* vNou = (tranzactie*) malloc( repos->cp * sizeof(tranzactie)*2);

	for (int i = 0;i < repos->n;i++)
		vNou[i] = repos->v[i];

	repos->cp = 2 * repos->cp;

	free(repos->v);

	repos->v = vNou;
}

void devide(repo* repos)
{
	tranzactie* vNou = (tranzactie*)malloc( repos->cp * sizeof(tranzactie) / 2);

	for (int i = 0;i < repos->n;i++)
		vNou[i] = repos->v[i];

	repos->cp = repos->cp /2 ;

	free(repos->v);

	repos->v = vNou;
}


void repoDestructor(repo repos)
{
	tranzactie tr;
	for (int i = 0;i < repos.n;i++)
	{
		tr = *(repos.v+i);
		free(tr.tip);
		free(tr.descriere);
	}
	free(repos.v);
}

int add(repo *repos, tranzactie tr)
{
	tranzactie k;
	for (int i = 0;i < repos->n;i++)
	{
		k = *(repos->v + i);
		if (getId(k) == getId(tr))
			return 2;
	}


	if (repos->n == repos->cp)
	{
		//printf("aaaaa");
		resize(repos);
		//printf("%d\n", repos->cp);
	}
	*(repos->v + repos->n) = tr;
	repos->n++;
	return 0;
}

int delete(repo *repos, int id)
{
	tranzactie k;
	int gasit = 0;
	for (int i = 0;i < repos->n;i++)
	{
		k = *(repos->v + i);
		if (getId(k) == id)
		{
			destruct(k);
			gasit = 1;
			int oke = i;
			for (int j = oke; j < repos->n - 1; j++)
			{
				*(repos->v + j) = *(repos->v + j + 1);
			}
			repos->n--;
			if (repos->n == repos->cp / 2 && repos->n > 1)
			{
				devide(repos);
			}
		}
	}

	if (gasit == 0)
		return 2;
	else
		return 0;
}

int update(repo* repos, tranzactie tr)
{
	tranzactie k;
	int gasit = 0;
	for (int i = 0;i < repos->n;i++)
	{
		k = *(repos->v + i);
		if (getId(k) == getId(tr))
		{
			gasit = 1;
			setSuma((repos->v + i), getSuma(tr));
			setZi((repos->v + i), getZi(tr));
			setTip((repos->v + i), getTip(tr));
			setDesc((repos->v + i), getDesc(tr));
		}
	}
	if (gasit == 0)
		return 2;
	else
		return 0;
}

int lungime(repo repos)
{
	return repos.n;
}

repo getAll(repo repos)
{
	return repos;
}