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
const string FileName ="/TP-log-CPP/app/Fichier.log";

const char SEPLOG = '\n'; // Char qui sépare 2 logs

const string localURL= "http://intranet-if.insa-lyon.fr";
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

// NA: penser à mettre la classe Log comme amie pour accéder aux données protected.
    string getCurrentLog();

    bool getnextLog();
    // Mode d'emploi :
    //Pour parcourir le fichier.log, nous donne le prochain log ous forme str
    // Contrat :
    //

    string getIPEmet();
    // Mode d'emploi :
    //Donne l'adresse IP de l'émeteur
    // Contrat :
    //

    string getTime();
    // Mode d'emploi :
    //Donne l'heure de l'émition (D/M/Y:h:mn:s delta GMT)
    // Contrat :
    //

    string getURLTarget();
    // Mode d'emploi :
    //Donne l'URL nettoyée 
    // Contrat :
    //


    string getURLReferer();
    // Mode d'emploi :
    //Donne l'URL du referer
    // Contrat :
    //

    string getclearURLReferer();
    // Mode d'emploi :
    //Donne l'URL du referer sans base de l'URL si elle est locale
    // Contrat :
    //

    string getActionType();
    // Mode d'emploi :
    //Donne le type d'action
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    Lectrice();
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

//----------------------------------------------------- Attributs protégés
    ifstream file;
    string currentLog; //Log sur lequel nous sommes placé pour le parcours du .log
};



#endif  // LECTRICE_H

