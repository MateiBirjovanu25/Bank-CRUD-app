#include <stdio.h>
#include "service.h"
#include "repo.h"
#include "domain.h"
#include "validator.h"
#include <stdlib.h>
#include <string.h>





serv servConstruct(repo repos)
{
	serv servo;
	servo.repository = repos;
	return servo;
}



int adaugare(repo *repos, int id,int zia,int luna,int an ,int suma, char* tip, char* descriere)
{
	zi dias;
	dias.zi = zia;
	dias.luna = luna;
	dias.an = an;
	tranzactie tr = construct(id, dias, suma, tip, descriere);
	int stare;
	if (validare(tr) == 0)
	{
		stare = add(*(&repos), tr);
		if (stare == 2)
		{
			destruct(tr);
			return 2;
		}
			
		return 0;
	}
	destruct(tr);
	return 1;
}

int stergere(repo* repos, int id)
{
	int stare;
	stare = delete(*(&repos), id);
	if (stare == 2)
		return 2;
	return 0;
}


int actualizare(repo* repos, int id, int zia, int luna, int an, int suma, char* tip, char* descriere)
{
	zi dias;
	dias.zi = zia;
	dias.luna = luna;
	dias.an = an;
	int stare;
	tranzactie tr = construct(id, dias, suma, tip, descriere);
	if (validare(tr) == 0)
	{
		stare = update(*(&repos), tr);
		if (stare == 2)
		{
			destruct(tr);
			return 2;
		}
		destruct(tr);
		return 0;
	}
	destruct(tr);
	return 1;
}


int lungimeServ(repo repos)
{
	int k;
	k= lungime(repos);
	return k;
}


void servDestructor(repo repos)
{
	repoDestructor(repos);
}


repo getTranzactii(serv servo)
{
	return getAll(servo.repository);
}

void filtrareTip(repo* reposNou,repo repos,char* tip)
{
	for (int i = 0;i < repos.n;i++)
	{
		if (strcmp(getTip(repos.v[i]), tip) == 0)
			add(reposNou, repos.v[i]);
	}
}

void filtrareSuma(repo* reposNou, repo repos, int suma, int caz)
{
	if (caz == 1)
	{
		for (int i = 0;i < repos.n;i++)
		{
			if (getSuma(repos.v[i])<suma)
				add(reposNou, repos.v[i]);
		}
	}

	else
	{
		for (int i = 0;i < repos.n;i++)
		{
			if (getSuma(repos.v[i]) > suma)
				add(reposNou, repos.v[i]);
		}
	}
	
}


int cmp(tranzactie a, tranzactie b, int caz,int criteriu)
{
	if (criteriu == 1)
	{
		if (caz == 1)
		{
			if (a.suma > b.suma)
			{
				return 1;
			}
			return 0;}
		else
		{
			if (a.suma < b.suma)
			{
				return 1;
			}
			return 0;}}

	else
	{
		if (caz == 1)
		{
			if (a.ziua.an > b.ziua.an)
			{
				return 1;}
			else if (a.ziua.an == b.ziua.an)
			{
				if (a.ziua.luna > b.ziua.luna)
				{
					return 1;}
				else if (a.ziua.luna == b.ziua.luna)
				{
					if (a.ziua.zi > b.ziua.zi)
					{
						return 1;
					}
				}
			}
			return 0;}
		else
		{
			if (a.ziua.an < b.ziua.an)
			{
				return 1;}
			else if (a.ziua.an == b.ziua.an)
			{
				if (a.ziua.luna < b.ziua.luna)
				{
					return 1;}
				else if (a.ziua.luna == b.ziua.luna)
				{
					if (a.ziua.zi < b.ziua.zi)
					{
						return 1;
					}
				}
			}
			return 0;
		}
	}
}


void sort(repo* repos,int caz,int criteriu,int(*comp)(tranzactie,tranzactie,int,int))
{
	int ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0;i < repos->n-1;i++)
		{
			if (comp(repos->v[i], repos->v[i+1], caz,criteriu)==1)
			{
				tranzactie aux;
				aux = repos->v[i];
				repos->v[i] = repos->v[i+1];
				repos->v[i+1] = aux;
				ok = 0;
			}
		}

	}
}


void sortareSuma(repo* reposNou, repo repos, int caz)
{
	for (int i = 0;i < repos.n;i++)
	{
		add(reposNou, repos.v[i]);
	}

	sort(reposNou, caz, 1,cmp);
}


void sortareZi(repo * reposNou, repo repos, int caz)
{
	for (int i = 0;i < repos.n;i++)
	{
		add(reposNou, repos.v[i]);
	}

	sort(reposNou, caz, 2,cmp);

}

