#include "controller.h"
#include <fstream>
#include <iostream>
using namespace std;

void Karta_controller::szablon() const {

	if (typ == karta_standard || typ==all) {
		ofstream plik("karty_standard.huj");
		if (!plik) { return; }
		else {
			plik << "Nazwa = _nazwa_" << endl <<
				"Energia(koszt) = _ener_" << endl <<
				"Atk = _atk_" << endl <<
				"HP = _def_" << endl <<
				"Def = _def_"<<endl;
		}
		plik.close();
	}
	if (typ == karta_plapka || typ==all) {
		ofstream plik("karty_plapka.huj");
		if (!plik) { return; }
		else {
			plik << "Nazwa = _nazwa_" << endl <<
				"Energia(koszt) = _ener_" << endl <<
				"Energia(mod) = ener_r"<<endl<<
				"Atk(mod) = _atk_r_" << endl <<
				"HP(mod) = _def_r_" << endl <<
				"Def(mod) = _def_r_"<<endl;
		}
		plik.close();
	}
	if (typ == karta_czar || typ == all) {
		ofstream plik("karty_czar.huj");
		if (!plik) { return; }
		else {
			plik << "Nazwa = _nazwa_" << endl <<
				"Energia(koszt) = _ener_" << endl <<
				"Energia(mod) = ener_r" << endl <<
				"Atk(mod) = _atk_r_" << endl <<
				"HP(mod) = _def_r_" << endl <<
				"Def(mod) = _def_r_"<<endl;
		}
		plik.close();
	}
}

void Karta_controller::czytaj() {

	if (typ == karta_standard || typ == all) {
		ifstream plik("karty_standard.huj");
		if (!plik) { return; }
		else {
			string buff, imie;
			int ener, atk, hp, def;

				plik >> buff;
			while (!plik.eof()) {
				//
				
				plik >> buff;
				plik >> buff;
				imie = buff;
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				ener = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				atk = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				hp = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				def = stoi(buff);

				Karta_standard buff_standard(imie, ener, hp, atk, def);
				buff_stan.push_back(buff_standard);
				plik >> buff;
			}
		}
		plik.close();
	}

	if (typ == karta_plapka || typ == all) {
		ifstream plik("karty_standard.huj");
		if (!plik) { return; }
		else {
			string buff, imie;
			int ener,ener_r, atk_r, hp_r, def_r;

			plik >> buff;
			while (!plik.eof()) {
				//

				plik >> buff;
				plik >> buff;
				imie = buff;
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				ener = stoi(buff);
				//
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				ener_r = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				atk_r = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				hp_r = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				def_r = stoi(buff);

				Karta_plapka buff_plapka(imie,ener, ener_r, hp_r, atk_r, def_r);
				buff_plap.push_back(buff_plapka);
				plik >> buff;
			}
		}
		plik.close();
	}
	if (typ == karta_czar || typ == all) {
		ifstream plik("karty_standard.huj");
		if (!plik) { return; }
		else {
			string buff, imie;
			int ener, ener_r, atk_r, hp_r, def_r;

			plik >> buff;
			while (!plik.eof()) {
				//

				plik >> buff;
				plik >> buff;
				imie = buff;
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				ener = stoi(buff);
				//
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				ener_r = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				atk_r = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				hp_r = stoi(buff);
				//
				plik >> buff;
				plik >> buff;
				plik >> buff;
				def_r = stoi(buff);

				Karta_czar buff_cza(imie, ener, ener_r, hp_r, atk_r, def_r);
				buff_czar.push_back(buff_cza);
				plik >> buff;
			}
		}
		plik.close();
	}
}

int Karta_controller::size() const {
	if (typ == karta_standard) { return buff_stan.size(); }
	if (typ == karta_plapka) { return buff_plap.size(); }
	if (typ == karta_czar) { return buff_czar.size(); }
	return buff_stan.size() + buff_plap.size() + buff_czar.size();
}