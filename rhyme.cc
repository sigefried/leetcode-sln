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

map<string, int> cnt;

vector<string> find_rhyme(int n) {
  if(n == 1) {
    cnt["A"] = 1;
    return {"A"};
  }
  auto sub = find_rhyme(n - 1);
  vector<string> ret;
  for(auto s : sub) {
    for(int i = 0; i < cnt[s]; ++i) {
      string n = s;
      n.push_back('A'+i);
      ret.push_back(n);
      cnt[n] = cnt[s];
    }
    string n = s;
    n.push_back('A' + cnt[s]);
    cnt[n] = cnt[s] + 1;
    ret.push_back(n);
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<string> ret = find_rhyme(n);
  for(auto s : ret) {
    cout << s << endl;
  }
	return 0;
}
