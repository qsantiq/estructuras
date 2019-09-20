#include "pshare.h"

using namespace std;

pshare::pshare(){}
pshare::pshare(int s){
  
    this->fails=0.0;
    this->jumps=0.0;
    this->miss_rate= 0.0;
    this->correct_rate= 0.0;
    this->ctaken=0;
    this->cntaken=0;
    this->nctaken=0;
    this->ncntaken=0;
    for (int i=0; i<(pow(2,s)); i++)
    {   
        this-> counters.push_back(*new bitcounter());
        this->pht.push_back(0);
    }
    for(int i=0; i<(pow(2,5)); i++ )
    {
         
    }
            
}

pshare::~pshare(){}

int pshare::select_counter(unsigned long address, int s)
{
   
    unsigned long mask=pow(2,s)-1;
    unsigned long c_n=0;
    unsigned long pht_a = address & mask;
    c_n = this->pht[pht_a] ^ pht_a;
    return c_n;
}

void pshare:: predict(int c){
if (this->counters[c].actual_s == 0 || this->counters[c].actual_s == 1  )
{
    this->prediction = ('N');
}
else
{
    this->prediction =('T');
}

}


bool pshare::compare(char j){
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




void pshare:: change_counter(int counter_number, int j){
     this->counters[counter_number].change_s(j);
}

void pshare:: update_pht(long address,char j, int s,int ph){

    unsigned long mask = pow(2,s)-1;
    unsigned long mask1 = pow(2,ph)-1;
    unsigned long pht_a= address & mask;
    this->pht[pht_a] = this->pht[pht_a]<<1;
    if(j== 'T')
    {
        this->pht[pht_a] = this->pht[pht_a]+1;

    } 
     this->pht[pht_a] = this->pht[pht_a] & mask1;
    
}

void pshare:: ALL( int s, int gh, int ph, int o)
{  
    ofstream out;
    string address_s;
    string jump_s;
    string line= "";
    string out_p="output/outp.txt";
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
        
        
        counter_number = this->select_counter(unsigned(address), s);
        this->predict(counter_number);
        jump_b = this->compare(jump_c);
        this->change_counter(counter_number,jump_b);
        this->update_pht( address, jump_c, s, ph);
        


        if( o ==1 && k<= 5000)
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
                string header;
                header="PREDICTOR PSHARE\nPC            OUTCOME    PREDICTION    CORRECT/INCORRECT";                
                out.open(out_p, ofstream::out | ofstream::trunc);
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
    cout<<"Branch Prediction Type:                               "<<"Pshare"<<endl;
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