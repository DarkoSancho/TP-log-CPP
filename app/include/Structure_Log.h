/*************************************************************************
                           Structure_Log  -  description
                             -------------------
    début                : 23/01/2025
    copyright            : (C) 2025 par ttavernier
    e-mail               : timothee.tavernier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Structure_Log> (fichier Structure_Log.h) ----------------
#if ! defined ( Structure_Log_H )
#define Structure_Log_H
#include "Log.h"
#include <string>
#include <map>
#include <unordered_map>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Structure_Log>
//
//
//------------------------------------------------------------------------

class Structure_Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Affiche() const;

    void NewLog( Log & unLog );
    // Mode d'emploi : Met à jour dico_visites avec un nouveau Log
    //
    // Contrat : Si le log ne respecte pas les options (mauvaise heure, mauvaise extension),
    // il ne sera pas pris en compte.
    //

    void UpdateTop10();
    // Mode d'emploi : Met à jour le top 10 des sites les plus visités
    //
    // Contrat :
    //

    void AfficheTop10();
    // Mode d'emploi : Affiche le top 10 des sites les plus visités
    //
    // Contrat :
    //

    void readFile(string nomFichier);

    string CreateGraphe();

    
       
    




//------------------------------------------------- Surcharge d'opérateurs
    Structure_Log & operator = ( const Structure_Log & unStructure_Log );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Structure_Log ( const Structure_Log & unStructure_Log );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Structure_Log(int heure = -1, bool graphe = false, bool exclusions = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Structure_Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //x

    






//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés


multimap<int, string> top10;
unordered_map<string, unordered_map<string, int>> graphe;
unordered_map<string, int> dico_visites;
bool makeGraphe;
int heure_creneau;
bool exclusionExtensions;

};

//-------------------------------- Autres définitions dépendantes de <Structure_Log>

#endif // Structure_Log_H



/*
Méthode de Lectrice à intégrer :
1- Initialisation (ou récupération) de StructLog (stocké, ou non, en attribut)
    - On renseigne notamment l'état des 3 options facultatives
2- Boucle For :
    a- Lecture d'une ligne
    b- Création d'un Log à partir des attributs repérés par la lecture
    c- Ajout de ce Log à Structure_Log
3- Renvoi (ou mise à jour) de la StructLog
*/
