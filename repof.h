#pragma once
#include "repo.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class RepoFile : public Repo<T> {

private:
	char* file;
public:
	//Constructor
	RepoFile() : Repo<T>() {

		file = NULL;
	}

	//Deconstructor
	~RepoFile() {

		delete[] file;
	}

	//Constructor cu parametru
	RepoFile(const char* fileName) {

		int lung = strlen(fileName);
		file = new char[lung + 1];
		strcpy_s(file, lung + 1, fileName);
		loadFromFile();
	}

	//Operatorul de atribuire
	RepoFile& operator=(const RepoFile& r)
	{
		setFileName(r.file);
		loadFromFile();
		return *this;
	}

	//Seteaza numele fisierului
	void setFileName(const char* fileName) {

		if (file != NULL)
			delete[] file;
		if (fileName != NULL) {

			file = new char[strlen(fileName) + 1];
			strcpy_s(file, strlen(fileName) + 1, fileName);
		}
		else
			file = NULL;

	}

	//Adaugare produs
	//in: e: elem de tip T
	//out: true, daca s-a efectuat adaugarea, false altfel
	bool addElem(T& e) {

		bool r = Repo<T>::addElem(e);
		saveToFile();
		return r;
	}

	//Stergere produs
	//in: e: elem de tip T
	//out: true, daca s-a efectuat stergerea, false altfel
	bool deteleElem(int id) {

		bool r = Repo<T>::deteleElem(id);
		saveToFile();
		return r;
	}
	
	//Modificare produs
	//in: e: elem de tip T
	//out: true, daca s-a efectuat modificarea, false altfel
	bool updateElem(T& e) {

		bool r = Repo<T>::updateElem(e);
		saveToFile();
		return r;
	}

	//Citeste din fisier lista de obiecte
	void loadFromFile() {

		if (file != NULL) {

			Repo<T>::getAll().clear();
			ifstream f(file);
			T elem;
			while (!f.eof()) {

				f >> elem;
				if (!!elem)
					Repo<T>::addElem(elem);
			}
			f.close();
		}
	}

	//Scrie in fisier lista de obiecte
	void saveToFile() {

		if (file != NULL) {

			ofstream g (file);
			vector<T> v = Repo<T>::getAll();
			for (int i = 0; i < v.size(); i++)
				g << Repo<T>::getAll()[i] << '\n';
			g.close();
		}
	}

	//Returneaza lista de obiecte
	//in: -
	//out: vector<T>, vectorul de obiecte
	vector <T> getAll() {

		return Repo<T>::getAll();
	}
};