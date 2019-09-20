#include "tournament.h"
using namespace std;

tournament::tournament(){}
tournament::tournament(int s){
   
    this->jumps=0.0;
    this->fails=0.0;
    this->miss_rate = 0.0;
    this->correct_rate= 0.0;   
    this->ctaken=0;
    this->cntaken=0;
    this->nctaken=0;
    this->ncntaken=0;
    
    predictorg = *new gshare (s);
    predictorp = *new pshare (s);
    for (int i=0; i<(pow(2,s)); i++)
    {   
        
        this-> counters.push_back(*new bitcounter(3));
       
    }
            
}

tournament::~tournament(){
   
}

int tournament::select_counter(unsigned long address, int s)
{
   
    unsigned long mask=pow(2,s)-1;
    unsigned long c_n=0;



    c_n =  address & mask;
    return  c_n;

}

void tournament:: predict(int c){

 
if (this->counters[c].actual_s == 0 || this->counters[c].actual_s == 1  )
{
    this->prediction = this->predictorg.prediction;
    this->selected_p = 'G';
}
else
{
    this->prediction = this->predictorp.prediction;
    this->selected_p = 'P';
}

}


bool tournament::compare(char j){
    this->jumps++;
    if (this->prediction == j)
    {
        this->result =('C');
        if(j == 'T')
            {
                this->ctaken++;
            }
            else
            {
                this->cntaken++;
            }
    }
    else 
    {

        this->result = ('I');
        if(j == 'T')
            {
                this->nctaken++;
            }
            else
            {
                this->ncntaken++;
            }

        this->fails++;
    }
    if (j== 'T')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


void tournament:: change_counter(int counter_number, int j){
    bool pg=0;
    bool pp=0;
    if(this->predictorg.prediction == 'T')
    {
        pg =1;
    }
    else
    {
        pg = 0;
    }

    if(this->predictorp.prediction == 'T')
    {
        pp =1;
    }
    else
    {
        pp = 0;
    }
     this->counters[counter_number].change_s_m(j,pg,pp );
}

void tournament::g_predict(long address, int s, int gh, char j){
    
    
    int counter_number_g = 0;
    bool jump_g = 0;
    counter_number_g = this->predictorg.select_counter(address, s,gh);   
    this->predictorg.predict(counter_number_g);
    jump_g =  this->predictorg.compare(j);
    this->predictorg.change_counter (counter_number_g, jump_g);
    this->predictorg.update_bhr( gh,j);
    
    
    

}
void tournament::p_predict(long address, int s, int ph, char j){
     
    int counter_number_p =0;
    bool j_p =0;
    counter_number_p=this->predictorp.select_counter(address, s);
    this->predictorp.predict (counter_number_p);
    j_p = this->predictorp.compare(j);
    this->predictorp.change_counter(counter_number_p, j_p);
    this->predictorp.update_pht(address, j, s,ph);
     

}

void tournament::ALL( int s, int gh, int ph, int o)
{   ofstream out;
    string address_s;
    string jump_s;
    string line;
    string out_p="output/outt.txt";
    bool first_i =0;
    bool jump_b = 0;
    long address;
    char jump_c;
    int k = 0;
    int counter_number =0;
    while(!cin.eof())
    { 
        cin>>address_s;
        cin>>jump_c;
        jump_s = jump_c;
        address = stol(address_s);
        if(address_s.empty() || jump_c == 0 )
        {
            break;
        }
        
        
        counter_number = this->select_counter(unsigned(address), s);
        this->g_predict(address, s, gh, jump_c);
        this->p_predict(address, s, ph, jump_c);
        this->predict(counter_number);
        jump_b = this->compare(jump_c);
        this->change_counter(counter_number,jump_b);
        


        if( o == 1 && k <= 5000)
        {
            
            line.append(to_string(address));
            line.append("       ");
            line.append(jump_s);
            line.append("           ");
            string s(1, this->prediction);
            line.append(s);
            line.append("               ");
            string m(1, this->result);
            line.append(m);
            

              
            if (first_i ==0)
            {
                out.open(out_p, ofstream::out | ofstream::trunc);
                string header;
                header="PREDICTORT\nPC         OUTCOME    PREDICTION    CORRECT/INCORRECT";                
                out << header<<endl;
                out.close();                
                first_i =1;
                
            }
            
            out.open(out_p, ofstream::out | ofstream::app);
            out << line<<endl;
            out.close();    
            line.clear();
            
        }
        k++;
    

    }

    this->miss_rate = this->fails/(this->jumps);
    this->correct_rate = (double)(this->ctaken+this->cntaken)/jumps;
    

    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Prediction Parameter"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Branch Prediction Type:                               "<<"Tournament"<<endl;
    cout<<"BHT size (entries):                                     "<<pow(2,s)<<endl;
    cout<<"Global History register File:                           "<<pow(2,gh)<<endl;
    cout<<"Private history register size:                          "<<pow(2,ph)<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Simulation Results:"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Number of Branch                                        "<<this->jumps-1<<endl;
    cout<<"Number of correct prediction of taken branches:         "<<this->ctaken<<endl;
    cout<<"Number of incorrect prediction of taken branches:       "<<this->nctaken<<endl;
    cout<<"Correct prediction of not taken branches:               "<<this->cntaken<<endl; 
    cout<<"Incorrect prediction of not taken branches:             "<<this->ncntaken<<endl;
    cout<<"Percentage of correct predictions:                      "<<this->correct_rate*100<<endl;                                        
    cout<<"--------------------------------------------------------------"<<endl;
  
}
