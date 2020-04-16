#include "test.h"
#include "service.h"
#include "ui.h"
#include "repo.h"
#include "repof.h"

int main() {

	test_produs();
	test_repo(); 
	test_repo_file();
	test_service();
	RepoFile<Produs> repo("produs.txt");
	Service service(repo);
	UI ui(service);
	ui.run();
	return 0;
}