#include "domain.h"
#include <stdio.h>
#include "tranzactie.h"
#include "repo.h"
#include <assert.h>
#include "service.h"
#include <stdlib.h>
#include <string.h>
#include "pseudotest.h"
#include "validator.h"
void testDomain()
{
	zi dios;
	tranzactie tr;
	dios = zilitor(1, 1, 2000);

	tr = construct(1,dios,20,"intrare","oke");

	assert(getSuma(tr) == 20);

	assert(strcmp(getTip(tr),"intrare")==0);

	assert(strcmp(getDesc(tr), "oke") == 0);

	assert(getZi(tr).an==2000);

	dios = zilitor(2, 2, 1000);

	setZi(&tr, dios);
	dios = getZi(tr);
	assert(dios.an == 1000);

	setSuma(&tr, 40);
	assert(getSuma(tr) == 40);

	setTip(&tr, "nah");
	assert(strcmp(getTip(tr),"nah")==0);

	setDesc(&tr, "bah");
	assert(strcmp(getDesc(tr), "bah") == 0);

	destruct(tr);
	
}

void testRepo()
{
	repo repos;
	repos = repoConstructor();


	zi dios;
	tranzactie tr;
	dios = zilitor(1, 1, 2000);
	tr = construct(1, dios, 20, "intrare", "oke");
	

	assert(lungime(repos) == 0);

	add(&repos, tr);

	int k,suma;
	k = getId(*(repos.v));
	suma = getSuma(*(repos.v));
	assert(k == 1);
	assert(suma == 20);


	assert(lungime(repos) == 1);

	delete(&repos, 1);

	assert(lungime(repos) == 0);

	dios = zilitor(1, 1, 2000);
	tr = construct(1, dios, 20, "intrare", "oke");
	add(&repos, tr);

	dios = zilitor(1, 1, 2000);
	tr = construct(2, dios, 20, "intrare", "oke");
	add(&repos, tr);

	assert(lungime(repos) == 2);

	dios = zilitor(1, 1, 2000);
	tr = construct(3, dios, 20, "intrare", "oke");
	add(&repos, tr);

	dios = zilitor(1, 1, 2000);
	tr = construct(4, dios, 20, "intrare", "oke");
	add(&repos, tr);

	assert(lungime(repos) == 4);

	delete(&repos, 5);

	assert(lungime(repos) == 4);

	assert(lungime(getAll(repos)) == 4);

	delete(&repos, 1);

	repo maomor;

	maomor = getAll(repos);

	assert(getId(maomor.v[0]) == 2);

	dios = zilitor(1, 1, 2000);
	tr = construct(2, dios, 450, "intrare", "oke");
	update(&repos, tr);
	destruct(tr);

	assert(getSuma(maomor.v[0]) == 450);

	dios = zilitor(1, 1, 2000);
	tr = construct(5, dios, 20, "intrare", "oke");
	add(&repos, tr);

	dios = zilitor(1, 1, 2000);
	tr = construct(6, dios, 20, "intrare", "oke");
	add(&repos, tr);

	int verif = add(&repos, tr);

	assert(verif == 2);

	tr = construct(1, dios, 20, "intrare", "oke");
	verif = update(&repos, tr);
	assert(verif == 2);
	destruct(tr);

	delete(&repos, 2);
	delete(&repos, 3);
	delete(&repos, 4);
	delete(&repos, 5);

	repoDestructor(repos);
}

void testServ()
{
	serv servo;
	repo repos = repoConstructor();
	servo = servConstruct(repos);
	int k;
	k = lungimeServ(servo.repository);
	assert(k == 0);
	adaugare(&servo.repository, 1, 1, 1, 2000, 20, "intrare", "oke");

	repo cont;
	int lung;
	cont = getTranzactii(servo);
	lung=lungimeServ(servo.repository);
	assert(lung == 1);

	stergere(&servo.repository, 1);

	cont = getTranzactii(servo);
	lung = lungimeServ(servo.repository);
	assert(lung == 0);

	adaugare(&servo.repository, 1, 1, 1, 2000, 20, "intrare", "oke");
	actualizare(&servo.repository, 1, 2, 2, 2001, 200, "intrare", "ok");
	
	int verif;

	verif=adaugare(&servo.repository, 1, 1, 1, 2000, 20, "intrare", "ok");
	assert(verif == 2);

	stergere(&servo.repository, 1);

	verif = adaugare(&servo.repository, 1, 1, 1, -2000, 20, "intrare", "ok");
	assert(verif == 1);

	verif = adaugare(&servo.repository, 1, 1, 1, 2000, 20, "intrare", "ok");

	verif=actualizare(&servo.repository, 2, 2, 2, 2001, 200, "intrare", "ok");
	assert(verif == 2);

	verif=actualizare(&servo.repository, 1, 2, 2, 2001, 200, "in", "ok");
	assert(verif == 1);

	verif= stergere(&servo.repository, 5);
	assert(verif == 2);


	servDestructor(servo.repository);
}

