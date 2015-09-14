#include <string>
#include <iostream>
using namespace std;

void Perm ( string fixedPart, string permPart )
{
   if (permPart == "")
   {
      cout << fixedPart << endl;
   }
   else
   {
      for (int i = 0; i < permPart.length(); i++)
      {
         Perm(fixedPart + permPart[i], permPart.substr(0, i) + permPart.substr(i + 1, permPart.length() - 1));
      }
   }
}


void main()
{

   // Don't touch main!!!

   string s;

   cout << "Enter a String: ";
   cin >> s;
   cout << s << endl;

   cout << "Perms are: " << endl;
   Perm( "", s );

}


