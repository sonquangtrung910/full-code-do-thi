#include<bits/stdc++.h>
using namespace std;
int p, c, n, res;
vector<int>e[100005];
int pha[100005];
int vi[100005];
 
void BFS(int st) {
    queue<int>q;
    vi[st] = 1;
 
    q.push(st);
 
    while(q.size()) {
        int u = q.front();
        res--;
 
        q.pop();
 
        for(int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
 
            if(vi[v] == 0 && pha[v] == 0) {
                vi[v] = 1;
                q.push(v);
            }
        }
    }
}
int main(){
    cin >> p >> c >> n;
    for(int i = 1; i <= c; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
 
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        for(int j = 0; j < e[x].size(); j++) {
            int u = e[x][j];
            pha[u] = 1;
        }
    }
 
    res = p;
 
    BFS(1);
 
    cout << res;
}
 