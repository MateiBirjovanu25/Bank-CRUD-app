#include <stdio.h>
#include <stdlib.h>
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "domain.h"

void ui(serv* servo)
{
	tranzactie tr;
	repo kappa;
	int id,suma,zia,luna,ana,n,colector;
	char tip[256],descriere[256],a[20];
	
	while (1)
	{
		printf("1. Adauga\n2. Modifica\n3. Sterge\n");
		printf("----------------------------\n");
		printf("vizualizare tranzactii dupa:\n");
		printf("   4. tip\n");
		printf("   5. suma(mai mare)\n");
		printf("   6. suma(mai mica)\n");
		printf("------------------------------\n");
		printf("vizualizare tranzactii sortate dupa suma:\n");
		printf("   7. crescator\n");
		printf("   8. descrescator\n");
		printf("vizualizare tranzactii sortate dupa zi:\n");
		printf("   9. crescator\n");
		printf("   10. descrescator\n");
		printf("------------------------------\n");
		printf("11. Afisare lista\n12. EXIT\n");


		int optiune;
		printf("introduceti comanda: ");
		if (scanf("%d", &n) < 1)
		{
			while (getchar() != '\n');
			optiune = -1;
		}
		else
			optiune = n;

		system("cls");

		if (optiune == 1)
		{
			int corect = 0;
			printf("introduceti id-ul: ");
			if(scanf("%d", &id) < 1)
				corect = 1;

			if (corect != 1)
			{
				printf("introduceti suma: ");
				if (scanf("%d", &suma) < 1)
					corect = 1;
			}
		
			if (corect != 1)
			{
				printf("introduceti ziua: ");
				if (scanf("%d", &zia) < 1)
					corect = 1;
			}
			
			if (corect != 1)
			{
				printf("introduceti luna: ");
				if (scanf("%d", &luna) < 1)
					corect = 1;
			}

			
			if (corect != 1)
			{
				printf("introduceti an: ");
				if (scanf("%d", &ana) < 1)
					corect = 1;
			}

			if (corect == 0)
			{
				gets(a);

				printf("introduceti tip: ");
				gets(tip);

				printf("introduceti descriere: ");
				gets(descriere);

				printf("\n");

				int verificare;
				verificare = adaugare(&(servo->repository), id, zia, luna, ana, suma, tip, descriere);
				if (verificare == 1)
					printf("date invalide\n\n");
				else if (verificare == 2)
					printf("exista deja tranzactie cu acest id\n\n");
			}
			else
			{
				while (getchar() != '\n');
				printf("tip de data invalid\n");
			}
		}

		else if (optiune == 2)
		{
			int corect = 0;
			printf("introduceti id-ul: ");
			if (scanf("%d", &id) < 1)
				corect = 1;

			if (corect != 1)
			{
				printf("introduceti suma: ");
				if (scanf("%d", &suma) < 1)
					corect = 1;
			}

			if (corect != 1)
			{
				printf("introduceti ziua: ");
				if (scanf("%d", &zia) < 1)
					corect = 1;
			}

			if (corect != 1)
			{
				printf("introduceti luna: ");
				if (scanf("%d", &luna) < 1)
					corect = 1;
			}


			if (corect != 1)
			{
				printf("introduceti an: ");
				if (scanf("%d", &ana) < 1)
					corect = 1;
			}

			if (corect == 0)
			{
				gets(a);

				printf("introduceti tip: ");
				gets(tip);

				printf("introduceti descriere: ");
				gets(descriere);

				printf("\n");

				int verificare;
				verificare = actualizare(&(servo->repository), id, zia, luna, ana, suma, tip, descriere);
				if (verificare == 1)
					printf("date invalide\n\n");
				else if (verificare == 2)
					printf("nu exista tranzactie\n\n");
			}
			else
			{
				while (getchar() != '\n');
				printf("tip de data invalid\n");
			}
		}

		else if (optiune == 3)
		{
			printf("introduceti id-ul: ");
			colector = scanf("%d", &id);

			printf("\n");

			int verificare;
			verificare = stergere(&(servo->repository), id);
			if (verificare == 2)
				printf("nu exista tranzactie\n\n");
		}

		else if (optiune == 4)
		{
			char ab[20];
			gets(ab);
			
			repo reposi;
			reposi = repoConstructor();
			printf("introduceti tip: ");
			gets(tip);
			filtrareTip(&reposi, servo->repository,tip);
			for (int i = 0;i < reposi.n;i++)
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
			free(reposi.v);
		}

		else if (optiune == 5)
		{
			int sumas;
			repo reposi;
			reposi = repoConstructor();
			printf("introduceti suma: ");
			colector=scanf("%d", &sumas);
			filtrareSuma(&reposi, servo->repository, sumas, 2);
			for (int i = 0;i < reposi.n;i++)
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
			free(reposi.v);
		}	

		else if (optiune == 6)
		{
			int sumad;
			repo reposi;
			reposi = repoConstructor();
			printf("introduceti suma: ");
			colector=scanf("%d", &sumad);
			filtrareSuma(&reposi, servo->repository, sumad, 1);
			for (int i = 0;i < reposi.n;i++)
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
			free(reposi.v);
		}

		else if (optiune == 7)
		{
			repo reposi;
			reposi = repoConstructor();

			sortareSuma(&reposi, servo->repository, 1);

			for (int i = 0;i < reposi.n;i++)
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
			free(reposi.v);
		}

		else if (optiune == 8)
		{
			repo reposi;
			reposi = repoConstructor();

			sortareSuma(&reposi, servo->repository, 2);

			for (int i = 0;i < reposi.n;i++)
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
			free(reposi.v);
		}

		else if (optiune == 9)
		{
			repo reposi;
			reposi = repoConstructor();

			sortareZi(&reposi, servo->repository, 1);

			for (int i = 0;i < reposi.n;i++)
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
			free(reposi.v);
		}

		else if (optiune == 10)
		{
		repo reposi;
		reposi = repoConstructor();

		sortareZi(&reposi, servo->repository, 2);

		for (int i = 0;i < reposi.n;i++)
			printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(reposi.v[i]), getZi(reposi.v[i]).zi, getZi(reposi.v[i]).luna, getZi(reposi.v[i]).an, getSuma(reposi.v[i]), getTip(reposi.v[i]), getDesc(reposi.v[i]));
		free(reposi.v);
		}

		else if (optiune == 11)
		{
			kappa=getTranzactii(*servo);
			for (int i = 0;i < kappa.n;i++)
			{
				tr = *(kappa.v + i);
				printf("id: %d, zi: %d.%d.%d, suma: %d, tip: %s, descriere: %s\n\n", getId(tr), getZi(tr).zi, getZi(tr).luna, getZi(tr).an, getSuma(tr), getTip(tr), getDesc(tr));
			}
		}

		else if (optiune == 12)
		{
			break;
		}

		else
		{
			printf("invalid\n");
		}
			
	}
}
