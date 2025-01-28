#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1000;
long long fdi[N];
long long fden[N];
const long long INF = 1e18;    
typedef pair <long long,long long> ll;
vector<ll>v[N];
int n,m,k,s,t;
void dsj1(int s){
    memset(fdi,0x3f,sizeof(fdi));
    fdi[s]=0;
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        long long val=pq.top().first;
        pq.pop();
        if(val>fdi[u]) continue;
        for(ll x: v[u]){
            if(fdi[x.first]>val+x.second){
                fdi[x.first]=val+x.second;
                pq.push({fdi[x.first],x.first});
            }
        }
    }
}
void dsj2(int s){
    memset(fden,0x3f,sizeof(fden));
    fden[s]=0;
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        long long val=pq.top().first;
        pq.pop();
        if(val>fden[u]) continue;
        for(ll x: v[u]){
            if(fden[x.first]>val+x.second){
                fden[x.first]=val+x.second;
                pq.push({fden[x.first],x.first});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin >>n>>m>>k>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
    }
    dsj1(s);
    dsj2(t);
    long long res=fdi[t];
    for(int i=1;i<=k;i++){
        int a,b,c;
        cin >>a>>b>>c;
        res=min(res,min(fdi[a]+fden[b]+c,fdi[b]+fden[a]+c));
    }
    if(res>=INF) cout <<-1;
    else cout <<res;
}
