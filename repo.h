#pragma once
#include "produs.h"

class Repo {

private:
	Produs produse[50];
	int nr_produse;
public:
	Repo();
	~Repo();
	bool addElem(Produs& p);
	void getAll(Produs lista[], int& lung);
	Produs getById(int);
	bool deteleElem(int);
	bool updateElem(Produs& p);
};
