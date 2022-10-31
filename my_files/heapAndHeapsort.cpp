// going to lunch but this is the error
// https://stackoverflow.com/questions/20254996/understanding-error-terminate-called-after-throwing-an-instance-of-stdlength
//check later

//SWAP works by reference

//gotta test heapsort
//getting data from file works only if the delimitor is at the end of the line too.
//if the delimitor isnt at the end, it will skip the last piece of data (authors)


#include <iostream>
#include <climits>
#include <cmath>
#include <fstream>
using namespace std; 

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

template <typename T>
void swapp(T & one, T & two){
    T & tmp = one; 
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
            heapArray = new T[len]; 
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
        void minHeapify(minHeap arr, int i){
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
                Songs & j = heapArray[i]; 
                Songs & k = heapArray[smallest]; 
                swapp(j, k); //pass by reference
                arr.minHeapify(arr, smallest);
            }
        };

        void buildMinHeap(minHeap arr, int arrLen){
            arr.setHeapsize(arrLen);
            for(int i = floor(arrLen/2); i >=0; i--){
                minHeapify(arr, i);
            }
        };

        void minHeapInsert(T obj){
            cout << "calling decrease key1"<<endl; 
            
            cout << "heapsize after +1:"<<getHeapsize()<<endl; 
            T newItem; //define empty constructor for heap object
            newItem.setKey(INT_MAX);
            heapArray[getHeapsize()] = INT_MAX; 
            cout << "calling decrease key2"<<endl; 
            decreaseKey(getHeapsize(), obj); 
            setHeapsize(getHeapsize()+1);
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
            if(key.getKey() > getEl(i).getKey()){
                cout << "ERROR"<<endl; 
            }
            heapArray[i] = key; 
            while((i >=0) && (((heapArray[getParent(i)]).getKey())>(heapArray[i].getKey()))){
                swapp(heapArray[i], heapArray[getParent(i)]);
                i = getParent(i); 
            }
        };

        //sorting 
        void heapsort(minHeap heapp, int n){
            buildMinHeap(heapp, n);
            for(int i = heapp.getLen(); i >=2; i--){
                Songs & j = heapArray[0]; 
                Songs & k = heapArray[i]; 
                swapp(j, k); //pass by reference
                heapp.setHeapsize(heapp.getHeapsize()-1); 
                minHeapify(heapp, 0); 
            }
        };


};



Songs * songsFromFile(const string filename, int n){
    Songs * songsArr = new Songs[n];
    Songs song1; 
    for(int i = 0; i<n; i++){
        songsArr[i] = song1; 
    } 
    fstream file; 
    string line; 
    string dataItself; 
    char delim = '-';
    
    file.open(filename); 
    if(file.is_open()){
        for(short i = 0; getline(file, line); i++){
            size_t pos = 0; 
            short counter = 0; 
            while ((pos = line.find(delim)) != string::npos){
            dataItself = line.substr(0, pos);
            cout << dataItself<< " "<<line<<endl; 
            line.erase(0, pos + 1);
            switch(counter){
                case 0:
                    songsArr[i].setKey(stoi(dataItself));
                    counter = 1; 
                    break; 
                case 1:
                    songsArr[i].setTitle(dataItself); 
                    counter = 2;
                    break; 
                case 2:
                    songsArr[i].setAuthor(dataItself); 
                    counter = 0; 
                    break; 
            }
            }
            cout <<"ENDL ENDL "<<endl<<endl; 
        }
    }
    return songsArr; 
}

int main(){
    /*int N = 21; 
    minHeap<Songs> myHeap(N);
    for(int i =0; i < N-1; i++){
        cout <<"song ID "<< i <<endl; 
        Songs mysong(i, "SongTitle1", "NoAuthor"); 
        myHeap.minHeapInsert(mysong);
    }
    for(int i = 0; i < myHeap.getHeapsize(); i++){
    cout << (myHeap.getEl(i)).getKey()<<") "<< (myHeap.getEl(i)).getTitle()<<" - " <<(myHeap.getEl(i)).getAuthor()<<endl; 
    }*/
    int N = 40; 
    Songs * songsArray = songsFromFile("randomizedSongData.txt", 30);
    minHeap<Songs> mySecondHeap(N, songsArray, N);
    cout << "done, maybe"<<endl; 

    //NOW TEST!!
    mySecondHeap.heapsort(mySecondHeap, N);
    ofstream ordered; 
    ordered.open("orderedSongs.txt", ios_base::app);
    ordered << " ------ HEAPSORT!! ----------"<<endl; 
    for(int i = 0; i < mySecondHeap.getHeapsize(); i++){
    ordered << (mySecondHeap.getEl(i)).getKey()<<") "<< (mySecondHeap.getEl(i)).getTitle()<<" - " <<(mySecondHeap.getEl(i)).getAuthor()<<endl; 
    }
    ordered.close(); 

}