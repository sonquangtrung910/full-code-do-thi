#include<bits/stdc++.h>
using namespace std;
int n,m,q;
const int N=510;
typedef pair<long long,long long> ll;
vector<ll>v[N];
long long f[N][N];
int visited[N];
void dsj2(int s){
    memset(visited,0,sizeof(visited));
    memset(f[s],0x3f,sizeof(f[s]));
    f[s][s]=0;
    for(int i=1;i<=n;i++){
        int u=0;
        long long minval=1e18;
        for(int j=1;j<=n;j++){
            if(visited[j]==0 and (u==0 or f[s][j]<minval)) {
                u=j;
                minval=f[s][j];
            }
        }
        visited[u]=1;
        for(ll x:v[u]){
           if(f[s][x.first]>f[s][u]+x.second){
                f[s][x.first]=f[s][u]+x.second;
           }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m>>q;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++) dsj2(i);
    while(q--){
        int a,b;
        cin >>a>>b;
        if(f[a][b]>1e18) cout <<"-1\n";
        else cout <<f[a][b]<<"\n";
    }
    return 0;
}