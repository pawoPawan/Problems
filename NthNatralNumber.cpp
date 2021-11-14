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
