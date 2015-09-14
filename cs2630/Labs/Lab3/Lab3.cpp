//---------------------------------------------------------------------
//  Lab3 - Fix all the memory problems!
//  You are only allowed to modify "Buggy".  Don't touch anything else!
//  Also, you cannot modify the portion of Buggy between the marked
//  comments.  You can make changes to Buggy before and after it.
//---------------------------------------------------------------------

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "LeakWatcher.h"

struct Node
{
   int info;
   Node * next;
   Node ( int x, Node * p = NULL ) { info = x;  next = p; }
};

void Buggy()
{
   const int NUM_ELE = 3;
   char buff[6];
   int a[NUM_ELE] = { 4, 5, 6 };

   strcpy ( buff, "Hello" );
   a[NUM_ELE - 1] = 7;            // Assign last element of a to 7


   //-------------------------------------------------------
   // Start of unmodifiable section of Buggy.
   //-------------------------------------------------------
   Node * list = new Node(8);
   list->next = new Node( 9, new Node(10) );
   for ( int i = 0; i < NUM_ELE; i++ )
      cout << i << ": " << a[i] << endl;
   cout << buff << endl;
   Node * p = list;
   while ( p != NULL )
   {
      cout << p->info << endl;
      p = p->next ;
   }
   //-------------------------------------------------------
   // End of unmodifiable section of Buggy.
   //-------------------------------------------------------

   Node * z = list;
   z = z->next;
   while (z != NULL)
   {
      delete list;
      list = z;
      z = z->next;
   }
   delete list;
}

int main()
{
   //-------------------------------------------------------
   // Don't touch any of this!
   //-------------------------------------------------------

   _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE ); 
   _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT ); 
   _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE ); 
   _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT ); 
   _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE ); 
   _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT ); 

   try
   {
      Buggy();
   }
   catch ( ... )
   {
      cout << "Uncaught Exception" << endl;
   }

   _CrtDumpMemoryLeaks();

   return 0;
}
