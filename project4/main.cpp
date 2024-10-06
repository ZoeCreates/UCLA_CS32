//// Menu.cpp : Defines the entry point for the console application.
////
//
//#include <iostream>
//#include <string>
//#include <cassert>
//#include "List.h"
//#include "ListNode.h"
//
//using namespace std;
//using namespace cs32;
//
//enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };
//
//CHOICE menu();
//
//int main(int argc, char* argv[]) {
//    
//	string value;
//	List list;
//    List list2;
//
//	CHOICE choice;
//	do {
//		choice = menu();
//		switch( choice ) {
//        case CHOICE::MAKEEMPTY:
//			list.makeEmpty();
//			break;
//        case CHOICE::ISEMPTY:
//			if (list.isEmpty()) {
//				cout << "list is empty" << endl;
//			}
//			else {
//				cout << "list is not empty" << endl;
//			}
//			break;
//        case CHOICE::DELETE:
//			cout << "Please provide a string to remove: ";
//			cin  >> value; 
//			list.deleteItem( value );
//			break;
//        case CHOICE::ADDTOFRONT:
//			cout << "Please provide a string to insert in front: ";
//			cin  >> value; 
//			list.addToFront( value );
//			break;
//        case CHOICE::ADDTOREAR:
//            cout << "Please provide a string to insert in rear: ";
//            cin  >> value;
//            list.addToRear( value );
//            break;
//        case CHOICE::FIND:
//			cout << "Please provide a string to find: ";
//			cin  >> value;
//            cout.setf( ios::boolalpha );
//            cout << list.findItem( value ) << endl;
//            cout.unsetf( ios::boolalpha );
//			break;
//        case CHOICE::PRINT:
//            cout << list.printItems() << endl;;
//			break;
//        case CHOICE::OPERATOR:
//            list2 = list;
//            cout << "second list now:" << endl;
//            cout << list2.printItems() << endl;
//            break;
//        case CHOICE::QUIT:
//            break;
//	}	
//
//	} while (choice != CHOICE::QUIT);
//
//	return( 0 );
//}
//
//CHOICE menu() {
//	string s;
//	CHOICE result;
//	cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
//	cin  >> s;
//    char choice = s.at( 0 );
//	switch( choice ) {
//	case 'M':
//	case 'm':
//		result = CHOICE::MAKEEMPTY;
//		break;
//    case 'D':
//    case 'd':
//        result = CHOICE::DELETE;
//        break;
//	case 'S':
//	case 's':
//		result = CHOICE::ISEMPTY;
//		break;
//    case 'A':
//    case 'a':
//        result = CHOICE::ADDTOFRONT;
//        break;
//	case 'R':
//	case 'r':
//		result = CHOICE::ADDTOREAR;
//		break;
//	case 'F':
//	case 'f':
//		result = CHOICE::FIND;
//		break;
//	case 'Q':
//	case 'q':
//		result = CHOICE::QUIT;
//		break;
//	case 'P':
//	case 'p':
//		result = CHOICE::PRINT;
//		break;
//    case '=':
//        result = CHOICE::OPERATOR;
//        break;
//    default:
//        result = CHOICE::QUIT;
//        break;
//	}
//
//	return( result );
//}




//
//#include <iostream>
//    #include <string>
//    #include <cassert>
//    #include "List.h"
//    #include "ListNode.h"
//
//    int main()
//    {
//           using namespace std;
//        using namespace cs32;
//
//           // test code
//
//           // the get function enables a client to iterate over all elements of a List
//           List l1;
//           assert( l1.min() == "" );
//           l1.addToFront("Hawkeye");
//           l1.addToFront("Thor");
//           l1.addToFront("Hulk");
//           l1.addToFront("Black Widow");
//           l1.addToFront("Iron Man");
//           l1.addToFront("Captain America");
//           for (int k = 0; k < l1.size(); k++)
//           {
//              string x;
//              l1.get(k, x);
//              cout << x << endl;
//           }
//           // should print:
//           // Captain America
//           // Iron Man
//           // Black Widow
//           // Hulk
//           // Thor
//           // Hawkeye
// 
//           assert( l1.position( "Hawkeye" ) == 5 );
//           assert( l1.position( "Thor" ) == 4 );
//           assert( l1.position( "Hulk" ) == 3 );
//           assert( l1.position( "Black Widow" ) == 2 );
//           assert( l1.position( "Iron Man" ) == 1 );
//           assert( l1.position( "Captain America" ) == 0 );
//           assert( l1.position( "Not there" ) == -1 );
//
//           assert( l1.before( "Not there", "Hulk" ) == false );
//           assert( l1.before( "Hulk", "Not there" ) == false );
//           assert( l1.before( "Hulk", "Captain America" ) == false );
//           assert( l1.before( "Black Widow", "Hulk" ) == true );
//           assert( l1.before( "Captain America", "Hulk" ) == true );
//
//           assert( l1.min() == "Black Widow" );
//
//           l1.removeAllBiggerThan( "Happy" );
//           // now just "Captain America", "Black Widow"
//           assert( l1.size() == 2 );
//           assert( l1.position( "Hawkeye" ) == -1 );
//           assert( l1.position( "Thor" ) == -1 );
//           assert( l1.position( "Hulk" ) == -1 );
//           assert( l1.position( "Black Widow" ) == 1 );
//           assert( l1.position( "Iron Man" ) == -1 );
//           assert( l1.position( "Captain America" ) == 0 );
//           assert( l1.position( "Not there" ) == -1 );
//
//           cout << "all tests passed!" << endl;
//           return( 0 );
//    }



#include <iostream>
    #include <string>
    #include <cassert>
    #include "List.h"
    #include "ListNode.h"


int main(){
    using namespace std;
    using namespace cs32;

    List test;
    
      

    
    test.addToRear("A");
    test.addToRear("B");
    test.addToRear("C");
    test.addToRear("D");
    test.addToRear("E");
    test.addToRear("F");
    test.addToRear("G");
    test.addToRear("H");
    test.addToFront("I");

    assert(test.size() == 9);
    
    assert(test.position("B") == 2);
        assert(test.position("D") == 4);
        assert(test.position("I") == 0);
        assert(test.position("H") == 8);
        assert(test.position("M") == -1);
    
        assert(test.min() == "A");


        assert(test.before("D", "E") == true);
        assert(test.before("D", "A") == false);
        assert(test.before("M", "C") == false);
        assert(test.before("C", "M") == false);
    
        string element;
        assert(test.get(1, element) == true);
        assert(element == "A");
        assert(test.get(2, element) == true);
        assert(element =="B");
        assert(test.get(12, element) == false);

        assert(test.min() == "A");

        test.removeAllBiggerThan("B");
        assert(test.size() == 2);
        assert(test.position("A") == 0);
        assert(test.position("B") == 1);


//        cout << "all tests passed!" << endl;
        return( 0 );
    }
