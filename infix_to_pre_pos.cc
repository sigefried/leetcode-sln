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

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

string infix_to_prefix(string s) {
  stack<char> ops;
  stack<string> operands;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '(') {
      ops.push(s[i]);
    } else if(s[i] == ')') {
      while(!ops.empty() && ops.top() != '(' ) {
        string b = operands.top(); operands.pop();
        string a = operands.top(); operands.pop();
        char op = ops.top(); ops.pop();
        operands.push(string(1,op) + a + b);
      }
      ops.pop();
    } else if (!isOperator(s[i])) {
        operands.push(string(1,s[i]));
    } else {
      while(!ops.empty() && getPriority(s[i]) <=  getPriority(ops.top())) {
        string b = operands.top(); operands.pop();
        string a = operands.top(); operands.pop();
        char op = ops.top(); ops.pop();
        operands.push(string(1,op) + a + b);
      }
      ops.push(s[i]);
    }
  }
//  cout << "final ops size: " << ops.size() << endl;
  while(!ops.empty()) {
    string b = operands.top(); operands.pop();
    string a = operands.top(); operands.pop();
    char op = ops.top(); ops.pop();
    operands.push(string(1,op) + a + b);
  }
  return operands.top();
}

void do_pop(stack<string> &operands, stack<char>&ops) {
  string b = operands.top(); operands.pop();
  string a = operands.top(); operands.pop();
  char op = ops.top(); ops.pop();
  operands.push(a + b + string(1,op));
}

string infix_to_posfix(string s) {
  stack<char> ops;
  stack<string> operands;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '(') {
      ops.push(s[i]);
    } else if(s[i] == ')') {
      while(!ops.empty() && ops.top() != '(' ) {
        do_pop(operands,ops);
      }
      ops.pop();
    } else if (!isOperator(s[i])) {
        operands.push(string(1,s[i]));
    } else {
      while(!ops.empty() && getPriority(s[i]) <=  getPriority(ops.top())) {
        do_pop(operands,ops);
      }
      ops.push(s[i]);
    }
  }
  cout << "final ops size: " << ops.size() << endl;
  while(!ops.empty()) {
    do_pop(operands,ops);
  }
  return operands.top();
}

int main() {
  string infix0 = "a+b*c^d";
  cout << "in fix: " <<  infix0 << endl;
  string prefix0 = infix_to_prefix(infix0);
  cout << "prefix fix: " << prefix0 << endl;
  string postfix0 = infix_to_posfix(infix0);
  cout << "post fix: " << postfix0 << endl;
  string infix1 = "a+b*(c^d-e)^(f+g*h)-i";
  cout << "in fix: " <<  infix1 << endl;
  string prefix1 = infix_to_prefix(infix1);
  cout << "prefix fix: " << prefix1 << endl;
  string postfix1 = infix_to_posfix(infix1);
  cout << "post fix: " << postfix1 << endl;
  string infix2 = "(A-B/C)*(A/K-L)";
  cout << "in fix: " <<  infix2 << endl;
  string prefix2 = infix_to_prefix(infix2);
  cout << "prefix fix: " << prefix2 << endl;
  string postfix2 = infix_to_posfix(infix2);
  cout << "post fix: " << postfix2 << endl;
	return 0;
}