void testServ2()
{

	serv servo;
	repo repos = repoConstructor();
	servo = servConstruct(repos);

	adaugare(&servo.repository, 1, 24, 2, 2001,1,"intrare", "ok1");
	adaugare(&servo.repository, 2, 23, 2, 2001,3, "iesire", "ok2");
	adaugare(&servo.repository, 3, 25, 2, 2001,2, "intrare", "ok3");


	repo repos1 = repoConstructor();
	filtrareSuma(&repos1, servo.repository, 2, 1);
	assert(lungime(repos1) == 1);
	free(repos1.v);


	repos1 = repoConstructor();
	filtrareSuma(&repos1, servo.repository, 2, 2);
	assert(lungime(repos1) == 1);
	free(repos1.v);


	repos1 = repoConstructor();
	filtrareTip(&repos1, servo.repository, "intrare");
	assert(lungime(repos1) == 2);
	free(repos1.v);

	repos1 = repoConstructor();
	filtrareTip(&repos1, servo.repository, "iesire");
	assert(lungime(repos1) == 1);
	free(repos1.v);

	repos1 = repoConstructor();
	sortareSuma(&repos1, servo.repository, 1);
	assert(repos1.v[0].suma==1);
	free(repos1.v);

	repos1 = repoConstructor();
	sortareSuma(&repos1, servo.repository, 2);
	assert(repos1.v[0].suma == 3);
	free(repos1.v);


	repos1 = repoConstructor();
	sortareZi(&repos1, servo.repository, 1);
	assert(repos1.v[0].ziua.zi == 23);
	free(repos1.v);

	repos1 = repoConstructor();
	sortareZi(&repos1, servo.repository, 2);
	assert(repos1.v[0].ziua.zi == 25);
	free(repos1.v);

	stergere(&servo.repository, 1);
	stergere(&servo.repository, 2);
	stergere(&servo.repository, 3);

	adaugare(&servo.repository, 1, 24, 1, 2001, 1, "intrare", "ok1");
	adaugare(&servo.repository, 2, 23, 3, 2001, 3, "iesire", "ok2");
	adaugare(&servo.repository, 3, 25, 2, 2001, 2, "intrare", "ok3");

	repos1 = repoConstructor();
	sortareZi(&repos1, servo.repository, 2);
	assert(repos1.v[0].ziua.zi == 23);
	free(repos1.v);

	repos1 = repoConstructor();
	sortareZi(&repos1, servo.repository, 1);
	assert(repos1.v[0].ziua.zi == 24);
	free(repos1.v);

	stergere(&servo.repository, 1);
	stergere(&servo.repository, 2);
	stergere(&servo.repository, 3);

	adaugare(&servo.repository, 1, 24, 1, 2001, 1, "intrare", "ok1");
	adaugare(&servo.repository, 2, 23, 2, 2003, 3, "iesire", "ok2");
	adaugare(&servo.repository, 3, 25, 3, 2002, 2, "intrare", "ok3");


	repos1 = repoConstructor();
	sortareZi(&repos1, servo.repository, 1);
	assert(repos1.v[0].ziua.an == 2001);
	free(repos1.v);

	repos1 = repoConstructor();
	sortareZi(&repos1, servo.repository, 2);
	assert(repos1.v[0].ziua.an == 2003);
	free(repos1.v);

	



	servDestructor(servo.repository);
}

void testValid()
{
	int verif;
	zi dios;
	tranzactie tr;
	dios = zilitor(1, 1, 2000);

	tr = construct(5, dios, 20, "intrar", "oke");
	verif=validare(tr);
	assert(verif == 1);
	destruct(tr);

	tr = construct(5, dios, 20, "intrare", "");
	verif = validare(tr);
	assert(verif == 1);
	destruct(tr);

	tr = construct(5, dios, -20, "intrare", "oke");
	verif = validare(tr);
	assert(verif == 1);
	destruct(tr);

	dios = zilitor(1, 1, -1);
	tr = construct(5, dios, 20, "intrare", "oke");
	verif = validare(tr);
	assert(verif == 1);
	destruct(tr);

	dios = zilitor(1, 13, 2000);
	tr = construct(5, dios, 20, "intrare", "oke");
	verif = validare(tr);
	assert(verif == 1);
	destruct(tr);

	dios = zilitor(40, 12, 2000);
	tr = construct(5, dios, 20, "intrare", "oke");
	verif = validare(tr);
	assert(verif == 1);
	destruct(tr);

	tr = construct(-1, dios, 20, "intrare", "oke");
	verif = validare(tr);
	assert(verif == 1);
	destruct(tr);
}










