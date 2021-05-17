#pragma once

/*
structura pentru stocarea unei zile
*/
typedef struct
{
	int zi;
	int luna;
	int an;
}zi;


/*
structura pentru memorarea unei tranzactii
*/
typedef struct
{
	int id;
	zi ziua;
	int suma;
	char* tip;
	char* descriere;
}tranzactie;