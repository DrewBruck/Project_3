/*
Name:       Drew Bruck
Course:     CSCI 335
Professor:  Jaime Canizales
Assignment: Project 3 - Create a max priority heap, where every parent has a 
            value that is equal to or larger than the two children.
*/

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>


template <typename T> 
class MaxHeap {
private:
    
    int current_size_;
    T heap[1000];
    std::vector<T> history;
 
public:
    MaxHeap(){
        current_size_=0; 
    }

    //template<typename T>
    // MaxHeap(T first){
    //     current_size_=0;
    //     InsertIntoHeap(first);
    // }
    
    int getCurrentSize(){return current_size_;}
    
    void printHeap(){
        for(int i = 0; i <current_size_; i++){
            std::cout << heap[i];
            // heap[i].PrintCustomer();
        }
        //std::cout << "\n";
    }

    bool isEmpty(){
        if (current_size_>0)
            return false;
        else
            return true; 
    }
    
    bool isFull(){
        if(current_size_== sizeof(heap))
            return true;
        else
            return false;
    }

    
    void InsertIntoHeap(T new_item){
        if(isFull())
            //throw Overflow("Sorry, mate.  Heap is all filled up.");
            std::cout << "it's full dickhead.";

        //Percolate up
        int hole = current_size_+1;
        while( hole>1 && (new_item > heap[hole/2])){
            heap[hole] = heap[hole/2];
            hole = hole/2;
        }
        heap[hole] = new_item;
        current_size_++;
    }
   
    void InsertHistory(T cust){
        history.pushback(cust);
        std::sort(history.begin(), history.end(), [](T a, T b)
        {
            return (a < b);
        });

    }
    
    void PercolateDown(int hole){
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
  
    void deleteMin(){
        if (isEmpty())
            //throw Underflow ("It's empty now, Dunski.")
        heap[1].SetServiceTime();
        InsertHistory(heap[1]);
        heap[1] = heap[current_size_];
        current_size_--;
        PercolateDown(1);
    }
};



//make sure history is always sorted small to high. so std::sort(s.begin(), s.end()) after every insert.

/*
1.) Create a template class for a max-heap by modifying the code given in the
notes for min-heap. Property of a max-heap: a binary tree has the heap order
property if every node is bigger than or equal to its two children.

3.) Modify the max-heap template class you created to be able to store Customer objects using priority level as the comparable metric.
Modify the max-heap template class function DeleteMax() to return the Customer object being deleted. Set the service time of the deleted customer using the function you created in part 2, then store this deleted customer in a
vector<Customer> history. Make sure history is always sorted from smallest to
largest service time (use std::sort, or find the correct position of the customer
and insert it there).
*/

#endif