#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef pair<long long, long long> ll;
const int N=1e5+100;
long long f[3][N];
long long res;
vector<ll>v[N];
void dsj(int s){
    memset(f[s],0x3f,sizeof(f[s]));
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    f[s][s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        long long val=pq.top().first;
        pq.pop();
        if(val>f[s][u]) continue;
        for( ll x:v[u]){
            if(f[s][x.first]>val+x.second){
                f[s][x.first]=val+x.second;
                pq.push({f[s][x.first],x.first});
            }
        }

    }
}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dsj(1);
    dsj(2);
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++) cout <<f[i][j]<<" ";
        cout <<endl;
    }
    int G[n];
    for(int i=1;i<=n;i++){
        res+=f[2][i];
        G[i]=f[1][i]-f[2][i];
    }
    sort(G+1,G+n+1);
    for(int i=1;i<=n/2;i++) res+=G[i];
    cout <<endl;
    cout <<res;

}