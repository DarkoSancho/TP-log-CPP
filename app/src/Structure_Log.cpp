/*************************************************************************
                         Structure_Log  -  description
                            -------------------
    début                : 23/01/2025
    copyright            : (C) 2025 par ttavernier
    e-mail               : timothee.tavernier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Structure_Log> (fichier Structure_Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Structure_Log.h"
#include <unordered_map>
#include <vector>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Structure_Log::Affiche() const {
        cout << "Contenu de dico_visites:\n";
        for (const auto& [site, visites] : dico_visites) {
            cout << "  " << site << " : " << visites << "\n";
        }

        cout << "\nContenu de graphe:\n";
        for (const auto& [source, destinations] : graphe) {
            cout << "  " << source << " :\n";
            for (const auto& [destination, poids] : destinations) {
                cout << "    -> " << destination << " : " << poids << "\n";
            }
        }
    }

void Structure_Log::NewLog(Log & unLog)
{
    if ( (heure_creneau == -1 || unLog.getHeure() == heure_creneau)){ //Rajouter && condition_extension pour check la validité de l'extension
      dico_visites[unLog.getUrlCible()] += 1;
      //if (makeGraphe) //A eventuellement insérer avant la ligne qui suit
      graphe[unLog.getReferer()][unLog.getUrlCible()] += 1;
    }
}

void Structure_Log::UpdateTop10()
{
    // Clear the top10 before updating
    top10.clear();
    
    // Create a vector of pairs (visit_count, url) from dico_visites
    vector<pair<int, string>> sorted_visits;
    for (const auto& entry : dico_visites) {
        sorted_visits.push_back({entry.second, entry.first});
    }
    
    // Sort the vector based on visit count (descending order)
    sort(sorted_visits.rbegin(), sorted_visits.rend());

    // Insert the top 10 into the multimap
    int count = 0;
    for (const auto& entry : sorted_visits) {
        if (count >= 10) break;  // Stop after adding 10 entries
        top10.insert({entry.first, entry.second});
        count++;
    }
}

string Structure_Log::CreateGraphe()
{   
    string res;
    for (const auto& [source, destinations] : graphe) {
        res += "  " + source + " :\n";
        for (const auto& [destination, poids] : destinations) {
            res +=  "    -> " + destination + " : " + "\n";
        }
    }
    return res;

}

//------------------------------------------------- Surcharge d'opérateurs

Structure_Log &Structure_Log::operator=(const Structure_Log &unStructure_Log)
{
}

//-------------------------------------------- Constructeurs - destructeur
Structure_Log::Structure_Log(const Structure_Log &unStructure_Log)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Structure_Log>" << endl;
#endif
} //----- Fin de Structure_Log (constructeur de copie)

Structure_Log::Structure_Log(int heure, bool graphe, bool exclusions)
{
#ifdef MAP
    cout << "Appel au constructeur de <Structure_Log>" << endl;
#endif
    heure_creneau = heure;
    makeGraphe = graphe;
    exclusionExtensions = exclusions;

} //----- Fin de Structure_Log

Structure_Log::~Structure_Log()
{
#ifdef MAP
    cout << "Appel au destructeur de <Structure_Log>" << endl;
#endif
} //----- Fin de ~Structure_Log

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
