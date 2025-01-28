#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,m,k;
queue<int>K;
int f[N];
int visited[N];
vector<int> v[N];
void bfs(int s){
    memset(visited,0,sizeof(visited));
    queue<int>q;
    f[s]=0;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int x:v[u]){
            if(visited[x]!=1) {
                f[x]=min(f[x],f[u]+1);
                q.push(x);
                visited[x]=1;
            }
        }

    }

}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    cin >>n>>k;
    for(int i=1;i<=k;i++){
        int a;
        cin >>a;
        K.push(a);
    }
    cin >>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(!K.empty()){
        bfs(K.front());
        K.pop();
    }
    for(int i=1;i<=n;i++) cout<<f[i]<<" ";
}