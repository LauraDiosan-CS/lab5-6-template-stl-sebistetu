#pragma once
#include "produs.h"
#include <vector>
using namespace std;

template <class T>
class Repo {

private:
	vector <T> obiecte;
	int nr_obiecte;

public:
	//Constructor
	Repo() {

		nr_obiecte = 0;
	}

	//Deconstructor
	~Repo() {}

	//Adaugare produs
	//in: e: elem de tip T
	//out: true, daca s-a efectuat adaugarea, false altfel
	bool addElem(T& e) {

		for (int i = 0; i < nr_obiecte; i++)
			if (e.get_id() == obiecte[i].get_id())
				return false;

		obiecte.push_back(e);
		nr_obiecte++;
		return true;
	}

	//Returneaza lista de obiecte
	//in: -
	//out: vector<T>, vectorul de obiecte
	vector <T> getAll() {

		return obiecte;
	}

	//Returneaza obiectul cu un anumit id
	//in: id, int
	//out: un obiect de tip T
	T getById(int id) {

		for (int i = 0; i < nr_obiecte; i++)
			if (id == obiecte[i].get_id())
				return obiecte[i];
	}

	//Stergere produs
	//in: e: elem de tip T
	//out: true, daca s-a efectuat stergerea, false altfel
	bool deteleElem(int id) {

		for (int i = 0; i < nr_obiecte; ++i)
			if (obiecte[i].get_id() == id) {

				obiecte.erase(obiecte.begin() + i);
				nr_obiecte--;
				return true;
			}
		return false;
	}

	//Modificare produs
	//in: e: elem de tip T
	//out: true, daca s-a efectuat modificarea, false altfel
	bool updateElem(T& e) {

		for (int i = 0; i < nr_obiecte; ++i)
			if (e.get_id() == obiecte[i].get_id()) {
				obiecte[i] = e;
				return true;
			}
		return false;
	}
};