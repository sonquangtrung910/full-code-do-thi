#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=2e5+100;
typedef pair <long long,long long> ll;
typedef pair <long long,ll> lll;
vector<ll>v[N];
long long f[N][11];
void dsj(int s,int k){
    memset(f,0x3f,sizeof(f));
    priority_queue<lll,vector<lll>,greater<lll> >pq;
    f[s][k]=0;
    pq.push(lll(0,ll(s,k)));
    while(!pq.empty()){
        int u=pq.top().second.first;
        int z=pq.top().second.second;
        long long val=pq.top().first;
        pq.pop();
        if(val>f[u][z]) continue;
        for(ll x:v[u]){
            long long ttv=0;
            long long gtv=-1;
            for(int i=1;i<=k;i++){
                if(f[x.first][i]>gtv){
                    gtv=f[x.first][i];
                    ttv=i;
                }
            }
                if(gtv>val+x.second){
                    f[x.first][ttv]=val+x.second;
                    pq.push(lll(f[x.first][ttv],ll(x.first,ttv)));
                }
        }
    }
        sort(f[n]+1,f[n]+k+1);
        for(int i=1;i<=k;i++) cout <<f[n][i]<<" ";
}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cin >>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
    }
    dsj(1,k);
}