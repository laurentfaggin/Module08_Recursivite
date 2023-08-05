#pragma once
#include "liste.h"

void TriBulles(Liste<int>& tableauATrier);
void TriRapide_rec(Liste<int>& p_tableauATrier, int p_firstIndex, int p_lastIndex);
void TriRapide(Liste<int>& tableauATrier);
int ChoixPivot(Liste<int>& p_valeurs, int p_firstIndex, int p_lastIndex);
int Partitionner(Liste<int>& p_valeurs, int p_firstIndex, int p_lastIndex, int p_pivotIndex);
bool EstTableauTrie(const Liste<int>& p_valeurs);