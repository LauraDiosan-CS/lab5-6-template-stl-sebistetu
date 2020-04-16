#pragma once
#include "repof.h"
#include "produs.h"
#include <vector>

class Service {
private:
	RepoFile<Produs> repo;
public:
	Service();
	Service(const RepoFile<Produs>& r);
	~Service();
	bool addProd(int, double, char*, char*);
	bool delProd(int);
	bool updateProd(int, double, char*, char*);
	vector <Produs> getAll();
	Service(const Service& s);
	double medie_ingredient(char* ingr);
	vector< pair <char*, double> > get_lista_medii_ingr();
};