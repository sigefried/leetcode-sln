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

bool isOperator(char x) {
  switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
      return true;
  }
  return false;
}

string prefix_to_postfix(string s) {
  stack<string> oprands;
  for(int i = s.size() -1; i >= 0; --i) {
    if(isOperator(s[i])) {
      string ops = string(1, s[i]);
      string a = oprands.top(); oprands.pop();
      string b = oprands.top(); oprands.pop();
      oprands.push(a + b + ops);
    } else {
      oprands.push(string(1,s[i]));
    }
  }
  return oprands.top();
}

string postfix_to_prefix(string s) {
  stack<string> oprands;
  stack<string> ops;
  for(auto ch : s) {
    if(isOperator(ch)) {
      string op = string(1, ch);
      string b = oprands.top(); oprands.pop();
      string a = oprands.top(); oprands.pop();
      oprands.push(op + a + b );
    } else {
      oprands.push(string(1,ch));
    }
  }

  return oprands.top();
}

int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "input: " << pre_exp << endl;
  string posf = prefix_to_postfix(pre_exp);
  cout << "post fix: " <<  posf << endl;
  string pref = postfix_to_prefix(posf);
  cout << "pre fix: " << pref << endl;
	return 0;
}
