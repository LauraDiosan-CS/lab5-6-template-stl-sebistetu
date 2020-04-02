#include "produs.h"
#include <string.h>

//Constructor
//out: Un produs gol
Produs::Produs() {

	id = 0;
	pret = 0.0;
	nume = NULL;
	ingrediente = NULL;
}

//Constructor cu parametru
//in: i- int, p - int, n - char*, ingr-char*
//out: un produs cu aceste date
Produs::Produs(int i, double p, char* n, char* ingr) {

	id = i;
	pret = p;

	if (n == NULL)
		nume = NULL;
	else {

		nume = new char[strlen(n) + 1];
		strcpy_s(nume, strlen(n) + 1, n);
	}

	if (ingr == NULL)
		ingrediente = NULL;
	else {

		ingrediente = new char[strlen(ingr) + 1];
		strcpy_s(ingrediente, strlen(ingr) + 1, ingr);
	}
}

//Constructr prin copiere
//out: un produs care contine aceleasi date cu cele din parametru
Produs::Produs(const Produs& p){

	id = p.id;
	pret = p.pret;

	if (p.nume == NULL)
		nume = NULL;
	else {

		nume = new char[strlen(p.nume) + 1];
		strcpy_s(nume, strlen(p.nume) + 1, p.nume);
	}

	if (p.ingrediente == NULL)
		ingrediente = NULL;
	else {

		ingrediente = new char[strlen(p.ingrediente) + 1];
		strcpy_s(ingrediente, strlen(p.ingrediente) + 1, p.ingrediente);
	}
}

//Destructor
Produs::~Produs() {

	delete[] nume;
	delete[] ingrediente;
}

// Getter pentru cod
int Produs::get_id() {

	return id;
}

//Getter pentru pret
double Produs::get_pret() {
	return pret;
}

//Getter pentru nume
char* Produs::get_nume() {
	return nume;
}

//Getter pentru ingrediente
char* Produs::get_ingrediente() {
	return ingrediente;
}

 //Setter pentru cod
void Produs::set_cod(int i) {

	id = i;
}

//Setter pentru pret
void Produs::set_pret(double p) {

	pret = p;
}

//Setter pentru nume
void Produs::set_nume(char* n) {

	if (nume)
		delete[] nume;

	if (n == NULL)
		nume = NULL;
	else {

		nume = new char[strlen(n) + 1];
		strcpy_s(nume, strlen(n) + 1, n);
	}
}

//Setter pentru ingrediente
void Produs::set_ingrediente(char* i) {

	if (ingrediente)
		delete[] ingrediente;

	if (i == NULL)
		ingrediente = NULL;
	else {

		ingrediente = new char[strlen(i) + 1];
		strcpy_s(ingrediente, strlen(i) + 1, i);
	}
}

//Operatorul de atribuire
//in: 2 obiecte de tip Produs
//out: noua stare a obiectului this
Produs& Produs::operator=(const Produs& p) {
	
	set_cod(p.id);
	set_pret(p.pret);
	set_nume(p.nume);
	set_ingrediente(p.ingrediente);
	return *this;
}

//Operatorul de egalitate
//in: 2 obiecte de tip Produs
//out: true daca cele 2 sunt egale, false altfel
bool Produs::operator==(const Produs& p) {
	return (id == p.id);
}
