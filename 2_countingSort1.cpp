//creare con chiavi e dati satelliti 

#include <iostream>
#include <cmath>
using namespace std; 

template <typename T>
int min(T*Arr, int n){
    T aux = Arr[0]; 
    for(int i = 1; i < n; i++){
        if(Arr[i]<aux){
            aux = Arr[i]; 
        }
    }
    return aux; 
}

template <typename T>
int max(T*Arr, int n){
    T aux = Arr[0]; 
    for(int i = 1; i < n; i++){
        if(Arr[i]>aux){
            aux = Arr[i]; 
        }
    }
    return aux; 
}

template <typename T>
void countingSort(T * A, int n){ //per ogni elemento considero di usare la chiave per ordinare
    T minA = min(A,n); 
    T maxA = max(A,n);  
    int lenght = (ceil(maxA-minA))+1;
    T  *Count = new T[lenght]{0}; // preinizializzo + allocazione dinamica -- size = lenght, max-min+1
    T  * Output = new T[n]{0}; // array finale (B) -- size = n (size dell'array di partenza)

    for(int i = 0; i<n; i++){ //counting dei numeri in A
        Count[A[i]-minA]++;  
    }
    for(int i = 1; i<lenght; i++){ //addiziono tutti i numeri a monte affinché mi diano l'informazione dell'INDICE (dove mettere i num)
        Count[i] = Count[i]+ Count[i-1]; 
    }
    for(int i = n-1; i>=0; i--){ //posiziono i numeri di A in Out attraverso Count
        Output[Count[A[i]-minA]-1] = A[i]; //il -1 serve perché gli indici partono da 0
        Count[A[i]-minA]--; 
    }

    for(int i = 0; i<n; i++){
        A[i] = Output[i]; 
    }

    delete [] Count; 
    delete [] Output; 
}

int main(){
    int myArray[] = {4, 31, 34, 14, 10, 10, 10, 23, 43, 13, 14, 4, 3};
    countingSort(myArray, 13);

    for(int i = 0; i < 13; i++){
        cout << myArray[i] << " ";
    }
}