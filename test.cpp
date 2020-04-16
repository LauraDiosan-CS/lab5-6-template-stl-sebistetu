#include "test.h"
#include "produs.h"
#include "repo.h"
#include "repof.h"
#include "service.h"
#include <assert.h>
#include <string.h>
#include <vector>
using namespace std;

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

	delete[] ana, faina;
}

void test_repo() {

	Repo <Produs>repo;

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
	vector <Produs> lista = repo.getAll();
	assert(lista.size() == 2);
	assert(lista[0] == p1);

	repo.updateElem(p3);
	lista = repo.getAll();
	assert(lista[0] == p3);

	repo.deteleElem(200);
	lista = repo.getAll();
	assert(lista.size() == 1);

	delete[] ana, alina, iulia, faina, drojdie, sare;
}

void test_repo_file() {

	ofstream ofs;
	ofs.open("test.txt", ofstream::out | ofstream::trunc);
	ofs.close();

	RepoFile <Produs>repo("test.txt");

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
	vector <Produs> lista = repo.getAll();
	assert(lista.size() == 2);
	assert(lista[0] == p1);

	repo.updateElem(p3);
	lista = repo.getAll();
	assert(lista[0] == p3);

	repo.deteleElem(200);
	lista = repo.getAll();
	assert(lista.size() == 1);
	delete[] ana, alina, iulia, faina, drojdie, sare;
}

void test_service() {

	ofstream ofs;
	ofs.open("test.txt", ofstream::out | ofstream::trunc);
	ofs.close();

	RepoFile <Produs>repo("test.txt");
	Service s(repo);

	char* ana = new char[4];
	strcpy_s(ana, 4, "ana");

	char* alina = new char[6];
	strcpy_s(alina, 6, "alina");

	char* iulia = new char[6];
	strcpy_s(iulia, 6, "iulia");

	char* faina = new char[6];
	strcpy_s(faina, 10, "faina,oua");

	char* drojdie = new char[8];
	strcpy_s(drojdie, 12, "drojdie,oua");

	char* sare = new char[5];
	strcpy_s(sare, 11, "sare,faina");

	Produs p1, p2, p3, p4;
	p1 = Produs(100, 1000, ana, faina);
	p2 = Produs(200, 2000, alina, drojdie);
	p3 = Produs(100, 3000, iulia, sare);
	p4 = Produs(300, 10000, alina, faina);

	s.addProd(100, 1000, ana, faina);
	s.addProd(200, 2000, alina, drojdie);
	s.addProd(300, 10000, alina, faina);
	vector <Produs> lista = s.getAll();
	assert(lista.size() == 3);
	assert(lista[0] == p1);

	s.updateProd(100, 3000, iulia, sare);
	lista = s.getAll();
	assert(lista[0] == p3);

	s.delProd(200);
	lista = s.getAll();
	assert(lista.size() == 2);

	char* faina1 = new char[6];
	strcpy_s(faina1, 6, "faina");

	char* sare1 = new char[6];
	strcpy_s(sare1, 6, "sare");

	assert(s.medie_ingredient(faina1) == 6500);

	vector < pair < char*, double > > rez = s.get_lista_medii_ingr();
	assert(rez.size() == 3);
	assert(strcmp(rez[1].first, faina1) == 0);
	assert(strcmp(rez[0].first, sare1) == 0);
	assert(rez[1].second == 6500);
	assert(rez[0].second == 3000);
	
	delete[] ana, alina, iulia, faina, drojdie, sare, faina1;
}
