#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "domain.h"
#include "tranzactie.h"


zi zilitor(int zia, int lunaa, int ana)
{
	zi dias;
	dias.zi = zia;
	dias.luna = lunaa;
	dias.an = ana;
	return dias;
}

tranzactie construct(int id, zi day, int suma, char* tip, char* descriere)
{
	tranzactie tr;
	tr.id = id;
	tr.ziua = day;
	tr.suma = suma;

	tr.tip = (char*)malloc(strlen(tip) + 1);
	strcpy(tr.tip, tip);
	tr.descriere = (char*)malloc(strlen(descriere) + 1);
	strcpy(tr.descriere, descriere);

	return tr;
}

void destruct(tranzactie tr)
{
	free(tr.tip);
	free(tr.descriere);
}

int getId(tranzactie tr)
{
	return tr.id;
}

zi getZi(tranzactie tr)
{
	return tr.ziua;
}

int getSuma(tranzactie tr)
{
	return tr.suma;
}

char* getTip(tranzactie tr)
{
	return tr.tip;
}

char* getDesc(tranzactie tr)
{
	return tr.descriere;
}

void setZi(tranzactie *tr,  zi day)
{
	tr->ziua.zi = day.zi;
	tr->ziua.luna = day.luna;
	tr->ziua.an = day.an;
}

void setSuma(tranzactie *tr, int suma)
{
	tr->suma = suma;
}

void setTip(tranzactie* tr, char* tip)
{
	free(tr->tip);
	tr->tip = malloc(strlen(tip)+1);
	strcpy(tr->tip, tip);
}


void setDesc(tranzactie* tr, char* desc)
{
	free(tr->descriere);
	tr->descriere = malloc(strlen(desc) + 1);
	strcpy(tr->descriere, desc);
}






