/*************************************************************************
                           Sortie  -  description
                             -------------------
    début                : 27/01/25
    copyright            : 2025 par Maxence
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Sortie> (fichier Sortie.h) ----------------
#if ! defined ( Sortie_H )
#define Sortie_H

//--------------------------------------------------- Interfaces utilisées
#include "Structure_Log.h"
//------------------------------------------------------------- Constantes
enum class statutFlux
{
    VALIDE,
    ERREUR_OUVERTURE,
    ERREUR_ECRITURE
};
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sortie>
// Classe qui s'occupe des sorties du programme: le top 10 des sites les plus visités et/ou écriture sur un fichiers un graphe des logs
//
//------------------------------------------------------------------------

class Sortie 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void AffichageTop10();
    // Mode d'emploi : affiche le top 10 des sites les plus visités des logs contenu dans la sda de structure logs
    //
    // Contrat :
    //

    statutFlux EcritGraphe(string fileChemin);
    // Mode d'emploi : écrit sur un fichier le graphe répresentant les logs 
    //
    // Contrat :
    //



// //------------------------------------------------- Surcharge d'opérateurs (pas utilisé)
//     Sortie & operator = ( const Sortie & unSortie );
//     // Mode d'emploi :
//     //
//     // Contrat :
//     //


//-------------------------------------------- Constructeurs - destructeur
    // Sortie ( const Sortie & unSortie ); (pas utilisé)
    // // Mode d'emploi (constructeur de copie) :
    // //
    // // Contrat :
    // //

    Sortie ( Structure_Log * );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sortie ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private:

    Structure_Log * struct_log;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Sortie>

#endif // Sortie_H

