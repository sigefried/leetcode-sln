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

void count_sort(vector<int> &input, int b) {
  vector<int> cnt(10, 0);
  for(auto d : input) {
    int digit = (d / b ) % 10;
    cnt[digit]++;
  }
  for(int i = 1; i < 10; ++i) {
    cnt[i] += cnt[i-1];
  }
  vector<int> tmp = input;
  for(int i = input.size() - 1; i >= 0; --i) {
    int digit = (input[i] / b) % 10;
    tmp[--cnt[digit]] = input[i];
  }

  input.swap(tmp);
}

void radix_sort(vector<int> & input) {
  int largest = *max_element(input.begin(), input.end());
  for(int b = 1; largest / b > 0; b *= 10) {
    count_sort(input, b);
  }
}

int main() {
  vector<int> tmp = {170, 45, 75, 90, 802, 24, 2, 66};
  radix_sort(tmp);
  for(auto n : tmp) {
    cout << n << " ";
  }
  cout << endl;
	return 0;
}
