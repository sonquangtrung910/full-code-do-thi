#include<bits/stdc++.h>
using namespace std;
typedef pair <long long,long long > ll;
int n,m,q;
int visited[500];
long long  f[1000];
vector <ll>v[500*500];
void dsj(int s){
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    memset(f,0x3f,sizeof(f));
    f[s]=0;
    pq.push({0,s});
    while (!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u]==1) continue;
        visited[u]=1;
        for (ll x:v[u]){
            f[x.first]=min(f[x.first],f[u]+x.second);
            pq.push({f[x.first],x.first});
        }
    }
    for(int i=1;i<=n;i++) cout <<f[i]<< " ";


}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin >>n>>m>>q;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dsj(1);
    return 0;
}