#include <iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5000+5;
int ege[maxn][maxn];
int vis[maxn][maxn];
int n;
void ola(int index)
{
  for(int i=1;i<=n;i++)
  {
    if(!vis[index][i]&&ege[index][i])
    {
      vis[index][i]=1;
      vis[i][index]=1;
      ola(i);
      printf("%d--%d\n",index,i);
    }
  }
}
int main()
{
  int x,y;
  int nn;
  cin>>n>>nn;
  memset(ege,0,sizeof(ege));
  memset(vis,0,sizeof(vis));

  for(int i=0;i<nn;i++)
  {  cin>>x>>y;
    ege[x][y]=1;
    ege[y][x]=1;

  }

  ola(1);

  // cout << "Hello world!" << endl;
  return 0;
}

