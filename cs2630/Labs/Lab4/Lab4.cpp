// Lab4 - Write the DoIt method as specified in the handout.  
// It has ???? by it.
// You are only allowed to change that method.
// You get 0 if you modify anything else.

#include <iostream>
using namespace std;

typedef int InfoType;

class LList
{
public:
   LList() { list = NULL; }
   ~LList();
   void AddRear( InfoType x );
   void RemoveFront();
   bool IsEmpty() const { return list == NULL; }
   bool DoIt ( InfoType & x ) const;
private:
   struct Node
   {
      InfoType info;
      Node * next;
      Node ( InfoType x, Node * p = NULL ) { info = x;  next = p; }
   };
   Node * list;
};


bool LList::DoIt ( InfoType & x ) const
{
   if (!IsEmpty())
   {
      Node * p = list;
      int count = 0;
      while (p != NULL)
      {
         count++;
         p = p->next;
      }
      if (count == 1)
      {
         x = list->info;
         return true;
      }
      else if (count <= 4)
      {
         x = list->next->info;
         return true;
      }
      else if (count > 4)
      {
         Node * q = list;
         while (q->next != NULL)
         {
            q = q->next;
         }
         x = q->info;
         return true;
      }
      else
      {
         return false;
      }
   }
   else
   {
      return false;
   }
}

LList::~LList()
{
   while ( list != NULL )
   {
      Node * p = list;
      list = list->next;
      delete p;
   }
}

void LList::RemoveFront()
{
   if ( list != NULL )
   {
      Node * p = list;
      list = list->next;
      delete p;
   }
}

void LList::AddRear( InfoType x ) 
{ 
   if( list == NULL )
      list = new Node(x);
   else
   {
      Node * p = list;
      while ( p->next != NULL  )
         p = p->next;
      p->next = new Node(x);
   }
}

void main()
{
   int x = 0;
   LList l;

   for ( int i = 0; i < 10; i++ )
   {
      if ( ! l.DoIt(x) )
         cout << "Not"  << endl;
      else
         cout << x << endl;
      l.AddRear( 2 * i + 1 );
   }
   while( ! l.IsEmpty() )
   {
      if ( ! l.DoIt(x) )
         cout << "Not"  << endl;
      else
         cout << x << endl;
      l.RemoveFront();
   }
   if ( ! l.DoIt(x) )
      cout << "Not"  << endl;
   else
      cout << x << endl;
}
