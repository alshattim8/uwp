#include "Company.h"
#include "LeakWatcher.h"

Company::Company()
{
   name = NULL;
}

Company::Company( const Company & toCopy )
{
   int arraySize = 0;
   for ( int i = 0; i < MAX_NAME_LEN && toCopy.name[i] != '0'; i++ )
      arraySize++;
   arraySize++;
   name = new char[arraySize];
   for ( int i = 0; i < arraySize; i++ )
      name[i] = toCopy.name[i];
   for ( int i = 0; i < PHONE_LEN; i++ )
      phone[i] = toCopy.phone[i];
}

Company::~Company()
{
   delete name;
}

Company & Company::operator=( const Company & rhs )
{
   if ( *this != rhs )
   {
      delete name;
      int arraySize = 0;
      for ( int i = 0; i < MAX_NAME_LEN && rhs.name[i] != '0'; i++ )
         arraySize++;
      arraySize++;
      name = new char[arraySize];
      for ( int i = 0; i < arraySize; i++ )
         name[i] = rhs.name[i];
      for ( int i = 0; i < PHONE_LEN; i++ )
         phone[i] = rhs.phone[i];
   }
   return *this;
   
}

bool  Company::operator<( const Company & toCompare ) const
{
   for ( int i = 0; name[i] != '0' && toCompare.name[i] != '0'; i++ )
   {
      if ( name[i] < toCompare.name[i] )
         return true;
      else if ( name[i] > toCompare.name[i] )
         return false;
   }
   return false;
}

bool  Company::operator==( const Company & toCompare ) const
{
   for ( int i = 0; i < MAX_NAME_LEN; i++ )
   {
      if ( name[i] != '0' && toCompare.name[i] != '0' )
      {
         if ( name[i] != toCompare.name[i] )
            return false;
      }
      else if ( name[i] == '0' && toCompare.name[i] == '0' )
         return true;
      else
         return false;
   }
   return false;
   
}

bool  Company::operator!=( const Company & toCompare ) const
{
   return !( operator==( toCompare ) );
}

ostream& operator<<( ostream& out, const Company & toOut )
{
   int count = 0;
   for ( int i = 0; toOut.name[i] != '0'; i++ )
   {
      out << toOut.name[i];
      count++;
   }
   out << setiosflags(ios::left) << setw( toOut.MAX_NAME_LEN 
      - count + 1 );
   out << ' ';
   for ( int i = 0; i < toOut.PHONE_LEN; i++ )
      out << toOut.phone[i];
   return out;
}

istream& operator>>( istream& in, Company & toIn )
{
   int maxSize = toIn.MAX_NAME_LEN + 1;
   int bufferSize = 0; 
   char * buffer = new char[maxSize];
   bool loop = true;
   in >> *buffer;
   in.putback( *buffer );
   for ( int i = 0; i < maxSize && loop; i++ )
   {
      bufferSize++;
      char got;
      in.get(got);
      buffer[i] = got;
      if ( buffer[i] == ' ' )
      {
         buffer[i] = '0';
         loop = false;
      }
   }
   delete toIn.name;
   toIn.name = new char[bufferSize];
   for ( int i = 0; i < bufferSize; i++ )
      toIn.name[i] = buffer[i];
   delete buffer;
   const int phoneSize = toIn.PHONE_LEN;
   char phoneBuffer[phoneSize];
   in >> *phoneBuffer;
   in.putback(*phoneBuffer);
   for ( int i = 0; i < toIn.PHONE_LEN; i++ )
      in >> toIn.phone[i];
   in.ignore( toIn.MAX_IGNORE_LEN, '\n' );
   return in;
}

#ifdef TESTING_COMPANY

void main()
{
   cout << "begin testing" << endl;
   Company test1, test2, *test3;
   cout << "enter a company (test1): " << endl;
   cin >> test1;
   cout << test1 << endl;
   cout << "enter a company that is ahead of the previous company "
      << "alphabetically (test2): " << endl;
   cin >> test2;
   cout << test2 << endl;
   cout << "test1 < test2: expected result: 0. Result: " 
      << ( test1 < test2 ) << endl;
   cout << "test2 < test1: expected result: 1. Result: " 
      << ( test2 < test1 ) << endl;
   cout << "test2 == test1: expected result: 0. Result: " 
      << ( test2 == test1 ) << endl;
   cout << "test2 != test1: expected result: 1. Result: " 
      << ( test2 != test1 ) << endl;
   cout << "test1 = test2" << endl;
   test1 = test2;
   cout << test1 << endl;
   cout << test2 << endl;
   cout << "test1 < test2: expected result: 0. Result: " 
      << ( test1 < test2 ) << endl;
   cout << "test2 < test1: expected result: 0. Result: " 
      << ( test2 < test1 ) << endl;
   cout << "test2 == test1: expected result: 1. Result: " 
      << ( test2 == test1 ) << endl;
   cout << "test2 != test1: expected result: 0. Result: " 
      << ( test2 != test1 ) << endl;
   cout << "test3 = Company(test2)" << endl;
   test3 = new Company( test2 );
   cout << "test3 == test2: expected result: 1. Result: "
      << ( *test3 == test2 ) << endl;
   cout << "end of tests" << endl;
}

#endif   // #ifdef TESTING_COMPANY