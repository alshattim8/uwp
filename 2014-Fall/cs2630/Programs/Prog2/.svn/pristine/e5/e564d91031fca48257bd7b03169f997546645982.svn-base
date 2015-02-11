#include "LList.h"
#include "LeakWatcher.h"

LList::~LList()
{
   if ( !IsEmpty() )
   {
      Node * p = list->next;
      while ( p != NULL )
      {
         delete list;
         list = p;
         p = p->next;
      }
      delete list;
   }
}

bool LList::IsEmpty() const
{
   return list == NULL;
}

bool LList::Insert( InfoType *x_ptr )
{
   if ( IsEmpty() || *x_ptr < *list->infoPtr )
   {
      list = new Node( x_ptr, list );
      return true;
   }
   else if ( *x_ptr == *list->infoPtr )
      return false;
   else
   {
      Node * p = list;
      while ( p->next != NULL && *p->next->infoPtr < *x_ptr )
      {
         p = p->next;
         if ( *x_ptr == *p->infoPtr )
            return false;
      }
      if ( p->next != NULL && *x_ptr == *p->next->infoPtr )
         return false;
      else
      {
         p->next = new Node( x_ptr, p->next );
         return true;
      }
   }
}

bool LList::Delete( const InfoType & x )
{
   if ( !IsEmpty() )
   {
      Node * p = list;
      if ( x == *p->infoPtr )
      {
         list = list->next;
         delete p;
         return true;
      }
      else
      {
         Node * q = p;
         p = p->next;
         while ( p != NULL )
         {
            if ( x == *p->infoPtr )
            {
               q->next = q->next->next;
               delete p;
               return true;
            }
            p = p->next;
            q = q->next;
         }
      }
   }
   return false;
}

void LList::Display( ostream & out_stream ) const
{
   Node * p = list;
   while ( p != NULL )
   {
      out_stream << *p->infoPtr << endl;
      p = p->next;
   }
}

#ifdef TESTING_LLIST

// --------------------------------------------------------------------
// Test bed main
// --------------------------------------------------------------------
void main()
{
   LList list;
   InfoType *test1 = new Company(), 
      *test2 = new Company(), 
      *test3 = new Company();
   cout << "please enter 3 companies:" << endl;
   cin >> *test1;
   cout << *test1 << endl;
   cin >> *test2;
   cout << *test2 << endl;
   cin >> *test3;
   cout << *test3 << endl;
   cout << "begin testing" << endl;
   cout << "IsEmpty(): expected result: 1. Result: "
      << list.IsEmpty() << endl;
   cout << "Delete( test1 ): expected result: 0. Result: "
      << list.Delete( *test1 ) << endl;
   cout << "Display():" << endl;
   cout << "displaying list" << endl;
   list.Display( cout );
   cout << "Insert( test1 ): expected result: 1. Result: "
      << list.Insert( test1 ) << endl;
   cout << "Insert( test2 ): expected result: 1. Result: "
      << list.Insert( test2 ) << endl;
   cout << "Insert( test3 ): expected result: 1. Result: "
      << list.Insert( test3 ) << endl;
   cout << "Insert( test1 ): expected result: 0. Result: "
      << list.Insert( test1 ) << endl;
   cout << "Insert( test2 ): expected result: 0. Result: "
      << list.Insert( test2 ) << endl;
   cout << "Insert( test3 ): expected result: 0. Result: "
      << list.Insert( test3 ) << endl;
   cout << "displaying list" << endl;
   list.Display( cout );
   cout << "IsEmpty(): expected result: 0. Result: "
      << list.IsEmpty() << endl;
   cout << "Delete( test1 ): expected result: 1. Result: "
      << list.Delete( *test1 ) << endl;
   cout << "Delete( test2 ): expected result: 1. Result: "
      << list.Delete( *test2 ) << endl;
   cout << "Delete( test3 ): expected result: 1. Result: "
      << list.Delete( *test3 ) << endl;
   cout << "Delete( test1 ): expected result: 0. Result: "
      << list.Delete( *test1 ) << endl;
   cout << "Delete( test2 ): expected result: 0. Result: "
      << list.Delete( *test2 ) << endl;
   cout << "Delete( test3 ): expected result: 0. Result: "
      << list.Delete( *test3 ) << endl;
   cout << "displaying list" << endl;
   list.Display( cout );
   cout << "end of tests" << endl;
}

#endif   // #ifdef TESTING_LLIST