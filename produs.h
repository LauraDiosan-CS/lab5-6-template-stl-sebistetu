#pragma once
#include <iostream>
using namespace std;
class Produs {

private:
	int id;
	double pret;
	char* nume;
	char* ingrediente;
public:
	Produs();
	Produs(int, double, char*, char*);
	Produs(const Produs& p);
	~Produs();
	int get_id();
	double get_pret();
	char* get_nume();
	char* get_ingrediente();
	void set_cod(int);
	void set_pret(double);
	void set_nume(char* n);
	void set_ingrediente(char* n);
	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);	
	bool operator!();
	friend ostream& operator<<(ostream& os, const Produs& p);
	friend istream& operator>>(istream& is, Produs& p);
};