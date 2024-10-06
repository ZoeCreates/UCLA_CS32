#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

size_t List::size() const {
    size_t count = 0;
    ListNode* current = head;

    // Traverse the list, counting nodes until reaching the end
    while (current != nullptr) {
        count++;
        current = current->getNext();
    }

    return count;
}


int List::position(const std::string& data) const {
    int index = 0;
    
    
    // Start at the head of the list
    ListNode* current = head;

    // Traverse the list until the end
    while (current != nullptr) {
        if (current->getElement() == data) {
            // If the data is found, return its index
            return index;
        }
        //move to the next node
        current = current->getNext();
        index++;
    }

    // If the data is not found, return -1
    return -1;
}

bool   List::before( const std::string& before, const std::string& after ) const{
    //- If the before value is found on List at a position less than the after value, return true; otherwise, return false.  It is marked const to indicate that the no data members of the List will be changed when implementing this operation.
    int beforeIndex = position(before);
        int afterIndex = position(after);

        // If either 'before' or 'after' string is not found in the list, return false
        if (beforeIndex == -1 || afterIndex == -1) {
            return false;
        }
        // Check if 'before' appears before 'after' in the list
        return beforeIndex < afterIndex;
}

bool List::get(int i, std::string& data) const {
    if (i < 0 || head == nullptr) {
        return false;  // If the list is empty or index is invalid, return false
    }

    ListNode* current = head;
    int index = 0;

    // Traverse the list until in position i
    while (current != nullptr && index < i) {
        current = current->getNext();
        index++;
    }

    if (current != nullptr) {
        data = current->getElement();
        return true;
    }

    return false;  // the position is out of range
}

std::string List::min() const {
    if (head == nullptr) {
        return ""; // Return an empty string if the list is empty
    }
    
    // Initialize with the value of the first node
    std::string minItem = head->getElement();
    // Do iteration starting with the second node
    ListNode* current = head->getNext();

    while (current != nullptr) {
        // compare min so far with new element
        if (current->getElement() < minItem) {
            // Update minItem if a smaller element is found
            minItem = current->getElement();
        }
        current = current->getNext(); // Move to the next node
    }

    return minItem;
}


void List::removeAllBiggerThan( const std::string &data) {
    if (head == nullptr) {
        return;  // do nothing if the list is empty
    }

    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr) {
        if (current->getElement() > data) {
            // If the element is greater than data, we remove it
            if (prev == nullptr) {
                // If the current node is the head node
                ListNode* temp = current;
                head = current->getNext();
                current = head;
                delete temp;
            } else {
                prev->setNext(current->getNext());
                delete current;
                current = prev->getNext();
            }
        } else {
            // If the current node is not to be deleted, move to the next node
            prev = current;
            current = current->getNext();
        }
    }
}









}


