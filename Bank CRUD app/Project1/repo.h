#pragma once
#include <stdlib.h>
#include "tranzactie.h"


/*
structura repository-ului
*/
typedef struct {
	tranzactie* v;
	int n;
	int cp;
}repo;


/*
functia creeaza o structura repo
preconditii: -
postconditii: repos(structura repo)
*/
repo repoConstructor();


/*
functia elibereaza memoria alocata repo-ului
preconditii: repos(structura repo)
postconditii: -
*/
void repoDestructor(repo repos);


/*
functia dubleaza memoria alocata vectorului din repo
preconditii: repos(structura repo)
postconditii: -
*/
void resize(repo* repos);


/*
functia injumatateste memoria alocata vectorului din repo
preconditii: repos(structura repo)
postconditii: -
*/
void devide(repo* repos);


/*
functia adauga o tranzactie in repository sau returneaza un cod de eroare
preconditii: repos(structura repo), tr(structura tranzactie)
postconditii: se returneaza 0 daca s-ar realizat cu succes adaugarea sau 2 daca deja exista o tranzactie cu acest id
*/
int add(repo* repos, tranzactie tr);


/*
functia sterge o tranzactie din repository sau returneaza un cod de eroare
preconditii: repos(structura repo), id(int)
postconditii: se returneaza 0 daca s-ar realizat cu succes stergerea sau 2 daca nu exista o tranzactie cu acest id
*/
int  delete(repo* repos, int id);


/*
functia actualizeaza o tranzactie din repository sau returneaza un cod de eroare
preconditii: repos(structura repo), tr(structura tranzactie)
postconditii: se returneaza 0 daca s-ar realizat cu succes actualizarea sau 2 daca nu exista o tranzactie cu acest id
*/
int update(repo* repos, tranzactie tr);


/*
functia returneaza lungimea repository-ului dat ca parametru
preconditii: repos(structura repo)
postconditii: se returneaza o lungime (int)
*/
int lungime(repo);


/*
functia returneaza repo-ul dat ca parametru
preconditii: repos (repo)
postconditii: se returneaza o structura repo
*/
repo getAll(repo repos);