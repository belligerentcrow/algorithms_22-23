//counting sort with satellite data --> stability works!
// 30-10-22 adding reading from file

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std; 

class historyOfPhilosophyBook{
    private:
        int key; 
        string title; 
        string * thinkers;
        string coverColour; 

    public: 
        historyOfPhilosophyBook(){}; 
        historyOfPhilosophyBook(int _i, string _tit, string _co): key(_i), title(_tit), coverColour(_co){};
        historyOfPhilosophyBook(int _i, string _s, string _co, string * _th): key(_i), title(_s), coverColour(_co){
            this->thinkers = _th; 
        }; 

        int getKey(){
            return this->key; 
        }
        string getTitle(){
            return this->title; 
        }
        string getCoverColour(){
            return this->coverColour; 
        }
        string * getThinkers(){
            return this->thinkers;
        }


};

template <typename T>
T min(T * Arr, int n){
    T aux = Arr[0]; 
    for(int i = 1; i < n; i++){
        if((Arr[i].getKey()) <aux.getKey()){
            aux = Arr[i]; 
        }
    }
    return aux; 
}

template <typename T>
T max(T * Arr, int n){
    T aux = Arr[0]; 
    for(int i = 1; i < n; i++){
        if((Arr[i].getKey()) >aux.getKey()){
            aux = Arr[i]; 
        }
    }
    return aux; 
}

template <typename T>
void countingSort(T * A, int n){
    T minA = min(A, n); 
    T maxA = max(A, n);
    int lenght = (ceil(maxA.getKey()-minA.getKey()))+1; 
    int * Count = new int[lenght]{0}; 
    T * Output = new T[n]; 

    for(int i = 0; i < n; i++){
        Count[(A[i].getKey())-(minA.getKey())]++;  
    }
    for(int i = 1; i < lenght; i++){
        Count[i] = Count[i]+Count[i-1]; 
    }

    for(int i = n-1; i>=0; i--){
        Output[Count[(A[i].getKey())-(minA.getKey())]-1] = A[i]; 
        Count[(A[i].getKey())-minA.getKey()]--; 
    }

    for(int i = 0; i <n; i++){
        A[i] = Output[i]; 
    }
    
    delete [] Count; 
    delete [] Output; 
}

template <typename T>
void printArray(T arr, int n){
    cout << "Printing array of books: "<<endl; 
    for(int i = 0; i < n; i++){
        cout << arr[i].getKey() << " - "<<arr[i].getTitle()<< " - " <<arr[i].getCoverColour()<<" . "<<endl; 
    }
}

int main(){
    int N = 12; 
    historyOfPhilosophyBook myBooks[N] = {{3, "Cartesio", "Blue"}, {0, "Platone", "Green"}, {1, "Aristotele", "Orange"}, {2, "Agostino", "Green" }, {4, "Pascal", "Green"}, {7, "Locke", "Yellow"}, {5, "Spinoza", "Green"}, {8, "Hume", "Green"}, {6, "Hobbes", "Green"}, {9, "Kant", "Green"}, {9, "Kant", "LightBlue"}, {5, "Spinoza", "Pink"}}; 
    historyOfPhilosophyBook myBooksBackup[N] = {{3, "Cartesio", "Blue"}, {0, "Platone", "Green"}, {1, "Aristotele", "Orange"}, {2, "Agostino", "Green" }, {4, "Pascal", "Green"}, {7, "Locke", "Yellow"}, {5, "Spinoza", "Green"}, {8, "Hume", "Green"}, {6, "Hobbes", "Green"}, {9, "Kant", "Green"}, {9, "Kant", "LightBlue"},{5, "Spinoza", "Pink"}};

    countingSort(myBooks, N); 
    printArray(myBooks, N); 

}