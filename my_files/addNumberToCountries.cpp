#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std; 

#define COUNTRYNUM 30

void loadCountry(const string filename){
    fstream file; 
    string line; 
    file.open(filename); 
    if(file.is_open()){
        for(short i = 0; getline(file, line); i++){
            ofstream file3; 
            file3.open("outSongsData.txt", ios_base::app);
            file3 << i+1 << '-'<<line<<'\n';
            file3.close(); 
        }
    }
}

int main(){
    loadCountry("songsData.txt"); 
}