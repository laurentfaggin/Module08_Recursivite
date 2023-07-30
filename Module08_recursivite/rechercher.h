#pragma once

int rechercher(const int* p_collection, int p_entierARechercher, int p_tailleDuTableau);

bool recherche(const int* p_collection, int p_entierARechercher, int p_tailleDuTableau);

int compterNombreOccurences(const int* p_collection, int p_valeurATrouver, int p_tailleTableau, bool(*p_recherche)(const int*, int, int));