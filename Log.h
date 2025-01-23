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

//Includes persos
using namespace std;


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

//Getters (si nécessaires)
    const string& getDate() const { return date; }             // Retourne une référence constante
    int getHeure() const { return heure; }                     // Retourne une copie (type primitif)
    const string& getTypeAction() const { return type_action; } // Retourne une référence constante
    const string& getUrlCible() const { return url_cible; }    // Retourne une référence constante
    int getStatus() const { return status; }                   // Retourne une copie
    int getTailleReponse() const { return taille_reponse; }     // Retourne une copie
    const string& getReferer() const { return referer; }       // Retourne une référence constante
    const string& getIdNavigateur() const { return id_navigateur; }
//Avantage : modification non permise (on fournit const)
//Inconvénient : tout le monde peut l'utiliser, contrairement à friend


//------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Log ( const Log & unLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log(const string& date, int heure, const string& type_action,
        const string& url_cible, int status, int taille_reponse,
        const string& referer, const string& id_navigateur)
        : date(date), heure(heure), type_action(type_action), url_cible(url_cible),
          status(status), taille_reponse(taille_reponse), referer(referer),
          id_navigateur(id_navigateur) {};
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
