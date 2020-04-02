#include "test.h"
#include "produs.h"
#include "repo.h"
#include <assert.h>
#include <string.h>

void test_produs() {

	char* ana = new char[4];
	strcpy_s(ana, 4, "ana");

	char* faina = new char[6];
	strcpy_s(faina, 6, "faina");

	Produs p1, p2, p3;
	p1 = Produs(100, 1000.0, ana, faina);
	p2 = Produs(p1);

	assert(p2.get_id() == 100);
	assert(strcmp(ana, p2.get_nume()) == 0);

	p3 = p1;
	assert(strcmp(faina, p3.get_ingrediente()) == 0);
	assert(p3 == p1);
}

void test_repo() {

	Repo repo;
	Produs produse[50];
	int lung = 0;

	char* ana = new char[4];
	strcpy_s(ana, 4, "ana");

	char* alina = new char[6];
	strcpy_s(alina, 6, "alina");

	char* iulia = new char[6];
	strcpy_s(iulia, 6, "iulia");

	char* faina = new char[6];
	strcpy_s(faina, 6, "faina");

	char* drojdie = new char[8];
	strcpy_s(drojdie, 8, "drojdie");

	char* sare = new char[5];
	strcpy_s(sare, 5, "sare");

	Produs p1, p2, p3;
	p1 = Produs(100, 1000, ana, faina);
	p2 = Produs(200, 2000, alina, drojdie);
	p3 = Produs(100, 3000, iulia, sare);

	repo.addElem(p1);
	repo.addElem(p2);
	repo.getAll(produse, lung);
	assert(lung == 2);
	assert(produse[0] == p1);

	repo.updateElem(p3);
	repo.getAll(produse, lung);
	assert(produse[0] == p3);

	repo.deteleElem(200);
	repo.getAll(produse, lung);
	assert(lung == 1);
}