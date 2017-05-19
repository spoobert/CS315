#include<iostream>
using namespace std;

int n;
int a[ 10 ];
int Nth[ 1 ]; 

void reverseList( int a[] , int n )
{
  
  
  while( n != 0 )
    {
     
      Nth[1] = a[ n - 1 ];
      a[ n - 1 ] = a[ n - sizeof( a ) / 4 ]; 
      a[ ( n - sizeof( a ) / 4 ) - n ] =  Nth[0];
      return reverseList( a , n - 1);
    }
  
  return;
}

int main()
{

   int a[ 3 ] = {1, 2, 3 };

   cout << "hello world" << endl;
   
   cout << a[ n - sizeof( a ) / 4 ] << endl;
   cout <<  a[ ( n - sizeof( a ) / 4 ) - n ] <<  Nth[0] << endl;
     
   
   

   reverseList( a , 3 );
   cout << sizeof( a )  << endl;
   cout << sizeof( a[0] )  << endl;
   for(int i = 0; i < 3 ; i++)
     cout << a[i] << endl; 
   
   return 0;
}
