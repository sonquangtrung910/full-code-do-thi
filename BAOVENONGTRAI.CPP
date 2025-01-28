#include <bits/stdc++.h>
#include <variant>
using namespace std;
const int N = 710;
int dx[] = {-1,-1,-1,+0,+0,+1,+1,+1};
int dy[] = {-1,+0,+1,-1,+1,-1,+0,+1};
int a[N][N];
int n, m;
int range(int x,int y) {
   return x > 0 && x <= n  && y > 0 && y <= m;
}
int visited[N][N];
int check;
void dfs(int x, int y) {
   visited[x][y] = 1;
   for (int i = 0 ; i <= 8 ; i++) {
       int X = x + dx[i];
       int Y = y + dy[i];
       if (range(X,Y) && visited[X][Y] == 0 && a[X][Y] == a[x][y])
           dfs(X,Y);
       if (range(X,Y) && a[X][Y] > a[x][y]) {
           check = 0;
       }
   }
}
int main() {
   cin >> n >> m;
   for (int i = 1 ; i <= n ; i++)
       for (int j = 1; j <= m ; j++) {
           cin >> a[i][j];
       }
   int cnt = 0;
   for (int i = 1 ; i <= n ; i++)
       for (int j = 1 ; j <= m ; j++)
           if (visited[i][j] == 0) {
                check = 1;
               dfs(i,j);
               cnt += check;
            }
   cout << cnt;
   return 0;
}
