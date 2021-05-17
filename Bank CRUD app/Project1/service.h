#pragma once
#include "repo.h"


/*
structura service-ului
*/
typedef struct {
	repo repository;
}serv;



/*
functia creeaza o structura serv
preconditii: repos(structura repo)
postconditii: servo(structura serv)
*/
serv servConstruct(repo repos);


/*
functia adauga in repository o noua tranzactie sau returneaza un cod de eroare
preconditii: repos(structura repo), id(int), zi(int), luna(int), an(int), suma(int), tip(char*), descriere(char*)
postconditii: se returneaza 0 daca s-a realizat cu succes adaugarea, 1 daca datele nu sunt valide sau 2 daca deja exista o tranzactie cu acest id
*/
int adaugare(repo *repos, int id, int zia, int luna, int an, int suma, char* tip, char* descriere);


/*
functia actualizeaza o tranzactie din repository sau returneaza un cod de eroare
preconditii: repos(structura repo), id(int), zi(int), luna(int), an(int), suma(int), tip(char*), descriere(char*)
posconditii: se returneaza 0 daca s-a realizat cu succes actualizarea, 1 daca datele nu sunt valide sau 2 daca deja exista o tranzactie cu acest id
*/
int actualizare(repo* repos, int id, int zia, int luna, int an, int suma, char* tip, char* descriere);


/*
functia sterge o tranzactie din repository sau returneaza un cod de eroare
preconditii: repos(structura repo), id(int)
postconditii: se returneaza 0 daca s-ar realizat cu succes stergerea sau 2 daca nu exista o tranzactie cu acest id
*/
int stergere(repo* repos, int id);

/*
functia returneaza lungimea repository-ului asociat service-ului actual
preconditii: repos(structura repo)
postconditii: se returneaza o lungime (int)
*/
int lungimeServ(repo repos);

/*
functia elibereaza memoria alocata repo-ului
preconditii: repos(structura repo)
postconditii: -
*/
void servDestructor(repo repos);


/*
functia returneaza repo-ul asocita servo-ului data ca parametru
preconditii: servo(serv)
postconditii: se returneaza o structura repo
*/
repo getTranzactii(serv servo);


/*
functia modifica structura repo si salveaza in aceasta elementele a caror tip corespund cu cel dat
preconditii: reposNou(structura repo), repos(structura repo), tip(char*)
postconditii: -
*/
void filtrareTip(repo* reposNou, repo repos, char* tip);


/*
functia modifica structura repo si salveaza in aceasta elementele a caror suma corespund cu cea dat.
In functie de caz se stabileste daca elementele alese sunt mai mici sau mai mari decat suma data.
preconditii: reposNou(structura repo), repos(structura repo), suma(int), caz(int)
postconditii: -
*/
void filtrareSuma(repo* reposNou, repo repos, int suma, int caz);


/*
functia sorteaza elementele din repository in functie de suma
In functie de caz se stabileste daca sortarea se face crescator sau descrescator
preconditii: reposNou(structura repo), repos(structura repo), caz(int)
postconditii: -
*/
void sortareSuma(repo* reposNou, repo repos, int caz);


/*
functia sorteaza elementele din repository in functie de zi
In functie de caz se stabileste daca sortarea se face crescator sau descrescator
preconditii: reposNou(structura repo), repos(structura repo), caz(int)
postconditii: -
*/
void sortareZi(repo* reposNou, repo repos, int caz);
