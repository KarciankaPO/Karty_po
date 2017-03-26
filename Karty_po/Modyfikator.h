#pragma once

class Modyfikator {
protected:
	int hp_r;
	int atk_r;
	int def_r;
	int ener_r;
public:
	Modyfikator(int ener_r=0, int hp_r=0,int atk_r=0,int def_r=0):ener_r(ener_r),hp_r(hp_r),atk_r(atk_r),def_r(def_r){}
};