#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList {
   public:
      struct Node {
         Node *prev = nullptr;
         Node *next = nullptr;
         T data;
      };
      /* Constructors & Destructors */
      LinkedList(); 
      ~LinkedList();
      LinkedList(const LinkedList<T> &list);

      /* Accessors */
      Node* Head();
      Node* Tail();
      unsigned int NodeCount() const;
      Node* Find(const T &data) const;
      void FindAll(vector<Node*>& outData, const T &value) const;
      Node* GetNode(unsigned int index);
      const Node* GetNode(unsigned int index) const;

      /* Insertion */      
      void AddHead(const T &data);
      void AddTail(const T &data);
      void AddNodesHead(const T *data,unsigned int count);
      void AddNodesTail(const T *data, unsigned int count);
      void InsertAt(const T& data, unsigned int index);
      void InsertBefore(Node *node, const T &data);
      void InsertAfter(Node *node, const T &data);

      /* Removal */
      bool RemoveHead();
      bool RemoveTail();
      bool RemoveAt(unsigned int index);
      unsigned int Remove(const T&data);
      void Clear();

      /* Behaviors */
      void PrintForward() const;
      void PrintReverse() const;
      void PrintForwardRecursive(const Node* node) const;
      void PrintReverseRecursive(const Node* node) const;

      /* Operators */
      LinkedList<T> &operator=(const LinkedList<T> &rhs);
      bool operator==(const LinkedList<T>& rhs) const;
      T& operator[](unsigned int index);
      const T& operator[](unsigned int index) const;
      
      private:
         Node *nodeHead;
         Node *nodeTail;
         unsigned int nodeCount;
};

/* Default Constructor */
template <typename T>
LinkedList<T>::LinkedList() {
   nodeHead = nullptr;
   nodeTail = nullptr;
   nodeCount = 0;
}

/* Default Destructor */
template <typename T>
LinkedList<T>::~LinkedList() {
   if(nodeCount != 0) {
      for(unsigned int i = 0; i < nodeCount; ++i) {
         Node *deleting = nodeHead;
         nodeHead = deleting->next;
         delete deleting;
      }
   }
   nodeHead = nullptr;
   nodeTail = nullptr;
   nodeCount = 0;
}

/* Copy Constructor. Constructs a new Linked List by copying the values of a given Linked List */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
   nodeHead = nullptr;
   nodeTail = nullptr;
   nodeCount = 0;
   Node *_node = list.nodeHead;
   for (unsigned int i = 0; i < list.nodeCount; ++i) {
      AddTail(_node->data);
      _node = _node->next;
   }
}

/* Returns Head pointer */
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
   return nodeHead;
}

/* Returns Tail pointer */
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
   return nodeTail;
}

/* Returns the total node count for the list */
template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
   return nodeCount;
}

/* Find the first node with a data value matching the passed in parameter,
returning a pointer to that node. Returns nullptr if no matching node found.  */
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T &data) const {
   bool stop = false;
   unsigned int i = 1;
   Node *_node = nodeHead;

   while(!stop) {
      if (_node->data == data)
      {
         stop = true;
         return _node;
      }
      else if(i == nodeCount) {
         stop = true;
         return nullptr;
      }
      _node = _node->next;
      ++i;
   }
   return nullptr;
}

/* Find all nodes which match the passed in parameter value, and store a pointer to
that node in the passed in vector. Use of a parameter like this (passing a
something in by reference, and storing data for later use) is called an output
parameter. */
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T &value) const {
   Node *_node = nodeHead;
   for (unsigned int i = 1; i <= nodeCount; i++)
   {
      if (_node->data == value)
      {
         outData.push_back(_node);
      }
      _node = _node->next;
   }
}

/* Given an index, return a pointer to the node at that index. Throws an exception
of type out_of_range if the index is out of range.  */
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
   if(index >= nodeCount) 
      throw out_of_range("index is out of range");
   Node *_node = nodeHead;
   for(unsigned int i = 1; i < index; ++i) {
      _node = _node->next;
   }
   return _node;
}

/* const version of GetNode */
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
   if(index >= nodeCount) 
      throw out_of_range("index is out of range");
   Node *_node = nodeHead;
   for(unsigned int i = 1; i < index; ++i) {
      _node = _node->next;
   }
   return _node;
}

