//#include <string.h>
//
////Constructor
//Repo::Repo() {
//
//	nr_produse = 0;
//}
// //Destructor
//Repo::~Repo() {
//
//}
//
////Adaugare produs
////in: un produs
////out: true daca s-a efectuat modificarea, false altfel
//bool Repo::addElem(T& p) {
//
//	for (int i = 0; i < nr_produse; ++i)
//		if (p.get_id() == produse[i].get_id())
//			return false;
//
//	produse[nr_produse++] = p;
//	return true;
//}
//
////Returneaza prin parametru lista de produse si numarul de produse
//void Repo::getAll(Produs lista[], int& lung) {
//
//	for (int i = 0; i < nr_produse; ++i)
//		lista[i] = produse[i];
//	lung = nr_produse;
//}
//
////Returneaza prdusul cu id-ul din parametru
////in: id-int
////out: produsul cu idul dat
//Produs Repo::getById(int id) {
//
//	for (int i = 0; i < nr_produse; ++i)
//		if (id == produse[i].get_id())
//			return produse[i];
//	return Produs(0, 0, NULL, NULL);
//}
//
////Sterge un produs dupa id
////in: id, int
////out: true, daca s-a efectuat stergerea, false altfel
//bool Repo::deteleElem(int id) {
//
//	for (int i = 0; i < nr_produse; ++i)
//		if (id == produse[i].get_id()) {
//			for (int j = i; j < nr_produse - 1; ++j)
//				produse[j] = produse[j + 1];
//			nr_produse--;
//			return true;
//		}
//	return false;
//}
//
////Modifica un produs dupa id
////in: p, produsul modificat
////out: true, daca s-a efectuat modificare, false altfel
//bool Repo::updateElem(Produs& p) {
//
//	for (int i = 0; i < nr_produse; ++i)
//		if (produse[i].get_id() == p.get_id()) {
//			produse[i] = p;
//			return true;
//		}
//	return false;
//}