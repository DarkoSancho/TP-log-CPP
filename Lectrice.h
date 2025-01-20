/*************************************************************************
                           Lectrice  -  Lis un log (format str) et en sort les information
                                        + Donne le prochain log
                             -------------------
    début                : 20/02/2025
    copyright            : (C) 2025 par tsanchez
    e-mail               : tom.sanchez@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Lectrice> (fichier Lectrice.h) ----------------
#if ! defined ( LECTRICE_H )
#define LECTRICE_H

using namespace std;
#include <iostream>
#include <string>
#include <fstream>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lectrice>
//Traduire les informations d'un log en langage humain
//Donner le prochain log du fichier après un log 
//------------------------------------------------------------------------

class Lectrice 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Lectrice ( const Lectrice & uneLectrice );
    // Mode d'emploi (constructeur de copie) :
    //Constructeur de copie par défault
    // Contrat :
    //

    Lectrice ( );
    // Mode d'emploi :
    //COnstructeur par défault
    // Contrat :
    //

    Lectrice( ofstream& File);
    //Mode d'emploi :
    //COnstructeur à partir d'un fichier .log

    virtual ~Lectrice ( );
    // Mode d'emploi :
    //Destructeur par défault de la classe + fermetur du fichier
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected: 
//----------------------------------------------------- Méthodes protégées
// NA: penser à mettre la classe Log comme amie pour accéder aux données protected.

    string getnextLog();
    // Mode d'emploi :
    //Pour parcourir le fichier.log, nous donne le prochain log ous forme str
    // Contrat :
    //

    string getIPEmet(string sLog);
    // Mode d'emploi :
    //Donne l'adresse IP de l'émeteur
    // Contrat :
    //

    string getTime(string sLog);
    // Mode d'emploi :
    //Donne l'heure de l'émition (D/M/Y:h:mn:s delta GMT)
    // Contrat :
    //

    string getURLTarget(string sLog);
    // Mode d'emploi :
    //Donne l'URL nettoyée 
    // Contrat :
    //

    int getstatus(string sLog);
    // Mode d'emploi :
    //Donne le status du code HTTP 
    // Contrat :
    //

    int getWeightData(string sLog);
    // Mode d'emploi :
    //Donne la quantité de donnée transférées au serveur distant
    // Contrat :
    // 

    string getURLReferer(string sLog);
    // Mode d'emploi :
    //Donne l'URL du referer
    // Contrat :
    //

    string getNavClient(string sLog);
    // Mode d'emploi :
    //Donne l'identificateur du client navigateur
    // Contrat :
    //
//----------------------------------------------------- Attributs protégés

    ofstream File; //Fichier .log
    string currentLog; //Log sur lequel nous sommes placé pour le parcours du .log
};



#endif  // LECTRICE_H

