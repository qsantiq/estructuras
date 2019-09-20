#include "flag.h"
#include <vector>
#include<bits/stdc++.h> 

using namespace std;
/*Funcion encargada de leer los parametros necesarios, recibe como parametro los argumentos*/

vector<int> flag_reader(int argc, char const *argv[])
{
    //Se declarasn ciertas variables necesarias
    int flags_quantity=5;
    vector<int> flags_output(flags_quantity);
    vector<string> flag_readed;
    bool s=false;
    bool bp=false;
    bool gh=false;
    bool ph=false;
    bool o=false;
    //Se colocan los argumentos en un vector
    for(int i=0;i<argc;i++){
        flag_readed.push_back(argv[i]); 
    }
    //Se buscan los argumentos conocidos a la vez que se checkea que no esten vacios
    for(unsigned int i=0;i<flag_readed.size();i++){
        try {
 
            if(flag_readed[i]=="-s" && flag_readed.size()>i+1){
                flags_output[0]=stoi(flag_readed[i+1]);
                s=1;
            }
            if(flag_readed[i]=="-bp" && flag_readed.size()>i+1){
                flags_output[1]=stoi(flag_readed[i+1]);
                bp=1;
            }
            if(flag_readed[i]=="-gh" && flag_readed.size()>i+1){
                flags_output[2]=stoi(flag_readed[i+1]);
                gh=1;
            }
            if(flag_readed[i]=="-ph" && flag_readed.size()>i+1){
                flags_output[3]=stoi(flag_readed[i+1]);
                ph=1;
            }
            if(flag_readed[i]=="-o" && flag_readed.size()>i+1){
                flags_output[4]=stoi(flag_readed[i+1]);
                o=1;
            }            
        }

        //En caso de que un parametro sea algo diferente a un numero
        catch (const std::invalid_argument& ia) {
            cout<<"Error el valor de los parametros debe ser un numero "<<endl;
            exit(-1);
        }
    }
        //Se verifica que se disponga de todos los parametros
        if(o==false || s==false || bp==false || gh==false || ph==false){
            cout<<"Faltan Argumentos"<<endl;
            exit(-1);
        }
    return flags_output; 
}