#include<bits/stdc++.h>
using namespace std;
long long  n,m;
const int N=100005;
long long  f[N];
typedef pair<long long, long long>ll;
vector<ll> v[N];
long long dp[N];
int visited[N];
void dsj(int s){
    dp[s]=1;
    memset(f,0x3f,sizeof(f));
    memset(visited,0,sizeof(visited));
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    f[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(visited[u]==1) continue;
        visited[u]=1;
        for(ll x:v[u]){
            if(f[x.first]>f[u]+x.second){
                f[x.first]=f[u]+x.second;
                pq.push({f[x.first],x.first});
                dp[x.first]=dp[u];
            }
            else if(f[x.first]==f[u]+x.second) dp[x.first]+=dp[u];
        }
    }
}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        long long k,a,b,c;
        cin >>k>>a>>b>>c;
        if(k==1){
            v[a].push_back({b,c});
        }
        else{
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
    }
    dsj(1);
    cout <<f[n]<<" "<<dp[n];
}