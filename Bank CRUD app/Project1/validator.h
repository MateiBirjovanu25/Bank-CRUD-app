#pragma once
#include "tranzactie.h"

/*
functia verifica validitatea campurilor structurii tr (suma>0,zi existenta, tip(intrare/iesire),descriere nevida)
preconditii: tr(de tip tranzactie)
postconditii: se returneaza 0 daca structura e valida si 1 daca exista o problema
*/
int validare(tranzactie tr);