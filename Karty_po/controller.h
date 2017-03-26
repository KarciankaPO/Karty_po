#pragma once
#include "Karty.h"
#include <vector>

enum typ_k{karta_standard,karta_plapka,karta_czar,all};

class Karta_controller {
private:
	vector<Karta_standard> buff_stan;
	vector<Karta_plapka> buff_plap;
	vector<Karta_czar> buff_czar;
	int typ;
public:
	Karta_controller(typ_k typ):typ(typ){}
	void typ_zmien(typ_k typ) { this->typ = typ; }
	void szablon() const;
	void czytaj();
	int size()const;

	Karta_standard& at_standard(int n) {
		return buff_stan[n];
	}
	Karta_plapka& at_plap(int n) {
		return buff_plap[n];
	}
	Karta_czar& at_czar(int n) {
		return buff_czar[n];
	}
};