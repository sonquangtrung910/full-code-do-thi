#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
typedef pair <long long,long long> ll;
vector<ll>v[N];
int visited[N];
long long f[N];
int n,m;
void dsj(int s){
    memset(f,0x3f,sizeof(f));
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    f[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u]==1) continue;
        visited[u]=1;
        for( ll x :v[u]){
            f[x.first]=min(f[x.first],f[u]+x.second);
            pq.push({f[x.first],x.first});
        }
    }
    for(int i=1;i<=n;i++) cout <<f[i]<<" ";

}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});

    }
    dsj(1);
    return 0;
}