#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "reader.h"


reader::reader(){
    
}
reader::~reader(){}

void reader::read(string path){
int i = 0;
long long j = 0;
long x = 0;
string aux;
aux.clear();
ifstream fe(path); 
while(!fe.eof()) 
    {
        
        fe.getline(this->cadena, 128, '\n');
        
        if (this->cadena[0] != 0)
        {
            for (int k=0; k<=int(sizeof(this->cadena)); k++)
            {
              
                
                if (this->cadena[k] == 'T'|| this->cadena[k] == 'N')
                {
                    this->jump.push_back(this->cadena[k]);
                   
                    
                }
            }
        
            
            while(int(this->cadena[i])!= ' ' )
                {
                    
                    aux= aux+ this->cadena[i];
                
                    i++;
                }
            x= stol(aux);
            this->address.push_back(x);
        }
            j++;
            aux.clear(); 
            i=0;
        
   }
   
  

}

void reader::read(){
string address;
string jump;
int i =0;
while(cin>>jump && cin >> address)
{ 
    if (i<200)
    {
        cout<<address<< " "<< jump<<endl;
    }
    
    if(address.empty() || jump.empty())
    {
        break;
    }
    i++;
    
}

}
