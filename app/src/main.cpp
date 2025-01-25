#include <iostream>
#include "Log.h"
#include <string>
#include <fstream>
#include "Lectrice.h"
#include "Structure_Log.h"

using namespace std;

int test_logs() {
    // Crée objets Log
    Log log1("2025-01-23", 14, "GET", "/home", 200, 1024, "http://example.com", "Mozilla/5.0");
    Log log2("2025-01-23", 16, "GET", "/home", 200, 1024, "http://example2.com", "Mozilla/5.0");
    Log log3("2025-01-23", 16, "GET", "/home", 200, 1024, "http://example.com", "Mozilla/5.0");
    Log log4("2025-01-23", 14, "GET", "/http://example2.com", 200, 1024, "http://example.com", "Mozilla/5.0");

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
    cout << "Création de structureLog et ajouts des logs" << endl;
    Structure_Log structureLog; //mettre structureLog(16) pour une heure spécifique
    structureLog.NewLog(log1);
    structureLog.NewLog(log2);
    structureLog.NewLog(log3);
    structureLog.NewLog(log4);

    cout << "Affichage de structLog" << endl;
    structureLog.Affiche();



    return 0;
}

int test_lectrice(){

    Lectrice L;
    cout<<L.getclearURLReferer()<<endl;
}

int main() {
  test_lectrice();
  return 0;
}

//Chemin : /home/jguedira/INSA_3A/C++/TP-log-CPP_v1