/* Create a new Node at the front of the list to store the passed in parameter */
template <typename T>
void LinkedList<T>::AddHead(const T &data) {
   if(nodeHead == nullptr) {
      Node *_node = new Node();
      _node->data = data;
      nodeHead = _node;
      nodeTail = _node;
      ++nodeCount;
   }
   else
   {
      Node *_node = new Node();
      _node->data = data;
      nodeHead->prev = _node;
      _node->next = nodeHead;
      nodeHead = _node;
      ++nodeCount;
   }  
}

/* Create a new Node at the end of the list to store the passed in parameter */
template <typename T>
void LinkedList<T>::AddTail(const T &data) {
   if(nodeTail == nullptr) {
      Node *_node = new Node();
      _node->data = data;
      nodeHead = _node;
      nodeTail = _node;
      ++nodeCount;
   }
   else {
      Node *_node = new Node();
      _node->data = data;
      nodeTail->next = _node;
      _node->prev = nodeTail;
      nodeTail = _node;
      ++nodeCount;
   }
}

/* Given an array of values, insert a node for each of those at the beginning of the
list, maintaining the original order. */
template <typename T>
void LinkedList<T>::AddNodesHead(const T *data,unsigned int count) {
   for(unsigned int i = 1; i < count + 1; ++i) {
      AddHead(data[count - i]);
   }
}

/* Given an array of values, insert a node for each of those at the end of the
list, maintaining the original order. */
template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
   for(unsigned int i = 0; i < count; ++i) {
      AddTail(data[i]);
   }
}

/*Inserts a new Node to store the first parameter, at the index-th location. So if
you specified 3 as the index, the new Node should have 3 Nodes before it.
Throws an out_of_range exception if given an invalid index*/
template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
   Node *_node = nodeHead;
   if(index == 0)
      AddHead(data);
   else if(index == nodeCount)
      AddTail(data);
   else {
      for(unsigned int i = 0; i < index-1; ++i) {
      _node = _node->next;
      }
      Node *newNode = new Node();
      newNode->data = data;
      newNode->prev = _node;
      newNode->next = _node->next;
      _node->next = newNode;
      newNode->next->prev = newNode;
      ++nodeCount;
   }
}

/*Given a pointer to a node, create a new node to store the passed in value, after
the indicated node before the given node*/
template <typename T>
void LinkedList<T>::InsertBefore(Node *node, const T &data) {
   Node *_node = nodeHead;
   for(unsigned int i = 1; i < nodeCount; ++i) {
      if(_node == node)
         InsertAt(data, i-1);
      _node = _node->next;
   }
}

/*Given a pointer to a node, create a new node to store the passed in value, after
the indicated node after the given node*/
template <typename T>
void LinkedList<T>::InsertAfter(Node *node, const T &data) {
   Node *_node = nodeHead;
   for(unsigned int i = 1; i < nodeCount; ++i) {
      if(_node == node)
         InsertAt(data, i);
      _node = _node->next;
   }
}

/* Deletes the first Node in the list. Returns whether or not the Node was removed. */
template <typename T>
bool LinkedList<T>::RemoveHead() {
   if(nodeCount == 0 || nodeHead == nullptr) {
      return false;
   }
   else if(nodeCount == 1) {
      Clear();
      return true;
   }
   else {
      Node *_node = nodeHead;
      nodeHead = _node->next;
      delete _node;
      nodeHead->prev = nullptr;
      --nodeCount;
      return true;
   }
}

/* Deletes the last Node, returning whether or not the operation was successful */
template <typename T>
bool LinkedList<T>::RemoveTail() {
   if(nodeCount == 0 || nodeTail == nullptr)
      return false;
   else if(nodeCount == 1) {
      Clear();
      return true;
   }
   else {
      Node *_node = nodeTail;
      nodeTail = _node->prev;
      delete _node;
      nodeTail->next = nullptr;
      --nodeCount;
      return true;
   }
}

/*Deletes the index-th Node from the list, returning whether or not the operation
was successful*/
template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
   if(nodeCount == 0 || index < 0 || index > nodeCount)
      return false;
   else if(index == 0) {
      RemoveHead();
      return true;
   }
   else if(index == nodeCount-1) {
      RemoveTail();
      return true;
   }
   else {
      Node *_node = nodeHead;
      for(unsigned int i = 0; i < index; ++i) {
         _node = _node->next;
      }
      _node->prev->next = _node->next;
      _node->next->prev = _node->prev;
      delete _node;
      --nodeCount;
      return true;
   }
}

