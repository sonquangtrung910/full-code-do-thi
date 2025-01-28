#include <bits/stdc++.h>
#include <variant>
using namespace std;
const int N = 1e5 + 100;
int n;
int MaxColor = 0;
int ColorEdge[N];
vector <pair<int,int> > a[N];
void dfs(int u, int parent, int color_edge_parent) {
   int Color = color_edge_parent;
   for (pair<int,int> v : a[u]) if (v.first != parent) {
       Color++;
       if (Color > MaxColor) {
           Color = 1;
       }
       ColorEdge[v.second] = Color;
       dfs(v.first,u,Color);
   }
}
int main() {
   cin >> n;
   for (int i = 1 ; i < n ; i++) {
       int x , y;
       cin >> x >> y;
       a[x].push_back({y,i});
       a[y].push_back({x,i});
   }
   for (int i = 1 ; i <= n ; i++)
       MaxColor = max(MaxColor,(int)a[i].size());
   dfs(1,0,0);
   cout << MaxColor << "\n";
   for (int i = 1 ; i < n ; i++)
       cout << ColorEdge[i] << "\n";
   return 0;
}
