#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <memory.h>

#include <stdio.h>
#include "pseudotest.h"
#include "ui.h"
#include "repo.h"
#include "service.h"

void main()
{
	testDomain();
	testRepo();
	testServ();
	testServ2();
	testValid();
	
	repo repos;
	repos=repoConstructor();

	serv servo;
	servo.repository = repos;
	
	ui(&servo);
	
	repoDestructor(servo.repository);
	_CrtDumpMemoryLeaks();
}