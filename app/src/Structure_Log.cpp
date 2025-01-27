/*************************************************************************
                         Structure_Log  -  description
                            -------------------
    début                : 23/01/2025
    copyright            : (C) 2025 par ttavernier
    e-mail               : timothee.tavernier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Structure_Log> (fichier Structure_Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

#include "Lectrice.h"

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Structure_Log.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

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

void Structure_Log::AfficheTop10()  
    {
        cout << "Classement des 10 sites les plus visités:\n";
        for (const auto& [nbvisites, site] : top10) {
            cout << "  " << site << " : " << nbvisites << "\n";
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


void Structure_Log::readFile(string nomFichier){
        Lectrice lectrice = Lectrice(nomFichier);
        while (lectrice.getnextLog()){
            Log cur_log = Log(lectrice.getDate(), lectrice.getTime(), lectrice.getActionType(),
                lectrice.getURLTarget(), lectrice.getStatus(), lectrice.getDataSize(),
                lectrice.getclearURLReferer(), lectrice.getIDNavigator());

            NewLog(cur_log);
        }
    }

string Structure_Log::CreateGraphe(){
    // Mode d'emploi : renvoie un string du graphe répresentant les visites du site
    //
    // Contrat : utilisé dans la classe Sortie pour créer le graphe
    //
    ostringstream dotContent;
    dotContent << "digraph {\n";
    unordered_map<string, int> nodeMap;
    int nodeIndex = 0;

    // Map each node to an index
    for (const auto& [node, _] : graphe) {
        if (nodeMap.find(node) == nodeMap.end()) {
            nodeMap[node] = nodeIndex++;
        }
        for (const auto& [neighbor, _] : graphe[node]) {
            if (nodeMap.find(neighbor) == nodeMap.end()) {
                nodeMap[neighbor] = nodeIndex++;
            }
        }
    }

    // Add nodes with labels
    for (const auto& [node, index] : nodeMap) {
        dotContent << "node" << index << " [label=\"" << node << "\"];\n";
    }

    // Add edges with labels
    for (const auto& [node, neighbors] : graphe) {
        for (const auto& [neighbor, weight] : neighbors) {
            dotContent << "node" << nodeMap[node] << " -> node" << nodeMap[neighbor] 
                        << " [label=\"" << weight << "\"];\n";
        }
    }

    dotContent << "}";
    return dotContent.str();
}
    

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
