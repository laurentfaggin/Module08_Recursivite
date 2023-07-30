
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "compteARebours.h"
#include "divisionEntiere.h"
#include "fibonacci.h"

std::string dureeLisibleParHumain(long long p_ns,
    bool p_ignoreNs, bool p_ignoreUs, bool p_ignoreMs) {
    constexpr long long Ns = 1;
    constexpr long long UsNs = 1'000 * Ns;
    constexpr long long MsNs = 1'000 * UsNs;
    constexpr long long SNs = 1'000 * MsNs;
    constexpr long long MNs = 60 * SNs;
    constexpr long long HNs = 60 * MNs;
    constexpr long long jourNs = 24 * HNs;

    int jours = static_cast<int>(p_ns / jourNs);
    p_ns -= jours * jourNs;
    int heures = static_cast<int>(p_ns / HNs);
    p_ns -= heures * HNs;
    int minutes = static_cast<int>(p_ns / MNs);
    p_ns -= minutes * MNs;
    int secondes = static_cast<int>(p_ns / SNs);
    p_ns -= secondes * SNs;
    int millisecondes = static_cast<int>(p_ns / MsNs);
    p_ns -= millisecondes * MsNs;
    int microsecondes = static_cast<int>(p_ns / UsNs);
    p_ns -= microsecondes * UsNs;
    int nanosecondes = static_cast<int>(p_ns);

    std::stringstream ss;
    std::string prefixText = "";

    if (jours) {
        ss << std::setw(2) << jours << " jour(s), ";
    }
    if (heures) {
        ss << std::setw(2) << heures << " heure(s), ";
    }
    if (minutes) {
        ss << std::setw(2) << minutes << " minute(s), ";
    }
    if (secondes || (p_ignoreMs && p_ignoreUs && p_ignoreNs)) {
        ss << std::setw(2) << secondes << " seconde(s)";
        prefixText = ", ";
    }

    if (!p_ignoreMs) {
        ss << std::setw(3) << prefixText << millisecondes << " milliseconde(s)";
        prefixText = ", ";
        if (!p_ignoreUs) {
            ss << std::setw(3) << prefixText << microsecondes << " microsecond(s)";
            prefixText = ", ";
            if (!p_ignoreNs) {
                ss << std::setw(3) << prefixText << nanosecondes << " nanosecond(s)";
            }
        }
    }

    return ss.str();
}

int main()
{/*
    compteARebours(10, 5);
    std::cout<<std::endl;
    compteARebours(10);
    std::cout << std::endl;
    compteARebours(100, 0, 10);
    std::cout << std::endl;
    float resultat = divisionEntiere(99, 26);
    std::cout << "resultat division: " << resultat << std::endl;*/
    int fibonacci = suiteDeFibonacci(10);
    std::cout << fibonacci << std::endl;
    using namespace std::chrono;

    time_point<high_resolution_clock> debut = high_resolution_clock::now();
    std::cout << "suiteDeFinobacci(10) = " << suiteDeFibonacci(10) << std::endl << std::endl;
    time_point<high_resolution_clock> fin = high_resolution_clock::now();

    nanoseconds tempsPasseNs = fin - debut;
    std::cout << "Duree du calcul (ns) : " << tempsPasseNs.count() << std::endl;

    std::cout << "Duree du calcul : " << dureeLisibleParHumain(tempsPasseNs.count(), true, true, true) << std::endl;

    debut = high_resolution_clock::now();
    std::cout << "suiteDeFinobacci(40) = " << suiteDeFibonacci(40) << std::endl << std::endl;
    fin = high_resolution_clock::now();

    tempsPasseNs = fin - debut;
    std::cout << "Duree du calcul (ns) : " << tempsPasseNs.count() << std::endl;

    std::cout << "Duree du calcul : " << dureeLisibleParHumain(tempsPasseNs.count(), true, true, true) << std::endl;

    
}
