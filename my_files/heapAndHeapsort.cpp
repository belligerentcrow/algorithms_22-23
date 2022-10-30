//not sure if the swap works

#include <iostream>
#include <climits>
#include <cmath>
using namespace std; 

template <typename T>
void swapp(T & one, T & two){
    T tmp = one; 
    one = two; 
    two = tmp; 
};

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
        minHeap(int len): length(len){
            heapsize = 0; 
        };
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
            return this->parentOf(i); 
        }

        //methods
        void minHeapify(minHeap * arr, int i){
            int smallest = i; 
            int left = arr.getLeft(i);
            int right = arr.getRight(i); 
            if((left <= arr.getHeapsize()) && (arr.getEl(left).getKey() < arr.getEl(i).getKey())){
                smallest = left; 
            }
            if((right <= arr.getHeapsize())&& (arr.getEl(right).getKey()<arr.getEl(smallest).getKey())){
                smallest = right; 
            }

            if(smallest != i){
                swap(arr.getEl(i), arr.getEl(smallest));
                arr.minHeapify(arr, smallest);
            }
        };

        void buildMinHeap(minHeap * arr, int arrLen){
            arr.getHeapsize() = arrLen;
            for(int i = floor(arrLen/2); i >=1; i--){
                minHeapify(arr, i);
            }
        };

        void minHeapInsert(T obj){
            cout << "calling decrease key1"<<endl; 
            setHeapsize(getHeapsize()+1); 
            T newItem; //define empty constructor for heap object
            newItem.setKey(INT_MAX);
            heapArray[getHeapsize()] = newItem;
            cout << "calling decrease key2"<<endl; 
            decreaseKey(getHeapsize(), obj.getKey()); 

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
            if(key.getKey() < getEl(i).getKey()){
                cout << "ERROR"<<endl; 
            }
            getEl(i).setKey(key.getKey()); 
            while((i >1) && getEl(getParent(i)).getKey()>getEl(i).getKey()){
                swap(heapArray[i], heapArray[getParent(i)]);
                i = getParent(i); 
            }
        };

        //sorting 
        void heapsort(minHeap heapp, int n){
            buildMinHeap(heapp, n);
            for(int i = heapp.getLen(); i >=2; i--){
                swapp(heapArray[0], heapArray[i]); 
                heapp.setHeapsize(heapp.getHeapsize()-1); 
                minHeapify(heapp, 0); 
            }
        };


};

class Songs{
    private:
        int key; 
        string title; 
        string author;
    public: 
        Songs(){}; 
        Songs(int _k): key(_k){};
        Songs(int _k, string _t, string _a): key(_k), title(_t), author(_a){};
        //getters
        int getKey(){
            return this->key; 
        } 
        string getTitle(){
            return this->title; 
        }
        string getAuthor(){
            return this->author;
        }

        //setters
        void setKey(int i){
            this->key = i; 
        }
        void setTitle(string _t){
            this->title = _t; 
        }
        void setAuthor(string _a){
            this->author = _a; 
        }
};

int main(){
    int N = 20; 
    minHeap<Songs> myHeap(N);
    for(int i =0; i < N; i++){
        cout <<"song ID "<< i <<endl; 
        Songs mysong(i, "SongTitle1", "NoAuthor"); 
        myHeap.minHeapInsert(mysong);
    }
    for(int i = 0; i < N; i++){
    cout << (myHeap.getEl(i)).getKey()<<") "<< (myHeap.getEl(i)).getTitle()<<" - " <<(myHeap.getEl(i)).getAuthor()<<endl; 
    }
}