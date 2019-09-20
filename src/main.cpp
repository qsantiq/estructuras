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
		
			/* int s= 3;
		int bh = 0;
		int gh =3;
		int ph = 3;
		int o = 1;*/

		
		string path;
		std::cin  >> path;
		//pshare* p = new pshare();
		//p->read(path);
		//int inicial =2;

		 
		
		int prueba;
		//string path;
		//std::cin  >> path;
		//cin.read();
		  
		//reader* lector = new reader(); 
		//lector->read();
		//lector->read(path);
		
		
		//bitcounter* santiago = new bitcounter();
		//santiago->change_s(0);
			

		//////////bimodal/////////

        //bimodal* predictorb = new bimodal (s);
		//predictorb->ALL(  s,  gh,  ph,  o);
		/*
		int counter_number=0;
		bool jump = 0;
		for (int i=0; i< int(lector->jump.size()); i++)
		{
			counter_number = predictorb->select_c(3, (lector->address[i]));
			predictorb->predict(counter_number);
			jump = predictorb->compare( lector->jump[i]);
			cout<<counter_number<<" "<<predictorb->counters[counter_number].actual_s<<" ";
			predictorb->change_counter(counter_number,jump);
			cout<<predictorb->counters[counter_number].actual_s<<" " << predictorb->prediction <<" "<<predictorb->result <<' '<<lector->jump[i]<<endl;
			
		}*/

	///////gshare/////////
        //gshare* predictorg = new gshare (s);
		//predictorg->ALL(  s,  gh,  ph,  o);
	   /*int counter_number_g = 0;
		bool jump_g= 0;
		
		
		for (int i=0; i< int(lector->jump.size()); i++)
		{
			
		   counter_number_g = predictorg->select_counter(lector->address[i],4,3);
		   
		   predictorg->predict(counter_number_g);
		   jump_g =  predictorg->compare(lector->jump[i]);
		   cout<<lector->address[i]<<" "<<counter_number_g<<" "<<predictorg->counters[counter_number_g].actual_s<<" ";
		   predictorg->change_counter (counter_number_g, jump_g);
		   predictorg->update_bhr(3,lector->jump[i]);
		   cout<<predictorg->counters[counter_number_g].actual_s<<" "<<predictorg->prediction<<" "<<lector->jump[i]<< " " << predictorg->result <<" "<<endl;
		
		}*/
		////pshare//////
        //pshare* predictorp = new pshare (s);
		//predictorp->ALL(  s,  gh,  ph,  o);
        /*int k = 0;
		int counter_number_p = 0;
		bool j_p= 0;
		for (int i=0; i<int(lector->jump.size()); i++)
			{
				counter_number_p=predictorp->select_counter(lector->address[i], 5);
				predictorp->predict (counter_number_p);
				j_p = predictorp->compare(lector->jump[i]);
				cout<<lector->address[i]<<" "<<counter_number_p<<" "<<predictorp->counters[counter_number_p].actual_s<<" ";
				predictorp->change_counter(counter_number_p, j_p);
				predictorp->update_pht(lector->address[i], lector->jump[i], 5,2);
				cout<<predictorp->counters[counter_number_p].actual_s<<" "<<predictorp->prediction<<" "<<lector->jump[i]<< " " << predictorp->result <<" "<<endl;
				
				
			}*/

		////////Torneo///////
		//tournament* predictort = new tournament (s);
        //predictort->ALL(  s,  gh,  ph,  o);
        /*
		int counter_number_tour = 0;
		bool j_tour= 0;
		for (int i=0; i< int(lector->jump.size()); i++)
		{
			counter_number_tour = predictort->select_counter(lector->address[i], 3);
			predictort->g_predict(lector->address[i], 3,4,lector->jump[i]);
			predictort->p_predict(lector->address[i], 3,3,lector->jump[i]);
			predictort->predict(counter_number_tour);
			j_tour = predictort->compare(lector->jump[i]);
			cout<< lector->jump[i]<<' ' <<counter_number_tour<< ' ' <<" "<<predictort->predictorg.prediction<<" "<<predictort->predictorp.prediction<<" "<<lector->address[i] << " " <<predictort->counters[counter_number_tour].actual_s<< " ";
			predictort->change_counter(counter_number_tour,j_tour);
			cout<< predictort->counters[counter_number_tour].actual_s<< " "<<predictort->selected_p<<" "<<predictort->prediction<<" "<<predictort->result<< endl;   
			
		}
	*/
	}
    
   
    
    
    return 0;

}



