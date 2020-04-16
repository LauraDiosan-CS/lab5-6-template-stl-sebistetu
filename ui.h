#pragma once
#include "service.h"
#include "ui.h"

class UI {

private:
	Service service;
public:
	UI(const Service& s);
	void afisareMeniu();
	void adaugareProdus();
	void stergereProdus();
	void afisareProduse();
	void modificareProduse();
	void medieIngrediente();
	void run();
};