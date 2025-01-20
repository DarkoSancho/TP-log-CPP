/*************************************************************************
                           Structure_Log  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Structure_Log> (fichier Structure_Log.h) ----------------
#if ! defined ( Structure_Log_H )
#define Structure_Log_H

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


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

    Structure_Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Structure_Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Structure_Log>

#endif // Structure_Log_H

