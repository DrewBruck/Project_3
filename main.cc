/*
Name:       Drew Bruck
Course:     CSCI 335
Professor:  Jaime Canizales
Assignment: Project 3 - Customer implementation.  This is the implementation
for the customer class to be used in conjunction with the template class
Max_Heap.h.  This customer class will contain the following information:
customer name, priority level, and service time.
*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "Max_Heap.h"

class Customer
{
    private:
        std::string name_;
        int service_time_;
        int priority_;

    public:
        //Zero-parameter constuctor
        Customer(){
            name_ = "";
            SetPriorityLevel();
            service_time_=0;
        }
        //Parameterized constructor
        Customer(std::string str){
            SetName(str);
            SetPriorityLevel();
            service_time_=0;
        }
        //SetName() takes user input and modifies name_.
        void SetName(std::string str){
            name_ = str;
        }
        //SetPriority() sets priority_ with a random integer between 0 and 100
        void SetPriorityLevel(){
            priority_ = (rand() % 101);
        }
        //SetServiveTime() sets the service_time_ variable with a rnadom
        //integer between 0 and 60.
        void SetServiceTime(){
            service_time_ = (rand() % 61);
        }
        //GetName() returns private variable name_;
        std::string GetName(){
            return name_;
        }
        //GetPriority() returns the value of private variable priority_.
        int GetPriority(){
            return priority_;
        }
        //GetServiceTime() returns the value of private variable service_time_
        int GetServiceTime(){
            return service_time_;
        }
        //Copy Constructor
        Customer(const Customer &cust){
            name_ = cust.name_;
            priority_ = cust.priority_;
            service_time_ = cust.service_time_;
        }
        //Copy Assignment
        Customer& operator=(const Customer & rhs){
            this->SetName(rhs.name_);
            this->priority_ = rhs.priority_;
            this->service_time_ = rhs.service_time_;
            return *this;
        }
        //Print Customer specs
        void PrintCustomer(){
            std::cout << "Customer: " << this->GetName() << "\n";
            std::cout << "Priority: " << this->GetPriority() << "\n";
            std::cout << "Service Time: " << this->GetServiceTime() << "\n" << "\n";
        }
        //Overload the < operator.
        bool operator<(const Customer rhs){
            return (service_time_< rhs.service_time_);
        }
        //Overload the > operator.
        bool operator>(const Customer rhs){
            return (priority_ > rhs.priority_);
        }

        //Overload the << operator so that print can be called to the class.
        friend std::ostream& operator<<(std::ostream &os, Customer cus){
            os << "Name: " << cus.GetName() << "\nPriority: " << cus.priority_ << "\nService Time: " << cus.service_time_ << "\n\n";
            return os;
        }

}; //end customer class


int main(){

    //test zero-parameter constructor & PrintCustomer() function
    Customer Drew;
    Drew.SetName("Drewski");
    // std::cout << Drew;      //test operator << override

    //test parameterized constructor
    Customer Jayme("Jayme");
    // std::cout << Jayme;

    // //Test getter functions
    // std::cout << Drew.GetName() << "\n";
    // std::cout << Drew.GetPriority() << "\n";
    // std::cout << Drew.GetServiceTime() << "\n";

    // //Test copy constructor
    // Customer copy(Jayme);
    // copy.PrintCustomer();

    // //Test copy assignment
    // Customer copy2 = Drew;
    // copy2.PrintCustomer();

    Customer Matt("Matt");
    // std::cout << Matt;

    Customer Adam("Adam");
    // std::cout<<Adam;

    Customer Germaine("Germaine");
    // std::cout << Germaine;

    Customer Erica("Erica");
    // std::cout << Erica;

    Customer Frank("Frank");

//Test heap construction
    MaxHeap<Customer> Lucy;
    Lucy.InsertIntoHeap(Drew);
    Lucy.InsertIntoHeap(Jayme);
    Lucy.InsertIntoHeap(Matt);
    Lucy.InsertIntoHeap(Adam);
    Lucy.InsertIntoHeap(Germaine);
    Lucy.InsertIntoHeap(Erica);
    Lucy.InsertIntoHeap(Frank);
    Lucy.printHeap();


std::cout << "\nHistory array checks\n";
//Test History vector insertion and ordering.
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();
    Lucy.deleteMin();

    Lucy.printHeap();

std::cout << "\nHistory array: \n";
    Lucy.printHistory();


// std::cout << "Heap testing";
// Lucy.printHeap();



return 0;
};