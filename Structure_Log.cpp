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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void newVisit( Log unLog )
{
}

void updateTop10()
{
}

void createGraphe()
{
}

//------------------------------------------------- Surcharge d'opérateurs

Structure_Log & Structure_Log::operator = ( const Structure_Log & unStructure_Log )
{
} 


//-------------------------------------------- Constructeurs - destructeur
Structure_Log::Structure_Log ( const Structure_Log & unStructure_Log )
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


Structure_Log::~Structure_Log ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Structure_Log>" << endl;
#endif
} //----- Fin de ~Structure_Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

