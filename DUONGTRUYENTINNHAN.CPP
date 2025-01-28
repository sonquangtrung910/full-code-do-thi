#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int n,m;
vector<int>v[N];
queue<int> q;
int f[N];
int tr[N];
void  trace(int u){
    if (u==-1) return;
    cout <<u<<" ";
    trace (tr[u]);
}
void bfs(){
    q.push(1);
    f[1]=1;
    tr[1]=-1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for(int x:v[u]){
            if(f[x]==-1){
            q.push(x);
            f[x]=f[u]+1;
            tr[x]=u;
            }
        }
    }
    if(f[n]==-1) {
        cout <<"IMPOSSIBLE"<<endl;
        return;
    }
    cout <<f[n]<<endl;
    trace(n);
}
int main(){
    freopen("DOTHI.INP","r",stdin);
    freopen("DOTHI.OUT","w",stdout);
    memset(f,-1,sizeof(f));
    cin >>n>>m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
}