/*Remove all Nodes containing values matching that of the passed-in parameter.
Returns how many instances were removed*/
template <typename T>
unsigned int LinkedList<T>::Remove(const T &data) {
   Node *_node = nodeHead;
   unsigned int instances = 0;
   unsigned int count = nodeCount;
   for(unsigned int i = 0; i < count; ++i) {
      if(_node->data == data) {
         if(i == 0) {
            _node = _node->next;
            RemoveHead();
         }
         else if(i == count-1) {
            RemoveTail();
         }
         else {
            _node->prev->next = _node->next;
            _node->next->prev = _node->prev;
            Node *deleting = _node;
            _node = _node->next;
            --nodeCount;
            delete deleting;
         }
         ++instances;
      }
      else {
         _node = _node->next;
      }
   }
   return instances;
}

/* Deletes all Nodes. */
template <typename T>
void LinkedList<T>::Clear() {
   if(nodeCount != 0) {
      for(unsigned int i = 0; i < nodeCount; ++i) {
         Node *deleting = nodeHead;
         nodeHead = deleting->next;
         delete deleting;
      }
   }
   nodeHead = nullptr;
   nodeTail = nullptr;
   nodeCount = 0;
}

/* Iterator through all of the nodes from head to tail and prints out their values, one a time. */
template <typename T>
void LinkedList<T>::PrintForward() const {
   Node *ptr = nodeHead;
   for(unsigned int i = 0; i < nodeCount; ++i) {
      cout << ptr->data << endl;
      ptr = ptr->next;
   }
}

/* Iterator through all of the nodes from tail to head and prints out their values, one a time. */
template <typename T>
void LinkedList<T>::PrintReverse() const {
   Node *ptr = nodeTail;
   for(unsigned int i = 0; i < nodeCount; ++i) {
      cout << ptr->data << endl;
      ptr = ptr->prev;
   }
}

/*This function takes in a pointer to a Node—a starting node. From that node,
recursively visit each node that follows, in forward order, and print their values.
This function MUST be implemented using recursion, or tests using it will be
worth no points. Check your textbook for a reference on recursion.*/
template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node *node) const {
   Node *ptr = node->next;
   cout << node->data << endl;
   while(ptr != nullptr) {
      cout << ptr->data << endl;
      ptr = ptr->next;
   }      
}

/*Same deal as PrintForwardRecursive, but in reverse.*/
template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node *node) const {
   Node *ptr = node->prev;
   cout << node->data << endl;
   while(ptr != nullptr) {
      cout << ptr->data << endl;
      ptr = ptr->prev;
   }
}

/* Assignment operator.  */
template <typename T>
LinkedList<T>&LinkedList<T>::operator=(const LinkedList<T> &rhs) {
   if(nodeCount != 0) {
      for(unsigned int i = 0; i < nodeCount; ++i) {
         Node *deleting = nodeHead;
         nodeHead = deleting->next;
         delete deleting;
      }
   }
   nodeHead = nullptr;
   nodeTail = nullptr;
   nodeCount = 0;
   Node *_node = rhs.nodeHead;
   for (unsigned int i = 0; i < rhs.nodeCount; ++i) {
      AddTail(_node->data);
      _node = _node->next;
   }   
   return *this;
}

/* Overloaded equality operator. */
template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
   Node *_node = nodeHead;
   Node *rhs_node = rhs.nodeHead;
   if(this->nodeCount != rhs.nodeCount)
      return false;
   for(unsigned int i = 0; i < nodeCount; ++i) {
      if (rhs_node->data == _node->data)
      {
         rhs_node = rhs_node->next;
         _node = _node->next;
      }
      else
      {
         return false;
      }
   }
   return true;  
}

/* Overloaded subscript operator. Takes an index, and returns data from the indexth node. Throws an out_of_range exception for an invalid index.  */
template <typename T>
T&LinkedList<T>::operator[](unsigned int index) {
   Node *_node = GetNode(index);
   return _node->data;
}

/* const version */
template <typename T>
const T&LinkedList<T>::operator[](unsigned int index) const {
   Node *_node = GetNode(index);
   return _node->data;
}