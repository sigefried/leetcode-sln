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

string prefix_to_infix(string s) {
  stack<string> oprands;
  for(int i = s.size() -1; i >= 0; --i) {
    if(isOperator(s[i])) {
      string ops = string(1, s[i]);
      string a = oprands.top(); oprands.pop();
      string b = oprands.top(); oprands.pop();
      oprands.push("(" + a + ops +  b + ")");
    } else {
      oprands.push(string(1,s[i]));
    }
  }
  return oprands.top();
}

string postfix_to_infix(string s) {
  stack<string> oprands;
  for(auto ch : s) {
    if(isOperator(ch)) {
      string op = string(1, ch);
      string b = oprands.top(); oprands.pop();
      string a = oprands.top(); oprands.pop();
      oprands.push( "(" + a + op + b + ")");
    } else {
      oprands.push(string(1,ch));
    }
  }

  return oprands.top();
}

int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "pre fix: " << pre_exp << endl;
  string infix = prefix_to_infix(pre_exp);
  cout << "in fix: " <<  infix << endl;
  string pos_exp = "ABC/-AK/L-*";
  infix = postfix_to_infix(pos_exp);
  cout << "in fix: " <<  infix << endl;
	return 0;
}
