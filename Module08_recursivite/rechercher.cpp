#include "rechercher.h";

int rechercher_rec(const int* p_collection, int p_entierAChercher, int p_tailleDuTableau) {
	if (p_tailleDuTableau < 0) {
		return -1;
	}
	if (p_collection[p_tailleDuTableau - 1] == p_entierAChercher) {
		return p_tailleDuTableau;
	}
	return rechercher_rec(p_collection, p_entierAChercher, p_tailleDuTableau - 1);
}

int rechercher(const int* p_collection, int p_entierAChercher, int p_tailleDuTableau) {
	return rechercher_rec(p_collection, p_entierAChercher, p_tailleDuTableau);
}

//bool recherche_rec(const int* p_collection, int p_valeurATrouver, int p_tailleTableau) {
//	if (p_tailleTableau <= 0) {
//		return false;
//	}
//	if (p_collection[p_tailleTableau - 1] == p_valeurATrouver) {
//		return true;
//	}
//	return recherche_rec(p_collection, p_valeurATrouver, p_tailleTableau - 1);
//}
//
//bool recherche(const int* p_collection, int p_valeurATrouver, int p_tailleTableau) {
//	return recherche_rec(p_collection, p_valeurATrouver, p_tailleTableau);
//}
//
//int compterNombreOccurences_rec(const int* p_collection, int p_valeurATrouver, int p_tailleTableau, bool(*p_recherche)(const int*, int, int)) {
//	if (p_tailleTableau <= 0) {
//		return 0;
//	}
//	int count = compterNombreOccurences_rec(p_collection, p_valeurATrouver, p_tailleTableau - 1, p_recherche);
//	if (p_recherche(p_collection, p_valeurATrouver, p_tailleTableau-1)) {
//		++count;
//	}
//	return count;
//}
//
//int compterNombreOccurences(const int* p_collection, int p_valeurATrouver, int p_tailleTableau, bool(*p_recherche)(const int*, int, int)) {
//	return compterNombreOccurences_rec(p_collection, p_valeurATrouver, p_tailleTableau, p_recherche);
//}
bool recherche_rec(const int* p_collection, int p_valeurATrouver, int p_index) {
    if (p_index < 0) {
        return false;
    }
    if (p_collection[p_index] == p_valeurATrouver) {
        return true;
    }
    return recherche_rec(p_collection, p_valeurATrouver, p_index - 1);
}

bool recherche(const int* p_collection, int p_valeurATrouver, int p_tailleTableau) {
    return recherche_rec(p_collection, p_valeurATrouver, p_tailleTableau - 1);
}

int compterNombreOccurences_rec(const int* p_collection, int p_valeurATrouver, int p_index) {
    if (p_index < 0) {
        return 0;
    }

    int count = compterNombreOccurences_rec(p_collection, p_valeurATrouver, p_index - 1);
    if (p_collection[p_index] == p_valeurATrouver) {
        ++count;
    }
    return count;
}

int compterNombreOccurences(const int* p_collection, int p_valeurATrouver, int p_tailleTableau, bool(*p_recherche)(const int*, int, int)) {
    return compterNombreOccurences_rec(p_collection, p_valeurATrouver, p_tailleTableau - 1);
}

