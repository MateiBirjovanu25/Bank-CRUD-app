#include <stdio.h>
#include "validator.h"
#include "tranzactie.h"
#include "string.h"
#include "domain.h"

int validare(tranzactie tr)
{
	if (getId(tr) < 0)
		return 1;

	if (strcmp(getTip(tr), "intrare") != 0 && strcmp(getTip(tr), "iesire") != 0)
		return 1;

	if (getSuma(tr) <= 0)
		return 1;

	if (strlen(getDesc(tr)) == 0)
		return 1;

	zi dios;
	dios = getZi(tr);

	if (dios.zi < 1 || dios.zi>30)
		return 1;

	if (dios.luna < 1 || dios.luna>12)
		return 1;

	if (dios.an<0)
		return 1;

	return 0;

	
}