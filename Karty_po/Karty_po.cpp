// Karty_po.cpp: Okre�la punkt wej�cia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Karty.h"
#include "controller.h"
#include <iostream>
int main()
{
	setlocale(LC_ALL, "");
	Karta_standard test("TEST", 10, 10, 4, 5);
	Karta_controller controller(all);
	controller.czytaj();
	

	cout << controller.at_plap(0).info()<<endl<< endl;
	cout << "liczba element�w w tablicach: " << controller.size()<<endl;
	controller.typ_zmien(karta_czar);
	cout<<"liczba element�w w tablicy czar: "<<controller.size();
	getchar();
    return 0;
}

