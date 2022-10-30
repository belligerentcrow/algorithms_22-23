//not sure if the swap works

#include <iostream>
#include <cmath>
using namespace std; 

template <typename T>
void swap(T one, T two){
    T tmp = one; 
    one = two; 
    two = tmp; 
}

template <typename T>
class minHeap{
    private:
        T * heapArray;
        int heapsize; 
        int length; 
        int leftOf(int i){
            return i << 1; 
        }
        int rightOf(int i){
            return ((i<<1)||1); 
        }
        int parentOf(int i){
            return floor(i>>1); 
        }
    public: 
        //constructors
        minHeap(int len): length(len){};
        minHeap(int len, T * arr, int n):length(len), heapArray(arr), heapsize(n){}; 

        //getters
        T * getArr(){
            return this->heapArray; 
        }
        int getHeapsize(){
            return this->heapsize; 
        }
        T getEl(int i){
            return this->heapArray[i]; 
        }
        int getLen(){
            return this->length; 
        }

        T getMin(){
            return getEl(0); 
        }

        //setters
        void setHeapsize(int i){
            this->heapsize = i; 
        }
        void setEl(int index, T el){
            this->heapArray[index] = el; 
        }

        //these return the INDEXES
        int getLeft(int i){
            return this->leftOf(i); 
        }
        int getRight(int i){
            return this->rightOf(i); 
        }
        int getParent(int i){
            return this->parenttOf(i); 
        }

        //methods
        void minHeapify(minHeap * arr, int i){
            int smallest = i; 
            int left = arr.getLeft(i);
            int right = arr.getRight(i); 
            if((left <= arr.getHeapsize()) && (arr.getEl(left).getKey() < arr.getEl(i).getKey()){
                smallest = left; 
            }
            if(right <= arr.getHeapsize())&& (arr.getEl(right).getKey()<arr.getEl(smallest).getKey()){
                smallest = right; 
            }

            if(smallest != i){
                swap(arr.getEl(i), arr.getEl(smallest));
                arr.minHeapify(arr, smallest);
            }
        };

        void buildMinHeap(minHeap * arr, int arrLen){
            arr.getHeapsize() = arrLen;
            for(int i = floor(arrLen/2)); i >=1; i--){
                minHeapify(arr, i);
            }
        };

        void minHeapInsert(){

        };

        T extractMin(){
            if(getHeapsize()<1){
                cout << "ERROR: HEAP UNDERFLOW"<<endl; 
            }
            T min = getEl(0); 
            setEl(0, getEl(getHeapsize())); 
            setHeapsize(getHeapsize()-1); 
            minHeapify(this, 0); 
            return min; 
        };

        void decreaseKey(int i, T key){
            if(key < getEl(i).getKey()){
                cout << "ERROR"<<endl; 
            }
            getEl(i).setKey(key); 
            while((int i >1) && getParent(i).getKey()>getEl(i).getKey()){
                swap(getEl(i), getParent(i));
                i = getParent(i); 
            }
        };

        //sorting 
        void heapsort(minHeap heapp, int n){
            buildMinHeap(heapp, n);
            for(int i = heapp.getLen(); i >=2; i--){
                swap(heapp.getEl(0), heapp.getEl(i)); 
                heapp.setHeapsize(heapp.getHeapsize()-1); 
                minHeapify(heapp, 0); 
            }
        };


};



int main(){

}