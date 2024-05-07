Drew Bruck
Project 3

This project should build a heap and keep it in max-heap structure format.
The main.cc file includes a Customer class to create objects to be stored in the heap.  The heap should be organized based on the priority_ value within the Customer class.  I achieved this by overwriting the following operators: < , > , <<.

I overwrote the < operator to return the service_time_ value that is smallest.  I overwrote the > operator to return the priority_ value that is larger.  This allowed me to keep the heap in descending size and the history array in ascending size.

I also overloaded the << operator to allow easy printing of the Customer class.  This way the template can take other objects, besides Customer, and still be able to print them with ease.

For the heap, I wasn't sure how to create a flexible sized array, so I set the limit to 15,000.
