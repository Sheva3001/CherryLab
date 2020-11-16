#include "MyList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	TList M; TList L1; TList L2;
	fromFileToList(M);
	printList(M);
	
	L1L2(M, L1, L2);
	printList(L1);
	printList(L2);
	return 0;
}

