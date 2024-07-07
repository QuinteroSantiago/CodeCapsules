# OOP_Projects

A repository for projects done in C++

## Project Descriptions
### LinkedList
This project implements a generic doubly linked list in C++. The LinkedList class provides functionalities to manipulate a linked list with various operations such as insertion, deletion, searching, and more.

#### File Structure
* LinkedList.h: Contains the declaration and implementation of the LinkedList class.
* main.cpp: Contains test cases to demonstrate the usage of the LinkedList class.
* LinkedList Class Overview
  * Node Structure: Each node contains a pointer to the previous node, a pointer to the next node, and the data.
  * Constructors and Destructor:
    * Default Constructor: Initializes an empty list.
    * Destructor: Cleans up all nodes in the list.
    * Copy Constructor: Creates a new list by copying an existing list.
  * Accessors:
    * Head(): Returns a pointer to the head node.
    * Tail(): Returns a pointer to the tail node.
    * NodeCount(): Returns the total number of nodes.
    * Find(): Finds the first node with the specified data.
    * FindAll(): Finds all nodes with the specified data.
    * GetNode(): Returns the node at the specified index.
  * Insertion:
    * AddHead(): Adds a node at the head.
    * AddTail(): Adds a node at the tail.
    * AddNodesHead(): Adds multiple nodes at the head.
    * AddNodesTail(): Adds multiple nodes at the tail.
    * InsertAt(): Inserts a node at the specified index.
    * InsertBefore(): Inserts a node before the specified node.
    * InsertAfter(): Inserts a node after the specified node.
  * Removal:
    * RemoveHead(): Removes the head node.
    * RemoveTail(): Removes the tail node.
    * RemoveAt(): Removes the node at the specified index.
    * Remove(): Removes nodes with the specified data.
    * Clear(): Removes all nodes.
  * Behaviors:
    * PrintForward(): Prints the list from head to tail.
    * PrintReverse(): Prints the list from tail to head.
    * PrintForwardRecursive(): Recursively prints the list from head to tail.
    * PrintReverseRecursive(): Recursively prints the list from tail to head.
  * Operators:
    * Assignment operator
    * Equality operator
    * Subscript operator
### sf_labs
This directory contains various small C++ projects and exercises, including:

  * NovTemps.txt: Temperature readings for November.
  * Sales.txt: Sales data for analysis.
  * dice.cpp: A game of chance simulation using object-oriented principles.
  * logicalOperators.cpp: A program to determine book club points based on books purchased.
  * logicalSales.cpp: A program to find the division with the highest sales.
  * percentages.cpp: A program to calculate and display the percentage of male and female students in a class.
  * salesChart.cpp: A program to read sales data and display it as a bar chart.

### umich_projects
This directory contains projects done as part of coursework at the University of Michigan, including:

#### project1:

brakeCoef.cpp: Calculates the optimal braking coefficient for a shuttle given initial velocity, air braking coefficient, and stopping distance.

#### project2:

evaluateReviews.cpp: Evaluates reviews and classifies them as truthful or deceptive based on keyword weights.
reviews.cpp & reviews.h: Helper functions and declarations for evaluating reviews.

#### project3:

planRoute.cpp: Plans the shortest route for a gLyft driver to visit planets based on their locations and names.
