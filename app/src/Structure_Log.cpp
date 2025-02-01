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
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Structure_Log.h"


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
        UpdateTop10();
        cout << "Classement des 10 sites les plus visités:\n";
       // Copier le top10 dans un vecteur pour le manipuler
        std::vector<std::pair<int, std::string>> reversedTop10(top10.begin(), top10.end());
        
        // Inverser l'ordre
        std::reverse(reversedTop10.begin(), reversedTop10.end());

        int count = 1;
        
        for (const auto& [nbvisites, site] : reversedTop10) {
            cout << count++ << "  " << site << " : " << nbvisites << " hits \n";
        }
    }

void Structure_Log::NewLog(Log & unLog)
{   
    if (((heure_creneau == -1) || (unLog.getHeure() == heure_creneau))&&((exclusionExtensions==false) || (getExtension(unLog.getUrlCible())=="NONE") ||  (getExtension(unLog.getUrlCible()) !="jpeg" && getExtension(unLog.getUrlCible()) !="jpg"&& getExtension(unLog.getUrlCible()) !="gif"&& getExtension(unLog.getUrlCible()) !="js"&& getExtension(unLog.getUrlCible()) !="css"))){ 
      dico_visites[unLog.getUrlCible()] += 1;
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

    // Sort the vector using a lambda function for multi-criteria sorting
    sort(sorted_visits.begin(), sorted_visits.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) {
            return a.first > b.first;  // Sort by visit count in descending order
        }
        return a.second < b.second;   // Sort alphabetically by URL if visit counts are equal
    });

    // Insert the top 10 into the multimap
    int count = 0;
    for (const auto& entry : sorted_visits) {
        if (count >= 10) break;  // Stop after adding 10 entries
        top10.insert({entry.first, entry.second});
        count++;
    }
}



// string Structure_Log::CreateGraphe()
// {   
//     string res;
//     for (const auto& [source, destinations] : graphe) {
//         res += "  " + source + " :\n";
//         for (const auto& [destination, poids] : destinations) {
//             res +=  "    -> " + destination + " : " + "\n";
//         }
//     }
//     return res;

// }

void Structure_Log::readFile(string nomFichier, string nomURL){
        Lectrice lectrice(nomFichier, nomURL);
       
        while (lectrice.getnextLog()){
           
            Log cur_log(lectrice.getDate(), lectrice.getTime(), lectrice.getActionType(),
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

    // Attribution de chaque noeud à un indice distinct
    for (const auto& [node, _] : graphe) {
        if (nodeMap.find(node) == nodeMap.end()) { //Le noeud (début de l'arc) est-il présent déjà dans la structure nodeMap?
            nodeMap[node] = nodeIndex++;
        }
        for (const auto& [neighbor, _] : graphe[node]) { //Le noeud (bout de l'arc) est-il présent déjà dans la structure nodeMap?
            if (nodeMap.find(neighbor) == nodeMap.end()) {
                nodeMap[neighbor] = nodeIndex++;
            }
        }
    }

    // Ajout des noeuds et labels associés à la string
    for (const auto& [node, index] : nodeMap) {
        dotContent << "node" << index << " [label=\"" << node << "\"];\n";
    }

    // Ajout des arcs et poids associés à la string
    for (const auto& [node, neighbors] : graphe) {
        for (const auto& [neighbor, weight] : neighbors) {
            dotContent << "node" << nodeMap[node] << " -> node" << nodeMap[neighbor]
                        << " [label=\"" << weight << "\"];\n";
        }
    }

    dotContent << "}";
    return dotContent.str();

}


//-------------------------------------------- Constructeurs - destructeur
Structure_Log::Structure_Log(const Structure_Log &unStructure_Log)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Structure_Log>" << endl;
#endif
} //----- Fin de Structure_Log (constructeur de copie)

Structure_Log::Structure_Log(bool graphe, bool exclusions, int heure)
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


string Structure_Log::getExtension(string URL) {
    size_t pos = URL.rfind('.');

    if (pos == string::npos || pos == 0) {
        return "NONE";
    }

    return URL.substr(pos+1);  
}