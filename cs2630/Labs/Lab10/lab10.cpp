// CS 2630 Lab 10  F13
// Finish the Do's
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

// Do1: Finish the function object to compare two strings.
//      Return true if the first string is smaller than the second;
//      return false otherwise.
class StringLessThan
{
public:
   template <class t>
   bool operator() (t& str1, t& str2)
   {
      return str1.compare(str2) < 0;
   }
};

typedef set<string, less<string>> TSet1;
typedef set<string, StringLessThan> TSet2;

void STL_Set_Manips()
{
   TSet1 s1;
   TSet2 s2;

   string str;
	cin >> str;
	while ( str != "EndS1" )
	{
		s1.insert( str );
		cin >> str;
	}
	cin >> str;
	while ( str != "EndS2" )
	{
		s2.insert( str );
		cin >> str;
	}

   // print out all the elements of s1
   TSet1::iterator iter1;
   for ( iter1 = s1.begin(); iter1 != s1.end(); iter1++ )
      cout << *iter1 << " ";
   cout << endl;

   // Do2: add all the elements of s2 to s1
   
   TSet2::iterator iter;
   for (iter = s2.begin(); iter != s2.end(); iter++)
   {
      s1.insert(*iter);
   }
   
   
   
	// print out all the elements of s1
   for ( iter1 = s1.begin(); iter1 != s1.end(); iter1++ )
      cout << *iter1 << " ";
   cout << endl;

	cin >> str;
   // Do3: erase all the elements of s1 from the 
   //      beginning up to and including str.
   //      If str is not in s1, do nothing.	
   
   TSet1::iterator iter2 = s1.begin();
   TSet1::iterator iter3 = iter2;
   bool isDone = false;
   TSet1::iterator found = s1.find(str);
   
   if (found != s1.end())
   {
      while (iter2 != found)
      {
         iter2++;
         s1.erase(iter3);
         iter3 = iter2;
      }
      s1.erase(found);
   }
   
   

	// print out all the elements of s1
   for ( iter1 = s1.begin(); iter1 != s1.end(); iter1++ )
      cout << *iter1 << " ";
   cout << endl;
}
 

typedef pair<int, int> Int_Pair;

void STL_Map_Manips()
{
   map<int,int> m;

   // Do4: Make m a lookup table for squares of 0 to 9
   
   for (int i = 0; i < 10; i++)
   {
      m.insert(Int_Pair(i, i * i));
   }
   
   // Do5: print out the whole table
   
   map<int, int>::iterator iter;
   for (iter = m.begin(); iter != m.end(); iter++)
   {
      cout << "Num: " << iter->first << "  Square: " << iter->second << endl;
   }

}

void main()
{
   STL_Map_Manips();
   STL_Set_Manips();
}

