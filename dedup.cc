//TYPE
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))


const int INF = 0x3f3f3f3f;
const int SZ = 100;

string removeDup(string s) {
  int low = 0, high = 0;
  while(high < s.size() ) {
    if(low == 0) {
      s[low++] = s[high];
    } else {
      if(s[low-1] == s[high]) {
        low--;
      } else {
        s[low++] = s[high];
      }
    }
    high++;
  }
  return s.substr(0, low);
}

int main()
{
  string str1  = "geeksforgeeg";
  cout << removeDup(str1) << endl;

  string str2 = "azxxzy";
  cout << removeDup(str2) << endl;

  string str3 = "aaaabbbbdddd";
  cout << removeDup(str3) << endl;
  string str4 = "acaaaaacdddd";
  cout << removeDup(str4) << endl;
}
