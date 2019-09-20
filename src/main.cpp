#include <iostream>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <netinet/in.h>
#include <math.h>
#include <fstream>
#include <time.h>
#include<vector>
#include "bitcounter.h"
#include "bimodal.h"
#include "reader.h"
#include "gshare.h"
#include "pshare.h"
#include "tournament.h"


#define BIMODAL 0
#define GSHARE 2
#define PSHARE 1
#define TOURNAMENT 3

using namespace std;

int main(int argc, char * argv [])


{
	if(argc != 11){
        cout << argc <<endl;
		cout << "Error. Número de argumentos inválido" << endl;
	}else{
		int s = stoi(argv[2]);
		int bp = stoi(argv[4]);
		int gh  = stoi(argv[6]);
		int ph = stoi(argv[8]);
		int o = stoi(argv[10]);
		
		//////////bimodal/////////
        if ( bp == BIMODAL )
        {
        bimodal* predictorb = new bimodal (s);
		predictorb->ALL(  s,  gh,  ph,  o);
        }

	///////gshare/////////
    	else if ( bp == GSHARE )
        {
		
        gshare* predictorg = new gshare (s);
		predictorg->ALL(  s,  gh,  ph,  o);
        }
	   
		////pshare//////
        else if ( bp == PSHARE )
        {
        pshare* predictorp = new pshare (s);
		predictorp->ALL(  s,  gh,  ph,  o);
        }

		////////Torneo///////
        else if ( bp == TOURNAMENT )
        {
		tournament* predictort = new tournament (s);
        predictort->ALL( s, gh, ph, o);
        }
		else
		{
			cout<< " error de seleccion de bh "<<endl;
			
		}
	}
    
   
    
    
    return 0;

}



