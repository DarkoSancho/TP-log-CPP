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
    void Ajoute ( Log unLog );
    // Mode d'emploi : Met à jour les structures de données avec la Log en paramètre
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

// struct ? getTop10();
// Mode d'emploi : Méthode qui crée le classement ordonné des 10 sites les plus visités
// à partir de son attribut dico_visites (éventuellement avec méthode map de la prof)
//      - soit en décla d'amitié à sortie, soit en public (plutôt ça je pense, à voir)
//----------------------------------------------------- Attributs protégés

/*
graphe = unordered_map :
- clé : string adresse_site
- valeur : unordered map = voisins
        - clé : string nom_voisin
        - valeur : nb_liens


dico_visites = unoredered_map :
- clé : string nom_site
- valeur : nb_visites
*/

bool makeGraphe;
bool heure_creneau;
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

