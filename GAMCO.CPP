#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int r, c;
char h[105][105];
ii st;
 
int dist[105][105];
 
void BFS(ii st) {
    dist[st.fi][st.se] = 0;
 
    queue<ii>q;
 
    q.push(st);
 
    while(q.size()) {
        int u = q.front().fi;
        int v = q.front().se;
 
        q.pop();
 
        for(int i = 0; i < 4; i++) {
            int x = u + dx[i];
            int y = v + dy[i];
            if(x >= 1 && x <= r && y >= 1 && y <= c && h[x][y] != '*' && dist[x][y] == -1) {
                dist[x][y] = dist[u][v] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
}
 
int  main() {
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dist[i][j] = -1;
            cin >> h[i][j];
            if(h[i][j] == 'C') {
                st.fi = i;
                st.se = j;
            }
        }
    }
 
    BFS(st);
 
    cout << dist[1][1];
}