/*
Name:       Drew Bruck
Course:     CSCI 335
Professor:  Jaime Canizales
Assignment: Project 3 - Create a max priority heap, where every parent has a 
            value that is equal to or larger than the two children.  Heap
            must follow a template to allow various objects to be insterted
            into heap.
*/

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>    //to throw and catch exceptions


template <typename T> 
class MaxHeap {
private:
    
    int current_size_;
    T heap[15000];
    std::vector<T> history;
 
public:
    //Zero-parameter constructor
    MaxHeap(){
        current_size_=1; 
    }

    //Parameterized constructor
    MaxHeap(T first){
        current_size_=1;
        InsertIntoHeap(first);
    }
    
    int getCurrentSize(){return current_size_;}
    
    //function to print heap array.
    void printHeap(){
        for(int i = 1; i <current_size_; i++){
            //uncomment to see where object resides within heap array
            //std::cout <<"heap[" << i << "]\n";
            std::cout << heap[i];     
            
        }
    }
    //function to print history vector
    void printHistory(){
        for(int i = 0; i <history.size(); i++){
            //uncomment to see where object resides within history vector
            // std::cout <<"history[" << i << "]\n";
            std::cout << history[i];
            
        }
    }

    //helper function to check if heap is empty
    bool isEmpty(){
        if (current_size_>0)
            return false;
        else
            return true; 
    }
    
    //helper function to check if heap is full
    bool isFull(){
        if(current_size_== sizeof(heap))
            return true;
        else
            return false;
    }

    //insert function to take object, and add it to heap. Should check if space
    //is available and reorganize entry, based on priority_, to ensure heap 
    //structure.
    void insertIntoHeap(T new_item){
        //exception handler to handle a full heap error
        try{
            if(isFull())
            throw std::overflow_error("Overflow");
        }

        catch(std::overflow_error){
            std::cout << "****** Cannot add item. Heap is already full. ****** \n";
            std::cout << "****** Ignoring last command and pressing on. ******\n";
        }

        //if space exists, the following will "percolate up" and insert object
        //into appropriate space.
        int hole = current_size_;
        while( (hole > 1) && (new_item > heap[hole/2])){
            heap[hole] = heap[hole/2];
            hole = hole/2;
        }
        heap[hole] = new_item;
        current_size_++;
        
    }
    //function to receive object and place it into History array
    void insertHistory(T cust){
        history.push_back(cust);
        std::sort(history.begin(), history.end(), [](T a, T b)
        {
            return (a < b);
        });

    }
    //percolateDown function to reorganize subtrees
    void percolateDown(int hole){
        int child;
        T temp = heap[hole];
        while(2*hole <= current_size_){
            child = hole*2;
            if (child != current_size_ && heap[child + 1] > heap[child])
                child++;
            if (heap[child] > temp)
                heap[hole] = heap[child];
            else
                break;
            hole = child;
        }
        heap[hole] = temp;

    }
    //deletes the maximum value in the heap and reorganizes subtree
    void deleteMax(){
        try{
            if (isEmpty())
            throw std::underflow_error("underflow");
        }
        catch(std::underflow_error){
            std::cout << "****** Can't delete item. Heap is already empty. ****** \n";
            std::cout << "****** Ignoring last command, and pressing on. ******\n";
            return;
        }
        heap[1].SetServiceTime();
        insertHistory(heap[1]);
        heap[1] = heap[current_size_-1];
        current_size_--;
        percolateDown(1);
    }
    //heapify function.
    void heapify(){
        for (int i = current_size_/2; i>0; i--){
            percolateDown(i);
        }
    }
};

#endif