#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m;
typedef pair<long long,long long> ll;
typedef pair<long long,ll> lll;
long long f[N][2];
vector<ll>v[N];
void dsj(int s){
    memset(f,0x3f,sizeof(f));
    priority_queue<lll,vector<lll>,greater<lll>> pq;
    f[s][0]=0;
    pq.push(lll(0,ll(s,0)));
    while(!pq.empty()){
        int u=pq.top().second.first;
        int z=pq.top().second.second;
        long long val=pq.top().first;
        pq.pop();
        if(val>f[u][z]) continue;
        for(ll x:v[u]){
            if(z==0){
                if(f[x.first][1]>val+x.second/2){
                    f[x.first][1]=val+x.second/2;
                    pq.push(lll(f[x.first][1],ll(x.first,1)));
                }
                if(f[x.first][0]>val+x.second){
                    f[x.first][0]=val+x.second;
                    pq.push(lll(f[x.first][0],ll(x.first,0)));
                }
            }
            else if(z==1){
                if(f[x.first][1]>val+x.second){
                    f[x.first][1]=val+x.second;
                    pq.push(lll(f[x.first][1],ll(x.first,1)));
                }
            }
        }
    }
}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
    }
    dsj(1);
    cout <<min(f[n][1],f[n][0]);
    return 0;
}