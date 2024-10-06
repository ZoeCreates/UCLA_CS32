#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

template <typename Type>
Deque<Type>::Deque() : head(nullptr), tail(nullptr)
{
    // TODO: CS 32 Students to complete code here
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    return head == nullptr;
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    while(!isEmpty()){
        deleteFront();
    }
}


template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    DequeNode<Type> *newNode = new DequeNode<Type>(data, head, nullptr);
    if (isEmpty()) {
        tail = newNode; // If deque was empty, new node is also the tail
    } else {
        head->setPrevious(newNode); // Link existing head to new head
    }
    head = newNode; // New node is now the head
}


template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    DequeNode<Type> *newNode = new DequeNode<Type>(data,nullptr, tail);
    if(isEmpty()){
        head = newNode;
    }
    else{
        tail -> setNext(newNode);
    }
    tail = newNode;
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    if(!isEmpty()){
        DequeNode<Type> *oldHead = head;
        head = head -> getNext();
        if (head){
            head -> setPrevious(nullptr);
        }
        else{
            tail = nullptr;
        }
        delete oldHead;
    }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    for (DequeNode<Type> *current = head; current != nullptr; current = current->getNext()) {
               if (current->getElement() == data) {
                   if (current == head) {
                       deleteFront();
                   } else if (current == tail) {
                       deleteRear();
                   } else {
                       current->getPrevious()->setNext(current->getNext());
                       current->getNext()->setPrevious(current->getPrevious());
                       delete current;
                   }
                   return true;
               }
           }
           return false; // Item not found

   
}



template <typename Type>
Type Deque<Type>::front( ) const
{
    if(isEmpty()){
        return Type();
    }
    Type result = head->getElement();
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    if(isEmpty()){
        return Type();
    }
    Type result = tail->getElement();
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (!isEmpty()) {
            DequeNode<Type> *oldTail = tail;
            if (head == tail) { // Only one element.
                head = nullptr;
                tail = nullptr;
            } else { // More than one element.
                tail = oldTail->getPrevious();
                tail->setNext(nullptr);
            }
            delete oldTail; // Delete the old tail node.
        }

}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{

    std::stringstream ss;
      for (DequeNode<Type>* current = head; current != nullptr; current = current->getNext()) {
          ss << to_string(current->getElement());
          if (current->getNext() != nullptr) {
              ss << " "; // Add a space between items, but not after the last item
          }
      }
      return ss.str();
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    if(this!=&rhs){
        makeEmpty();
        for(DequeNode<Type> *current = rhs.head; current!= nullptr; current = current -> getNext()){
            addToRear(current -> getElement());
        }
        return *this;
    }

	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    for(DequeNode<Type> *current = head; current!= nullptr; current = current -> getNext()){
        result++;
    }

    return( result );
}





//should set the value of the parameter data to be the element located at position i of the Deque (if that position exists) and return true if the position exists; otherwise, return false.  It is marked const to indicate that the no data members of the Deque will be changed when implementing this operation.
template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    if(i<0){
        return false;
    }
    int index = 0;
    for(DequeNode<Type>*current = head; current!= nullptr; current = current -> getNext()){
        if(index ==i){
            data= current -> getElement();
            return true;
        }
        index++;
    }

    return( false );
}

}


#endif
