#include <stdexcept>
#include <iostream>
#include "pile_methodes.h"



bool caracteresCorrectementImbriques(std::string p_string) {
	Pile<char> pile;
	bool ok = true;
	for (char c : p_string) {
		if (c == '(' || c == '{' || c == '[') {
			pile.empiler(c);
		}
		else if ((c == ')' && pile.sommet() == '(') ||
			(c == '}' && pile.sommet() == '{') ||
			(c == ']' && pile.sommet() == '['))
		{
			pile.depiler();
		}
		else {
			ok = false;
		}
	}
	if (ok && pile.estPileVide()) {
		ok = true;
	}
	return ok;
}

Pile<char>infixeConvertiEnPostfixe(std::string p_stringInfixe) {
	Pile<char>pilePostfixe;
	Pile<char>pileStach;

	for (char c : p_stringInfixe) {
		int priorite = evaluationPriorite(c);
		if (c == '(' || priorite == 0) {
			pilePostfixe.empiler(c);
		}
		else if (c == ')' && !pilePostfixe.estPileVide()) {
			while (c != '(' && !pileStach.estPileVide()) {
				pilePostfixe.empiler(pileStach.sommet());
				pileStach.depiler();
			}
		}
		else if (priorite > 0 && !pilePostfixe.estPileVide()) {
			pileStach.empiler(c);
		}
		else if (priorite > 0 && priorite < evaluationPriorite(pileStach.sommet())) {
			pilePostfixe.empiler(pileStach.sommet());
			pileStach.depiler();
			pileStach.empiler(c);
		}
		else {
			pileStach.empiler(c);
		}
	}
	while (!pileStach.estPileVide()) {
		pilePostfixe.empiler(pileStach.sommet());
		pileStach.depiler();
	}
	return pilePostfixe;
}



int evaluationPriorite(char p_char) {
	int priorite = 0;
	switch (p_char) {
	case '-':
		priorite = 1;
		break;
	case '+':
		priorite = 2;
		break;
	case '/':
		priorite = 3;
		break;
	case '*':
		priorite = 4;
		break;
	default:
		priorite = 0;
		break;
	}
	return priorite;
}



