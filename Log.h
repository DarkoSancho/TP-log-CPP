/*************************************************************************
                           Log  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ----------------
#if ! defined ( Log_H )
#define Log_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Log ( const Log & unLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string date; //Autre type?
int heure;
string type_action;
string url_cible;
int status;
int taille_reponse;
string referer;
string id_navigateur;

};

//-------------------------------- Autres définitions dépendantes de <Log>

#endif // Log_H

