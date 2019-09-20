#include "bitcounter.h"

bitcounter::bitcounter(){
    for(int i=0; i<4; i++)
    {
        //this->states.push_back(i); 
        this->states[i] =i;
        //cout<< this->states[i];
    }
    
    
    this->actual_s =0;
}
bitcounter::bitcounter(int state){
    for(int i=0; i<4; i++)
    {
        //this->states.push_back(i); 
        this->states[i] =i;
        //cout<< this->states[i];
    }
    
    
    this->actual_s =state;
}
bitcounter::~bitcounter(){

}

void bitcounter:: change_s(bool jump){

    if (this->actual_s == 0 && jump ==1 ){
        //cout<<"el estado actual es: "<<this->actual_s << endl;
        //this->actual_s = this->states[1];
        this->actual_s++;
       // cout<<"el estado actual es: "<<this->actual_s << endl;
    }
    else if( this->actual_s == 1 && jump ==1){
        //cout<<"el estado actual es: "<<this->actual_s << endl;
        //this->actual_s = this->states[2];
        this->actual_s++;
        //cout<<"el estado actual es: "<<this->actual_s << endl;
    }
    else if( this->actual_s == 2 && jump ==1){
       // cout<<"el estado actual es: "<<this->actual_s << endl;
        //this->actual_s = this->states[3];
        this->actual_s++;
    }
    else if( this->actual_s == 1 && jump ==0){
        //cout<<"el estado actual es: "<<this->actual_s << endl;
        //this->actual_s = this->states[0];
        this->actual_s--;
    }
    else if( this->actual_s == 2 && jump ==0){
        //cout<<"el estado actual es: "<<this->actual_s << endl;
        //this->actual_s = this->states[1];
        this->actual_s--;
    }
    else if( this->actual_s == 3 && jump ==0){
         //cout<<"el estado actual es: "<<this->actual_s << endl;
        //this->actual_s = this->states[2];
        this->actual_s--;
    }
    
    

}

void bitcounter:: change_s_m(bool jump, bool gr, bool pr){
    
    if( gr == jump && pr != jump && this->actual_s != 0 )
    {
        this->actual_s--;
    }

     if( gr != jump && pr == jump && this->actual_s != 3 )
    {
        this->actual_s++;
    }



}