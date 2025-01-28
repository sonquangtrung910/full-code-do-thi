#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
vector <int>v[N];
int n;
int m;
int cau=0;
int low[N],num[N],cnt=0;
void dfs(int u,int p){
    cout <<u<<" "<<p<<endl;
    low[u]=num[u]=++cnt;
    for(int x:v[u]){
        if(x==p) continue;
        else{
            if(num[x]==0){
                dfs(x,u);
                low[u]=min(low[u],low[x]);
                if(low[x]==num[x]) cau++;
            }
            else{
                low[u]=min(low[u],num[x]);
            }
        }
    }

}
int main(){
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin >>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >>m;
    for(int i=1;i<=m;i++){
        int ok=0;
        int a,b;
        cin >>a>>b;
        for(int x:v[a]){
            if(x==b) ok=1;
        }
        if(ok==1) continue;
        else {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++) if(num[i]==0) dfs(i,i);
    cout <<cau;

}