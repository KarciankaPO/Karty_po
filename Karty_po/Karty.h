#pragma once
#include <string>
#include <sstream>
#include "Modyfikator.h"
using namespace std;

class Karta {
protected:
	string	nazwa;
	int		frakcja;
	int		ener;
public:
	virtual string info() = 0;
	//
	Karta(string nazwa,int ener,int frakcja):nazwa(nazwa),ener(ener),frakcja(frakcja){}
	string	info_nazwa()  const { return nazwa; }
	string	info_frakcja() const { return frakcja_int(this); }
	string	info_energia() const { stringstream buff; buff << ener; return buff.str(); }

	//
	friend string frakcja_int(const Karta* const);
};

class Karta_plapka: public Karta,protected Modyfikator  {
public:
	Karta_plapka(string nazwa, int ener, int ener_r, int hp_r, int atk_r, int def_r, int frakcja = 0) : Karta(nazwa, ener, frakcja), Modyfikator(ener_r, hp_r, atk_r, def_r) {}
	virtual string info();
};

class Karta_standard : public Karta {
private:
	int hp;
	int atk;
	int def;
	Karta_plapka kp_mod;
public:
	Karta_standard(string nazwa, int ener ,int hp,int atk,int def, int frakcja=0): Karta(nazwa, ener, frakcja),hp(hp),atk(atk),def(def), kp_mod("",0,0,0,0,0) {}
	//info
	virtual string info();
	string info_kp() { return kp_mod.info(); };
};

class Karta_czar :public Karta, protected Modyfikator {
private:
	//info
	virtual string info();
public:
	Karta_czar(string nazwa, int ener, int ener_r, int hp_r, int atk_r, int def_r, int frakcja = 0) : Karta(nazwa, ener, frakcja), Modyfikator(ener_r,hp_r,atk_r,def_r) {}
};