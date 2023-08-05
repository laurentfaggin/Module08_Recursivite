#pragma once
#include <iostream>
#include <string>
#include "pile.h"
#include "liste.h"



bool caracteresCorrectementImbriques(std::string p_string);
int evaluationPriorite(char p_char);
Pile<char>infixeConvertiEnPostfixe(std::string p_stringInfixe);


