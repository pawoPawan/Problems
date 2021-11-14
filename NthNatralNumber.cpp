#include <iostream>
using namespace std;

#define lli long long

lli FindNthNaturalNumberAfterExcludingNumberContainingDigit9(lli N);

int main()
{
  lli nNum = 0;
  cout << "Enter a Number: ";
  cin >> nNum;
  cout << "Nth Natural number after excluding 9: " << FindNthNaturalNumberAfterExcludingNumberContainingDigit9(nNum) << endl;
}

lli FindNthNaturalNumberAfterExcludingNumberContainingDigit9(lli N)
{
  lli ret;
  for(lli i = 1; N > 0; i *= 10)
  {
    ret += i * (N%9);
    N = N/9;
  }
  return ret;
}

/*
It is known that, digits of base 2 numbers varies from 0 to 1. 
Similarly, digits of base 10 numbers varies from 0 to 9.
Therefore, the digits of base 9 numbers will vary from 0 to 8.
It can be observed that Nth number in base 9 is equal to Nth number after skipping numbers containing digit 9.
So the task is reduced to find the base 9 equivalent of the number N 

Time Complexity: O(log9 N)
Auxiliary Space: O(1)
*/
