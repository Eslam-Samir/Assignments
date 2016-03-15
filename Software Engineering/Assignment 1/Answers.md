###Computer and Systems 
###Engineering Department

####Software Engineering

####Assignment 1

####Submitted By

####Eslam Samir Ali Abu El-Ala

####Section 1




####Questions:

#####1- What is a class?

  A class is a user-defined type which allows us to treat variables in programming as objects.


#####2- How does a class accomplish abstraction, encapsulation, and data hiding?

  **`Abstraction:`** using public members and inheritance which enables us to treat a set of related classes as one concept.
  **`Encapsulation & Data Hiding:`** by dividing variables and functions inside the class into private, public, and protected members.

  -	**`Public:`** Anything can see it 
  -	**`Protected:`** Only objects of this class and derived class can see it 
  -	**`Private:`** Only objects from this class can see it. 


#####3- What is the relationship between an object and a class?

  An object is an instance of a class.
  This means an object is the equivalent of a variable and class is the equivalent of a new data type.


#####4- In what way, aside from being functions, are class function members different from class data members?

  Usually data members go into the private section and functions into the public section.
  Also unlike class data members possible to define class function members outside of the class definition.


#####5- Define a class to represent a bank account.

  [BankAccount.h](https://github.com/Eslam-Samir/Assignment-1/blob/master/BankAccount/BankAccount.h)


#####6- When are class constructors called? When are class destructors called?

  Constructors are called to initialize the internally used fields in the class
  Destructors are called to release any resources allocated by the object.


#####7- Provide code for a constructor for the bank account class.

  [BankAccount.h](https://github.com/Eslam-Samir/Assignment-1/blob/master/BankAccount/BankAccount.h)
  
  [BankAccount.cpp](https://github.com/Eslam-Samir/Assignment-1/blob/master/BankAccount/BankAccount.cpp)


#####8- What is a default constructor? What is the advantage of having one?

  A default constructor is a constructor that is called to create an object and is called with no arguments.
  You can use it to initialize the data members inside of the class.


#####9- Modify the Stock class definition.

  [Stock.h](https://github.com/Eslam-Samir/Assignment-1/blob/master/Stock.h)


#####10- What are this and *this?

  **`this`** is a pointer points to the object itself.
  
  **`*this`** is Reference to the calling.

####Programming Exercises:


#####1- [BankAccount](https://github.com/Eslam-Samir/Assignment-1/tree/master/BankAccount)


#####2- [Person](https://github.com/Eslam-Samir/Assignment-1/blob/master/Person.cpp)


#####3- [Move](https://github.com/Eslam-Samir/Assignment-1/blob/master/Move.cpp)
