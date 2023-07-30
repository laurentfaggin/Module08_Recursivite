#include <iostream>
#include <sstream>
#include <stdexcept>
#include "compteARebours.h"


/*********** compte a rebours avec valeur depart et valeur de fin  ***************/
void compteARebours_rec(int p_depart, int p_fin) {
	std::cout << p_depart << " ";
	if (p_depart > p_fin) {
		compteARebours_rec(p_depart - 1, p_fin);
	}
}

void compteARebours(int p_depart, int p_fin) {
	if (p_depart < p_fin) {
		int temp = p_depart;
		p_depart = p_fin;
		p_fin = temp;
	}
	compteARebours_rec(p_depart, p_fin);
}

/**************** compte a rebours avec valeur de depart et decrementee de 1 *****************/

void compteARebours_rec(int n) {
	std::cout << n << " ";
	if (n > 0) {
		compteARebours_rec(n - 1);
	}
}

void compteARebours(int n) {
	if (n > 0) {
		compteARebours_rec(n);
	}
}

/**************** compte a rebours avec valeur de depart, de fin, de decrementation  *****************/


void compteARebours_rec(int p_depart, int p_fin, int p_decrementation) {
	std::cout << p_depart << " ";
	if (p_depart < p_fin) {
		int temp = p_depart;
		p_depart = p_fin;
		p_fin = temp;
	}
	if (p_depart > p_fin && p_decrementation <= p_depart - p_fin) {
		compteARebours_rec(p_depart - p_decrementation, p_fin, p_decrementation);
	}
}

void compteARebours(int p_depart, int p_fin, int p_decrementation) {
	compteARebours_rec(p_depart, p_fin, p_decrementation);
}


