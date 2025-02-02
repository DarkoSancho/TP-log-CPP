#include <iostream>
#include "Log.h"
#include <string>
#include <fstream>
#include "Lectrice.h"
#include "Structure_Log.h"
#include "Sortie.h"

using namespace std;

int getHeure(string );
void messageErreur();

int test_logs() {
    // Crée objets Log
    Log log1("2025-01-23", 14, "GET", "/home", 200, 1024, "http://example.com", "Mozilla/5.0");
    Log log2("2025-01-23", 16, "GET", "/home", 200, 1024, "http://example2.com", "Mozilla/5.0");
    Log log3("2025-01-23", 16, "GET", "/home", 200, 1024, "http://example.com", "Mozilla/5.0");
    Log log4("2025-01-23", 14, "GET", "/http://example2.com", 200, 1024, "http://example.com", "Mozilla/5.0");

    // Affiche les informations du log
    cout << "Date: " << log1.getDate() << endl;
    cout << "Heure: " << log1.getHeure() << endl;
    cout << "Type d'action: " << log1.getTypeAction() << endl;
    cout << "URL cible: " << log1.getUrlCible() << endl;
    cout << "Statut: " << log1.getStatus() << endl;
    cout << "Taille de la réponse: " << log1.getTailleReponse() << " octets" << endl;
    cout << "Referer: " << log1.getReferer() << endl;
    cout << "Navigateur: " << log1.getIdNavigateur() << endl;

    // Crée une instance de Structure_Log et ajoute le log
    cout << "Création de structureLog et ajouts des logs" << endl;
    Structure_Log structureLog; //mettre structureLog(16) pour une heure spécifique
    structureLog.NewLog(log1);
    structureLog.NewLog(log2);
    structureLog.NewLog(log3);
    structureLog.NewLog(log4);

    structureLog.UpdateTop10();
    structureLog.AfficheTop10();

    cout << "Affichage de structLog" << endl;
    structureLog.Affiche();



    return 0;
}





int main(int argc, char** argv)
{
    bool argsValid = true;

    bool faireGraph = false;
    string nomGraphe;

    bool nomLogPres = false;
    string nomLog;

    bool URL_LocalPre = false;
    string URL_Local;

    bool exclusion = false;

    bool heurePresent;
    int heure=-1;


    // Parcourir les arguments
    for (int i = 1; i < argc && argsValid; i++) // i=0 est le nom de la méthode
    {
        string argCurrent = argv[i];

        if (argCurrent.empty())
        {
            argsValid = false;
        }

        if (argCurrent == "-g")
        {
            if (i == argc - 1)
            {
                argsValid = false;
                cerr << "Paramètre non valide pour l'option -g : aucun paramètre "<< endl;
                messageErreur();
            }
            else
            {
                string nextArg = argv[++i ];
                // Vérifier si nextArg est un fichier valide, ou gérer l'option -g
                if (nextArg[0] == '-') // Si c'est une autre option, afficher une erreur
                {
                    argsValid = false;
                    cerr << "Paramètre attendu pour -g, mais obtenu : " << nextArg  << endl;
                    messageErreur();
                }
                else
                {
                    nomGraphe = argv[i ];
                    faireGraph = true;
                }
            }
        }
        else if (argCurrent == "-e")
        {
          exclusion = true;
        }
        else if (argCurrent == "-t")
        {
            if (i == argc - 1)
            {
                argsValid = false;
                cerr << "Paramètre non valide pour l'option -t : aucun paramètre " << endl;
                messageErreur();
            }
            else
            {
                string nextArg = argv[++i ];
                // Vérifier si nextArg est un fichier valide, ou gérer l'option -t
                if (nextArg[0] == '-') // Si c'est une autre option, afficher une erreur
                {
                    argsValid = false;
                    cerr << "Paramètre attendu pour -t, mais obtenu : " << nextArg << endl;
                    messageErreur();
                }
                else if (getHeure(nextArg) == -1)
                {
                  argsValid = false;
                  cerr << "Heure renseignée au mauvais format : " << nextArg << "\r\nVeuillez fournir une heure entre 0 et 23." << endl;
                  return 0;
                }
                else
                {
                  heurePresent = true;
                  heure = getHeure(nextArg);
                }
            }
        }
        else if (argCurrent.size()>4 && argCurrent.substr(argCurrent.size() - 4) == ".log")
        {
          nomLogPres = true;
          nomLog = argCurrent;
        }
        else if (argCurrent == "-u")
        {
            if (i == argc - 1)
            {
                argsValid = false;
                cerr << "Paramètre non valide pour l'option -u : aucun paramètre" << endl;
                messageErreur();
            }
            else
            {
                string nextArg = argv[++i ];
                // Vérifier si nextArg est un fichier valide, ou gérer l'option -g
                if (nextArg[0] == '-') // Si c'est une autre option, afficher une erreur
                {
                    argsValid = false;
                    cerr << "Paramètre attendu pour -u, mais obtenu : " << nextArg  << endl;
                    messageErreur();
                }
                else
                {
                    URL_Local = argv[i ];
                    URL_LocalPre = true;
                }
            }
        }
        else
        {
          cerr << "Paramètre "<< argCurrent <<" non reconnu " << endl;
          argsValid = false; 
        }

    }

   
    

    if (!argsValid || !nomLogPres)
    {
      cerr << "Paramètres invalide: Usage: ./analog [-g nomfichier.dot] [-e] [-t heure] nomfichier.log" << endl;
      return 0;
    }

  Structure_Log * log_SD;
  if (heurePresent)
  {
    log_SD = new Structure_Log(faireGraph, exclusion, heure);
  }
  else
  {
    log_SD = new Structure_Log(faireGraph,exclusion);
  }
  
  
  if (URL_LocalPre)
  {
    
    log_SD->readFile(nomLog, URL_Local);
  }
  else
  {
    
    log_SD->readFile(nomLog);
    
  }
  
  Sortie * affichage = new Sortie(log_SD);

  affichage->AffichageTop10();
  if (faireGraph)
  {
    affichage->EcritGraphe(nomGraphe);
  }
}

          



int getHeure(string strHeure)
{
  for( long unsigned int i = 0 ; i < strHeure.size() ; i++)
    {
  	if( !isdigit( strHeure[i] ) )
    {
      return -1;
    }
  }

  int heure = stoi ( strHeure ) ;
  if( heure < 0 or heure > 23 ) 
  {
    return -1;
  }
  return heure;
}

void messageErreur()
{
  cerr << "Paramètres invalide: Usage: ./analog [-g nomfichier.dot] [-e] [-u URL_Local] [-t heure] nomfichier.log" << endl;
}