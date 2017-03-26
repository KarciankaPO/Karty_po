#include "Karty.h"
#include <sstream>

string frakcja_int(const Karta* frakcja) {
	if (frakcja->frakcja == 0) { return "Frakcja 1"; }
	else if (frakcja->frakcja == 1) { return "Frakcja 1"; };
	return "brak frakcji";
}

string Karta_plapka::info() {
	stringstream buff;
	buff << "Typ: Karta p³apka"<<endl<<
		"Nazwa: " << nazwa << endl <<
		"Energia: " << ener << endl <<
		"Frakcja: " << frakcja << "\n\nModyfikatory ujemne karty_standard:\n" <<
		"Hp-:" << hp_r << endl <<
		"Atk-:" << atk_r << endl <<
		"Def-:"<<def_r;
	return buff.str();
 }

string Karta_standard::info() {
	stringstream buff;
	buff << "Typ: Karta standard" << endl <<
		"Nazwa: " << nazwa << endl <<
		"Energia: " << ener << endl <<
		"Frakcja: " << frakcja << endl <<
		"Hp:" << hp << endl <<
		"Atk:" << atk << endl <<
		"Def:" << def;
	return buff.str();
}

string Karta_czar::info() {
	stringstream buff;
	buff << "Typ: Karta czar" << endl <<
		"Nazwa: " << nazwa << endl <<
		"Energia: " << ener << endl <<
		"Frakcja: " << frakcja << "\n\nModyfikatory ujemne karty_czar:\n" <<
		"Hp-:" << hp_r << endl <<
		"Atk-:" << atk_r << endl <<
		"Def-:" << def_r;
	return buff.str();
}