#include <iostream>
#include "Log.h"
//#include "Structure_Log.h"

using namespace std;

int main() {
    // Crée un objet Log
    Log log1("2025-01-23", 14, "GET", "/home", 200, 1024, "http://example.com", "Mozilla/5.0");

    // Affiche les informations du log
    cout << "Date: " << log1.getDate() << endl;
    cout << "Heure: " << log1.getHeure() << endl;
    cout << "Type d'action: " << log1.getTypeAction() << endl;
    cout << "URL cible: " << log1.getUrlCible() << endl;
    cout << "Statut: " << log1.getStatus() << endl;
    cout << "Taille de la réponse: " << log1.getTailleReponse() << " octets" << endl;
    cout << "Referer: " << log1.getReferer() << endl;
    cout << "Navigateur: " << log1.getIdNavigateur() << endl;

    // Crée une instance de Structure_Log et ajoute le log
    /*
    Structure_Log structureLog;
    structureLog.Ajoute(log1);

    cout << "Le log a été ajouté à Structure_Log avec succès." << endl;
    */
    return 0;
}

//Chemin : /home/jguedira/INSA_3A/C++/TP-log-CPP
