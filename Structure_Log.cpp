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
// type Structure_Log::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Structure_Log & Structure_Log::operator = ( const Structure_Log & unStructure_Log )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Structure_Log::Structure_Log ( const Structure_Log & unStructure_Log )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Structure_Log>" << endl;
#endif
} //----- Fin de Structure_Log (constructeur de copie)


Structure_Log::Structure_Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Structure_Log>" << endl;
#endif
} //----- Fin de Structure_Log


Structure_Log::~Structure_Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Structure_Log>" << endl;
#endif
} //----- Fin de ~Structure_Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

