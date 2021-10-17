//Longest Consecutive 1's
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  //test cases
  cin >> t;
  while (t--)
  {
    int N;
    //size of array
    cin >> N;
    int count = 0;
    int ans = 0;
    while (N > 0)
    {
      if (N % 2 != 0)
      {
        count++;
        ans = max(ans, count);
      }
      else
      {
        count = 0;
      }
      N = N / 2;
    }
    cout << ans;
  }
  return 0;
}