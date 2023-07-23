#include <iostream>
#include <sstream>
#include "compteARebours.h"

void compteARebours_rec(int p_depart, int p_fin) {
	std::cout << p_depart << " ";
	if (p_depart > p_fin) {
		compteARebours_rec(p_depart - 1, p_fin);
	}
}


void compteARebours(int p_depart, int p_fin) {
	compteARebours_rec(p_depart, p_fin);
}


void compteARebours_rec(int n) {
	std::cout << n << " ";
	if (n >0) {
		compteARebours_rec(n - 1);
	}
}

void compteARebours(int n) {
	if (n > 0) {
		compteARebours_rec(n);
	}
}