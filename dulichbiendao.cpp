#include<bits/stdc++.h>
using namespace std;
int n,m,k;
typedef pair<long long, long long>ll;
typedef pair<long long,ll>lll;
typedef pair <long long,lll>llll;
const int N=1e3+100;
vector<ll>v[N];
long long f[N][N][3];
void dsj(int s,int k){
    memset(f,0x3f,sizeof(f));
    priority_queue<llll,vector<llll>,greater<llll> >pq;
    f[s][0][0]=0;
    pq.push(llll(0,lll(s,ll(0,0))));
    while(!pq.empty()){
        int u=pq.top().second.first;
        long long val=pq.top().first;
        int c=pq.top().second.second.first;
        int z=pq.top().second.second.second;
        pq.pop();
        if(val>f[u][c][z]) continue;
        for( ll x : v[u]){
            if(z==0){
                if(f[x.first][c+1][1]>val+x.second/2 and c<k){
                    f[x.first][c+1][1]=val+x.second/2;
                    pq.push(llll(f[x.first][c+1][1],lll(x.first,ll(c+1,1))));
                }
                if(f[x.first][c][0]>val+x.second){
                    f[x.first][c][0]=val+x.second;
                    pq.push(llll(f[x.first][c][0],lll(x.first,ll(c,0))));
                }
            }
            if(z==1){
                if(f[x.first][c][0]>val+x.second){
                    f[x.first][c][0]=val+x.second;
                    pq.push(llll(f[x.first][c][0],lll(x.first,ll(c,0))));
                }
            }
        }
    }

}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin >>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >>a>>b>>c;
        v[a].push_back({b,c});
    }
    dsj(1,k);
    int res=min(f[n][k][0],f[n][k][1]);
    if(res>=1e18) cout <<-1;
    else cout <<res;
    return 0;
}