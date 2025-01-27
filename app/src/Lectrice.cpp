/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Lectrice.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Lectrice::getCurrentLog(){
    return currentLog;
}

bool Lectrice::getnextLog(){
    if(getline(file,currentLog,SEPLOG)){
        return true;
    }
    else{
        currentLog = "";
        return false;
    }
}

string Lectrice::getIPEmet(){
    string IP;
    int pos;
    pos = currentLog.find('-'); // Il y aura tujours un - car les utilisateurs sont anonymes
    return currentLog.substr(0,pos-1); // Il y a un espace avant le tiré
}

string Lectrice::getTimeDate(){
    string Time;
    int posd;
    int posf;
    posd=currentLog.find('[');
    posf=currentLog.find(']');
    return currentLog.substr(posd+1,posf-posd-1); 
}

string Lectrice::getDate(){
    string str = getTimeDate();
    int pos = str.find(":");
    return str.substr(0,pos); 
}

int Lectrice::getFuseau(){
    string str = getTimeDate();
    int pos = str.find(":");
    string str2 = str.substr(pos+1);
    string sfuseau1= str2.substr(9);
    string sfuseau = sfuseau1.substr(0,sfuseau1.length()-2); // Garde les 3 premiers caractéres
    return stoi(sfuseau);

}

int Lectrice::getTime(){
    string str = getTimeDate();
    int pos = str.find(":");
    string str2 = str.substr(pos+1);
    string stime= str2.substr(0,8);
    
    string sheure=stime.substr(0,2);
    
    string sminute=stime.substr(3,2);
    
    string sseconde=stime.substr(6,2);
    
    int fuseau = getFuseau();
    return 3600*(stoi(sheure)-fuseau)+60*stoi(sminute)+stoi(sseconde);
}

string Lectrice::getURLTarget(){
    string URL;
    int posURL=currentLog.find('"');
    string str1 = currentLog.substr(posURL);
    int posd = str1.find('/');
    string str2 = str1.substr(posd);
    int posf= str2.find('"');
    return str2.substr(0,posf);
}

string Lectrice::getURLReferer(){
    // On cherche la 3 éme occurence de '"'
    int pos1, pos2, pos3, pos4; //Occurence des i_éme '"'    
    pos1 = currentLog.find('"');   
    string str1 = currentLog.substr(pos1+1);
    pos2 = str1.find('"');
    string str2 = str1.substr(pos2+1);
    pos3= str2.find('"');
    string str3 = str2.substr(pos3+1);
    pos4 = str3.find('"');
    return str3.substr(0,pos4);
}

string Lectrice::getclearURLReferer(){
    string URL = getURLReferer();
    int len = localURL.length();
    if (URL.substr(0,len)==localURL){
        return URL.substr(len+1);
    }
    else{
        return URL;
    }
}

string Lectrice::getActionType(){
    string action;
    int pos1, pos2;  
    pos1 = currentLog.find('"');   
    string str1 = currentLog.substr(pos1+1);
    pos2 = str1.find('/');
    string str2 = str1.substr(0,pos2-1);
    return str2;
}

int Lectrice::getStatus(){
    int pos1, pos2; //Occurence des i_éme '"'    
    pos1 = currentLog.find('"');   
    string str1 = currentLog.substr(pos1+1);
    pos2 = str1.find('"');
    string str2 = str1.substr(pos2+1);
    
    string str3 = str2.substr(1);
    int posespace =str3.find(" ");
    string sstatus=str3.substr(0,posespace);
    if (!stoi(sstatus)){
        return -1;
    }

    int status = stoi(sstatus);
    return status;
}

int Lectrice::getDataSize(){
    int pos1, pos2; //Occurence des i_éme '"'    
    pos1 = currentLog.find('"');   
    string str1 = currentLog.substr(pos1+1);
    pos2 = str1.find('"');
    string str2 = str1.substr(pos2+1);
    int posespace =str2.find(" ");
    string ssize1=str2.substr(posespace);
    
    
    string ssize = ssize1.substr(0,ssize1.length()-ssize1.find('"')-1);
    if (ssize1 == "-"){
        return -1;
    }
    else{
        int size = stoi(ssize);
        return size;
    }
}

string Lectrice::getIDNavigator(){
    int pos1, pos2, pos3, pos4; //Occurence des i_éme '"'    
    pos1 = currentLog.find('"');   
    string str1 = currentLog.substr(pos1+1);
    pos2 = str1.find('"');
    string str2 = str1.substr(pos2+1);
    pos3= str2.find('"');
    string str3 = str2.substr(pos3+1);
    pos4 = str3.find('"');
    string str4=str3.substr(pos4);
    return str4.substr(3,str4.length()-4);
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Lectrice::Lectrice (string lefileName, string laLocalURL)
{
    file.open(lefileName);
    localURL = laLocalURL;
    if (!file.is_open()){
        cerr << "Erreur lors de l'ouverture du fichier " << endl;
    }
    //getline(file,currentLog,SEPLOG);
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} 


Lectrice::~Lectrice ( )
// Algorithme :
//
{
    if (file.is_open()){
        file.close();
    }
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

