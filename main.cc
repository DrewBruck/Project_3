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
        }
        //Parameterized constructor
        Customer(std::string str){
            SetName(str);
            SetPriorityLevel();
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
            return (priority_< rhs.priority_);
        }
        //Overload the > operator.
        bool operator>(const Customer rhs){
            return (priority_< rhs.priority_);
        }

}; //end customer class


int main(){
    std::vector<Customer> history;
    //test zero-parameter constructor & PrintCustomer() function
    Customer Drew;
    Drew.SetName("Drewski");
    Drew.PrintCustomer();

    //test parameterized constructor
    Customer Jayme("Jayme");
    Jayme.SetServiceTime();
    Jayme.PrintCustomer();

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
    Matt.SetServiceTime();
    Matt.PrintCustomer();

    Customer Adam("Adam");
    Adam.SetServiceTime();
    Adam.PrintCustomer();

    Customer Germaine("Germaine");
    Germaine.SetServiceTime();
    Germaine.PrintCustomer();

    Customer Erica("Erica");
    Erica.SetServiceTime();
    Erica.PrintCustomer();

    history.push_back(Drew);
    history.push_back(Jayme);
    history.push_back(Matt);
    history.push_back(Adam);
    history.push_back(Erica);
    history.push_back(Germaine);


std::cout << "Testing vector order: \n";
for (int i = 0; i<history.size(); i++){
    history[i].PrintCustomer();
}

std::cout << (Matt<Jayme);
std::sort(history.begin(), history.end(), [](Customer a, Customer b)
{
    return (a < b);
});

std::cout << "Testing sorted vector order: \n";
for (int i = 0; i<history.size(); i++){
    history[i].PrintCustomer();
}



return 0;
};