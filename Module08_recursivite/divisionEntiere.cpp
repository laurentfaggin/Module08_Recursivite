#include "divisionEntiere.h"

float divisionEntiere_rec(float p_dividende, float p_diviseur) {

	if (p_dividende > 0 && p_dividende > p_diviseur) {
		return divisionEntiere_rec(p_dividende - p_diviseur, p_diviseur);
	}
}

float divisionEntiere(float p_dividende, float p_diviseur) {
	float result = 1;
	if (result > 0) {
		result = divisionEntiere_rec(p_dividende, p_diviseur);
	}
	return result;
}