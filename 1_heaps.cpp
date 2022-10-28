#include <iostream>
using namespace std; 

//Template of the Priority Queue
template <class T> class priorityQueue{
    public: 
        virtual T * extract() =0; 
        virtual priorityQueue<T> * enqueue(T x) = 0; 
        virtual double compare (T * a, T * b) = 0; 
        virtual void printKey(int i) const = 0; 
}; 

template <class T> class binaryHeap : public priorityQueue<T>{
    private:
        T ** queue; 
        int heapsize;
        int queue_length; 
        
        //shifting left, equal to 2*i 
        int getLeft(int i){
            return i << 1; 
        }
        
        //shifting left and using an OR mask with 1, equal to 2*i+1
        int getRight(int i){
            return (i << 1) | 1; 
        }
        
        //shifting right, equal to floor(i/2)
        int getParent(int i){
            return i >> 1; 
        }
        
        void swap(int i, int j){
            T * tmp = queue[i]; 
            queue[i] = queue[j]; 
            queue[j] = tmp; 
        }
        
        void heapify(int index){
                int i = index;
                // <--  or, while (i <= heapsize/2)
                while(i <= heapsize){
                    int v = i;
                    int left = getLeft(i); 
                    int right = getRight(i);
                    if(left <= heapsize && compare(queue[left], queue[i])<0){
                        v = left; 
                    }
                    if(right<= heapsize && compare(queue[right], queue[i])<0){
                        v = right; 
                    }
                    if(v == i){
                        break; 
                    }
                    swap(i, v); 
                    i = v; 

                }
        }

    public:
}; 