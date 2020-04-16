#include "ui.h"
#include "service.h"
#include <iostream>
#include <vector>
using namespace std;

UI::UI(const Service& s) {
	
	service = s;
}

void UI::afisareMeniu() {

	cout << "1.Adaugare\n";
	cout << "2. Afisare\n";
	cout << "3. Stergere\n";
	cout << "4. Modificare\n";
	cout << "5. Medie ingrediente\n";
	cout << "0. Stop\n";
}

void UI::adaugareProdus() {

	int id;
	double pret;
	char* nume = new char[50];
	char* i = new char[50];
	cout << "\nDati id-ul: ";
	cin >> id;
	cout << "\nDati pretul: ";
	cin >> pret;
	cout << "\nDati numele: ";
	cin >> nume;
	cout << "\nDati ingredientele: ";
	cin >> i;
	cout << '\n';
	bool rez = service.addProd(id, pret, nume, i);

	if (rez)
		cout << "\nAdaugare efetuata cu succes!\n";
	else
		cout << "\nExista un obiect cu acest id!\n";

	delete[] i;
	delete[] nume;
}

void UI::stergereProdus() {

	int id;
	cout << "\nDati id-ul produsului pt stergere: ";
	cin >> id;
	cout << '\n';
	bool rez = service.delProd(id);
	if (rez)
		cout << "\nStergere efectuata cu succes!\n";
	else
		cout << "\nNu exista un obiect cu acest id!\n";
}

void UI::afisareProduse() {

	vector <Produs> lista = service.getAll();

	for (auto i = lista.begin(); i != lista.end(); ++i)
		cout << *i << '\n';
	cout << '\n';

}

void UI::modificareProduse() {

	int id;
	double pret;
	char* nume = new char[50];
	char* i = new char[50];
	cout << "\nDati id-ul : ";
	cin >> id;
	cout << "\nDati pretul nou: ";
	cin >> pret;
	cout << "\nDati numele nou: ";
	cin >> nume;
	cout << "\nDati ingredientele noi: ";
	cin >> i;
	cout << '\n';
	bool rez = service.updateProd(id, pret, nume, i);

	if (rez)
		cout << "\nModificare efetuata cu succes!\n";
	else
		cout << "\nNu exista un obiect cu acest id!\n";

	delete[] i;
	delete[] nume;
}

void UI::medieIngrediente() {

	vector < pair < char*, double > > v = service.get_lista_medii_ingr();

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " : media " << v[i].second << '\n';
}

void UI::run() {

	bool shouldRun = true;
	char op;
	while (shouldRun) {

		afisareMeniu();
		cout << "\nDati operatia: ";
		cin >> op;
		cout << '\n';
		switch (op) {
		case '1':
			adaugareProdus();
			break;
		case '2':
			afisareProduse();
			break;
		case '3':
			stergereProdus();
			break;
		case'4':
			modificareProduse();
			break;
		case '5':
			medieIngrediente();
			break;
		case '0':
			shouldRun = false;
			break;
		default:
			cout << "\nComanda gresita!\n";
			break;
		}
	}
}
