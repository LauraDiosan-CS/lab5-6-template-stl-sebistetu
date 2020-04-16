#include "service.h"
#include "repof.h"

//Constructor
Service::Service() {
}

//Constructor cu parametru
Service::Service(const RepoFile<Produs>& r) {

	repo = r;
}

//Constructor prin copiere
Service::Service(const Service& s) {

	repo = s.repo;
}

//Returneaza media produselor in care apare parametrul ingr ca si ingredient
//in: ingr- char* ingredientul dat
//out: double, media
double Service::medie_ingredient(char* ingr) {
	
	double nr = 0, suma = 0;
	char* p;
	char* n;
	vector<Produs> v = repo.getAll();

	for (int i = 0; i < v.size(); ++i) {

		p = strtok_s(v[i].get_ingrediente(), ",", &n);

		while (p) {

			if (strcmp(p, ingr) == 0) {

				nr++;
				suma += v[i].get_pret();
			}

			p = strtok_s(NULL, ",", &n);
		}
	}

	if (nr)
		return suma / nr;
	else
		return 0;
}

//Returneaza un veztor in care pe fiecare pozitie avem memorate ingredientul si media acestuia
//in: -
//out: vector<pair<char*, double>>, vectorul cerut
vector<pair<char*, double>> Service::get_lista_medii_ingr(){
	
	vector < pair < char*, double > > rez;
	vector <char*> carac;
	vector <Produs> v = repo.getAll();
	char* n;
	char* p;

	for (int j = 0; j < v.size(); ++j) {

		p = strtok_s(v[j].get_ingrediente(), ",", &n);

		while (p) {

			bool ok = true;

			for (int i = 0; i < carac.size(); i++)
				if (strcmp(p, carac[i]) == 0)
					ok = false;

			if (ok) {

				carac.push_back(p);
				double medie = Service::medie_ingredient(p);

				char* ingr = new char[strlen(p) + 1];
				strcpy_s(ingr, strlen(p) + 1, p);
				rez.push_back(make_pair(ingr, medie));
			}

			p = strtok_s(NULL, ",", &n);
		}
	}
	return rez;
}

//Descontructor
Service::~Service() {

}

//Adaugare produs
//in: id: int, p: doube, n: char*, i: char*
//out: true, daca s-a efectuat adaugarea, false altfel
bool Service::addProd(int id, double p, char* n, char* i) {
	
	Produs prd(id, p, n, i);
	return repo.addElem(prd);
}

//Stergere produs
//in: id - int
//out: true, daca s-a efectuat stergerea, false altfel
bool Service::delProd(int id) {

	return repo.deteleElem(id);
}

//Modificare produs
//in: id: int, p: doube, n: char*, i: char*
//out: true, daca s-a efectuat modificarea, false altfel
bool Service::updateProd(int id, double pret, char* n, char* i) {

	Produs p(id, pret, n, i);
	return repo.updateElem(p);
}

//Returneaza lista de produse
//in: -
//out: vectorul de produse
vector<Produs> Service::getAll() {

	return repo.getAll();
}
