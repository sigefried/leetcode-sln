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

void print_board(vector<vector<int>> &board, pair<int, int> start, pair<int,int> end) {
  int n = board.size();
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i == start.first && j == start.second) {
        cout << 's';
      } else if(i == end.first && j == end.second) {
        cout << 'e';
      }
      else if(board[i][j] == 0) {
        cout << '#';
      } else if(board[i][j] == 1) {
        cout << 'x';
      } else if(board[i][j] == 2) {
        cout << '*';
      } else {
        cout << '!';
      }
    }
    cout << endl;
  }
}

vector<vector<int>> init_board(int n) {
  vector<vector<int>> board(n, vector<int>(n ,0));
  for(int i = 1 ; i < n; i += 2) {
    for(int j = 1; j < n; j += 2) {
      board[i][j] = 1;
    }
  }
  return board;
}

vector<char> get_valid_move(vector<vector<int>> &board, pair<int,int> cur) {
  vector<char> ret;
  int n = board.size();
  int x = cur.first;
  int y = cur.second;
  //up
  if(x - 2 > 0 && board[x-2][y] == 1) {
    ret.push_back('U');
  }
  //down
  if(x + 2 < n - 1 && board[x+2][y] == 1) {
    ret.push_back('D');
  }

  //left
  if(y - 2 > 0 && board[x][y-2] == 1) {
    ret.push_back('L');
  }
  //right
  if(y + 2 > 0 && board[x][y+2] == 1) {
    ret.push_back('R');
  }
  return ret;
}

void dfs_gen(vector<vector<int>> &board, pair<int,int> cur, pair<int, int> end) {
  board[cur.first][cur.second] = 2;
  if(cur == end) return;
  vector<char> valid_move = get_valid_move(board, cur);
  int x = cur.first, y = cur.second;
  while(!valid_move.empty()) {
    int idx = rand() % valid_move.size();
    //cout << idx << endl;
    char mv = valid_move[idx];
    if(mv == 'L') {
      pair<int,int> nxt = {x, y - 2};
      board[x][y-1] = 2;
      board[x][y-2] = 2;
      dfs_gen(board, nxt,end);
    } else if( mv == 'R' ) {
      pair<int,int> nxt = {x, y + 2};
      board[x][y+1] = 2;
      board[x][y+2] = 2;
      dfs_gen(board, nxt,end);

    } else if(mv == 'U') {
      pair<int,int> nxt = {x - 2, y};
      board[x-1][y] = 2;
      board[x-2][y] = 2;
      dfs_gen(board, nxt,end);

    } else if(mv == 'D') {
      pair<int,int> nxt = {x + 2, y};
      board[x+1][y] = 2;
      board[x+2][y] = 2;
      dfs_gen(board, nxt,end);
    }
    valid_move = get_valid_move(board, cur);
  }
}

void prim_gen(vector<vector<int>> &board, pair<int,int> cur, pair<int, int> end) {
  vector<pair<int, int>> tmp = {cur};
  int n = board.size();
  while(tmp.size() > 0) {
    int node_idx = rand() % tmp.size();
    auto cur_node = tmp[node_idx];
    //cout << cur_node.first << " " << cur_node.second << endl;
    tmp.erase(tmp.begin() + node_idx);
    if(board[cur_node.first][cur_node.second] == 2) continue;
    board[cur_node.first][cur_node.second] = 2;
    // push next and get edge
    vector<char> valid_connect;
    if(cur_node.first - 2 > 0) {
      if(board[cur_node.first - 2][cur_node.second] == 2) {
        valid_connect.push_back('U');
      } else if(board[cur_node.first - 2][cur_node.second] == 1) {
        tmp.push_back({cur_node.first - 2, cur_node.second});
        //cout << "aaa" << board[cur_node.first - 2][cur_node.second] << endl;
      }
    }
    if(cur_node.first + 2 < n) {
      if(board[cur_node.first + 2][cur_node.second] == 2) {
        valid_connect.push_back('D');
      } else if(board[cur_node.first + 2][cur_node.second] == 1) {
        tmp.push_back({cur_node.first + 2, cur_node.second});
      }
    }

    if(cur_node.second - 2 > 0) {
      if(board[cur_node.first][cur_node.second - 2] == 2) {
        valid_connect.push_back('L');
      } else if(board[cur_node.first][cur_node.second - 2] == 1) {
        tmp.push_back({cur_node.first, cur_node.second - 2});
      }
    }

    if(cur_node.second + 2 < n) {
      if(board[cur_node.first][cur_node.second + 2] == 2) {
        valid_connect.push_back('R');
      } else if(board[cur_node.first][cur_node.second + 2] == 1) {
        tmp.push_back({cur_node.first, cur_node.second + 2});
      }
    }
    //cout << tmp.size() << endl;

    if(valid_connect.size() == 0) continue;
    int mv_idx = rand() % valid_connect.size();
    char conn = valid_connect[mv_idx];
    //cout << conn << endl;
    switch(conn) {
      case 'U':
        board[cur_node.first - 1][cur_node.second] = 2;
        break;
      case 'D':
        board[cur_node.first + 1][cur_node.second] = 2;
        break;
      case 'L':
        board[cur_node.first][cur_node.second - 1] = 2;
        break;
      case 'R':
        board[cur_node.first][cur_node.second + 1] = 2;
        break;
    }
  }
}

int main() {
  cout << "input size: " << endl;
  int n;
  cin >> n;
  srand (time(NULL));
  vector<vector<int>> board = init_board(n);
  pair<int,int> start = {3,3};
  pair<int,int> end = { n - 2, n - 2};
  cout << "initial board" << endl;
  print_board(board, start, end);
  cout << "dfs generated board:" << endl;
  auto dfs_rst = board;
  dfs_gen(dfs_rst, start, end);
  print_board(dfs_rst, start, end);
  cout << "prime generated board:" << endl;
  auto bfs_rst = board;
  prim_gen(bfs_rst, start, end);
  print_board(bfs_rst, start, end);
	return 0;
}
