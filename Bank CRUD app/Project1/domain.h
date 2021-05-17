#pragma once
#include "tranzactie.h"


/*
functia creeaza o structura tranzactie
preconditii: id(int), day(structura zi), suma(int), tip(char*), descriere(char*)
postconditii: tr(structura tranzactie)
*/
tranzactie construct(int id, zi day, int suma, char* tip, char* descriere);

void destruct(tranzactie tr);

/*
functia creeaza o structura zi
preconditii: zi(int), luna(int), an(int)
postconditii: returneaza day(structura zi)
*/
zi zilitor(int zia, int lunaa, int ana);


/*
functia returneaza id-ul structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie)
postconditii:returneaza id(int)
*/
int getId( tranzactie tr);


/*
functia returneaza ziua structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie)
postconditii:returneaza day(structura zi)
*/
zi getZi( tranzactie tr);


/*
functia returneaza suma structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie)
postconditii:returneaza suma(int)
*/
int getSuma( tranzactie tr);


/*
functia returneaza tipul structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie)
postconditii:returneaza tip(char*)
*/
char* getTip( tranzactie tr);


/*
functia returneaza descrierea structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie)
postconditii:returneaza descriere(char*)
*/
char* getDesc( tranzactie tr);


/*
functia seteaza ziua structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie), day(zi)
postconditii: -
*/
void setZi( tranzactie *tr,  zi day);


/*
functia seteaza suma structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie), suma(int)
postconditii: -
*/
void setSuma( tranzactie *tr, int suma);


/*
functia seteaza tipul structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie), tip(char*)
postconditii: -
*/
void setTip( tranzactie *tr, char* tip);


/*
functia seteaza descrierea structurii tranzactie data ca parametru
preconditii: tr(structura tranzactie), descriere(char*)
postconditii: -
*/
void setDesc( tranzactie *tr, char* desc);
