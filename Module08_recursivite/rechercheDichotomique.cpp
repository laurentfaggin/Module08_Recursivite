#include "rechercheDichotomique.h"
#include "liste.h"





/********************* TRI BULLES **************************/
void TriBulles(Liste<int>& tableauATrier) {
    int lastValue = 0;
    bool estPermute = true;
    int indexMax = tableauATrier.nombreDElement();

    while (estPermute) {
        estPermute = false;
        for (int i = 0; i < indexMax - 1; i++) {
            if (tableauATrier.obtenir(i + 1) < tableauATrier.obtenir(i)) {
                lastValue = tableauATrier.obtenir(i + 1);
                tableauATrier.definir(i + 1, tableauATrier.obtenir(i));
                tableauATrier.definir(i, lastValue);
                estPermute = true;
            }
        }
        indexMax = indexMax - 1;
    }
}

/********************     TRI RAPIDE ***************************/
void TriRapide_rec(Liste<int>& p_tableauATrier, int p_firstIndex, int p_lastIndex) {
    int pivotIndex = 0;
    if (p_firstIndex < p_lastIndex) {
        pivotIndex = ChoixPivot(p_tableauATrier, p_firstIndex, p_lastIndex); 
        pivotIndex = Partitionner(p_tableauATrier, p_firstIndex, p_lastIndex, pivotIndex);
        TriRapide_rec(p_tableauATrier, p_firstIndex, pivotIndex - 1);
        TriRapide_rec(p_tableauATrier, pivotIndex + 1, p_lastIndex);
    }
}

void TriRapide(Liste<int>& tableauATrier) {
    TriRapide_rec(tableauATrier, 0, tableauATrier.nombreDElement() - 1);
}

int ChoixPivot(Liste<int>& p_valeurs, int p_firstIndex, int p_lastIndex) {
    return p_firstIndex;
}

int Partitionner(Liste<int>& p_valeurs, int p_firstIndex, int p_lastIndex, int p_pivotIndex) {
    int lastValue = 0;
    int valeurPivot = p_valeurs.obtenir(p_pivotIndex);
    int nextPivotIndex = p_firstIndex;

    p_valeurs.definir(p_pivotIndex, p_valeurs.obtenir(p_lastIndex));
    p_valeurs.definir(p_lastIndex, valeurPivot);

    for (int i = p_firstIndex; i < p_lastIndex; i++) {
        if (p_valeurs.obtenir(i) <= valeurPivot) {
            lastValue = p_valeurs.obtenir(nextPivotIndex);
            p_valeurs.definir(nextPivotIndex, p_valeurs.obtenir(i));
            p_valeurs.definir(i, lastValue);
            nextPivotIndex = nextPivotIndex + 1;
        }
    }
    lastValue = p_valeurs.obtenir(nextPivotIndex);
    p_valeurs.definir(nextPivotIndex, p_valeurs.obtenir(p_lastIndex));
    p_valeurs.definir(p_lastIndex, lastValue);

    return nextPivotIndex;
}

bool EstTableauTrie(const Liste<int>& p_valeurs) {
    bool estTrie = true;
    for (int i = 0; i < p_valeurs.nombreDElement() - 1; i++) {
        if (p_valeurs.obtenir(i) > p_valeurs.obtenir(i + 1)) {
            estTrie = false;
            break;
        }
    }
    return estTrie;
}

bool RechercheDichotomique(const Liste<int>& tableauTrie, int elementRecherche) {
    int debut = 0;
    int fin = tableauTrie.nombreDElement() - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;
        int valeurMilieu = tableauTrie.obtenir(milieu);

        if (valeurMilieu == elementRecherche) {
            return true; 
        }
        else if (valeurMilieu < elementRecherche) {
            debut = milieu + 1; 
        }
        else {
            fin = milieu - 1; 
        }
    }

    return false; 
}