/*************************************************************************
                           Sortie  -  description
                             -------------------
    début                : 27/01/25
    copyright            : (C) 2025 par Maxence
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Sortie> (fichier Sortie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel

#include "Sortie.h"
#include <cstring>
#include <limits>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Sortie::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

statutFlux Sortie::EcritGraphe (string fileChemin )
//Algorithme :
//
{
#ifdef MAP
cout << "Appel de la méthode EcritGraphe de <Sortie>" << endl;
#endif
    ofstream flux;
    flux.open(fileChemin, ios::out);

     if (!flux.is_open())
    {
        return statutFlux::ERREUR_OUVERTURE; // Retourne une erreur si l'ouverture échoue
    }

    
    flux << struct_log->CreateGraphe();
    

    if (!flux) // Vérifie si l'écriture a échoué
    {
        flux.close();
        return statutFlux::ERREUR_ECRITURE;
    }

    flux.close();
    return statutFlux::VALIDE;


} //----- Fin de EcritGraphe

void Sortie::AffichageTop10 ( )
//Algorithme :
//
{
#ifdef MAP
cout << "Appel de la méthode AffichageTop10 de <Sortie>" << endl;
#endif
    
    struct_log->AfficheTop10();
    

} //----- Fin de AffichageTop10


// //------------------------------------------------- Surcharge d'opérateurs (pas utilisé)
// Sortie & Sortie::operator = ( const Sortie & unSortie )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


// //-------------------------------------------- Constructeurs - destructeur (pas utilisé)
// Sortie::Sortie ( const Sortie & unSortie )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Sortie>" << endl;
// #endif
// } //----- Fin de Sortie (constructeur de copie)


Sortie::Sortie( Structure_Log * s )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sortie>" << endl;
#endif

    struct_log = s;

} //----- Fin de Sortie


Sortie::~Sortie ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sortie>" << endl;
#endif
} //----- Fin de ~Sortie


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

