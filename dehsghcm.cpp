#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF = 1e9;
int f[N];
int n,m,k,s,t;
typedef pair<long long,long long> ll;
vector<ll>v[N];
int check(int a,int b,int c,int s,int t){
    v[a].push_back({b,c});
    v[b].push_back({a,c});
    memset(f,0x3f,sizeof(f));
    f[s]=0;
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    pq.push({0,s});
    while (!pq.empty()){
        int u=pq.top().second;
        long long val=pq.top().first;
        pq.pop();
        if(f[u]<val) continue;
        for(ll x: v[u]){
            if(f[x.first]>val+x.second){
                f[x.first]=val+x.second;
                pq.push({f[x.first],x.first});
            }
        }
    }
    v[a].pop_back();
    v[b].pop_back();
    return f[t];
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int res=INF;
    cin >>n>>m>>k>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
    }
    for(int i=1;i<=k;i++){
        int a,b,c;
        cin >>a>>b>>c;
        res=min(res,check(a,b,c,s,t));
    }
    if(res==INF) cout <<-1;
    else cout <<res;
    
}
