#include<iostream>
#include<string.h>
#include<fstream> //This header file is used to manipulate the txt file 

using namespace std;

//An add function with arguments of a vector, the destination, the source 1, the source 2

void add(vector<int> &regis,int dest,int src1,int src2)
{ 
    regis[dest]=regis[src1]+regis[src2]; //we will add the value stored in src1 index of register and source 2 index of register and stored it in destination index of register
}

//A sub function with arguments like a vector, the destination, the source 1, the source 2

void sub(vector<int> &regis,int dest,int src1,int src2)
{
    regis[dest]=regis[src1]-regis[src2]; //we will subtract the value stored in src1 index of register and source 2 index of register and stored it in destination index of register
}

//An addi function with arguments like a vector, the destination, the source 1, the source 2

void addi(vector<int> &regis,int dest,int src1,int src2)
{
    regis[dest]=regis[src1]+src2; //we will add the value stored in src1 index of register and source 2 and stored it in destination index of register
}

//A subi function with arguments like a vector, the destination, the source 1, the source 2

void subi(vector<int> &regis,int dest,int src1,int src2)
{
    regis[dest]=regis[src1]-src2; //we will subtract the value stored in src1 index of register and source 2 and stored it in destination index of register
}

//A store function with arguments like a vector, the destination, the source 1

void store(vector<int> &regis,int dest,int src1)
{
    regis[dest]=src1; //we will store the source1 to the destination index of register
}


int main()
{
    fstream newfile; //makeing a newfile of fstream type

    newfile.open("temp.txt", ios::in);  //giving access to read the temp.txt file
    
    if (newfile.is_open()) { //check if new file is open
        vector<int> regis(33,0); //making a vector name register of size 33 and initialize it with 0

        string stat; 

        while (getline(newfile, stat)) {  //to get the commands from txt file line by line

            string op="";
            string src1="";
            string src2="";
            string dest="";

            //to store different values like operator,sources and destination

            int i=0;
            int n=stat.length();

            while(i<n){
                if(stat[i]==' '){ //if the iterator experience a space character then it will break
                    break;
                }

                op+=stat[i]; //storing each character till space i.e. operator
                i++;
            }

            i++;

            while(i<n){
                if(stat[i]==','){ //iterate till a comma occur
                    dest=stat[i-1]; //store destination value ie previous character of comma 
                    break; //if comma occur break the loop
                }
                else{
                    i++;
                }
            }

            while(i++<(n-1)){ // this while loop will store the register no. or the interger value
                if(stat[i-1]==',' && stat[i]!='x'){ // to store the integer value //it will check if the comma occur and the next character is not x
                    src1+=stat[i]; //until the condition meet store each character ie. integer value

                    while(i++<n){
                        src1+=stat[i];
                    }

                }

                else if(stat[i-1]==',' && stat[i]=='x'){  // to store the register no. //it will check if the comma occur and the next character is x then
                    src1=stat[i+1]; //store the the register no. in src1  
                    break;
                }
            }

            while(i++<(n-1)){ // this while loop will store the register no. or the interger value
                if(stat[i-1]==',' && stat[i]!='x'){ // to store the integer value //it will check if the comma occur and the next character is not x
                    src2+=stat[i];//until the condition meet store each character ie. integer value
                    while(i++<n){
                        src2+=stat[i];
                    }

                }

                else if(stat[i-1]==',' && stat[i]=='x'){   // to store the register no. //it will check if the comma occur and the next character is x then
                    src2=stat[i+1]; //store the the register no. in src1  
                    break;
                }
            }

            int destination=0,source1=0,source2=0;

            // stoi is an inbuilt function to convert string into integer
            //Here we convert every strings to integers except

            if(dest!=""){             
                destination=stoi(dest); 
            }

            if(src1!=""){            
                source1=stoi(src1);
            }

            if(src2!=""){            
                source2=stoi(src2);
            }

            if(op=="add"){ //if operator has add then it will call add function with regis vector,destination,source1,source2 as argument
                add(regis,destination,source1,source2);
            }

            else if(op=="addi"){// if operator has addi then it will call add function with regis vector,destination,source1,source2 as argument
                addi(regis,destination,source1,source2);
            }

            else if(op=="sub"){ //if operator has sub then it will call add function with regis vector,destination,source1,source2 as argument
                sub(regis,destination,source1,source2);
            } 

            else if(op=="subi"){ //if operator has subi then it will call add function with regis vector,destination,source1,source2 as argument
                subi(regis,destination,source1,source2);
            }

            else if(op=="store"){ //if operator has store then it will call add function with regis vector,destination,source1 as argument
                store(regis,destination,source1);
            }

            else{
                cout<<"invalid statement"<<endl;
            }
        }

        cout<<"The values stored in registers are "<<endl; // a for loop to iterate and print the values stored in register vector 

        for(int i=1;i<=32;i++){
            cout<<"register No. "<<i<<"= "<<regis[i]<<endl; //printing register values from register 1 to register 32
        }

        newfile.close(); // closing the newfile of type fstream
    }


    
    return 0;
}