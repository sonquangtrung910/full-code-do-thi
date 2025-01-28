#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m;
int cau=0;
int ok[N];
vector<int> tree[N];
int low[N],num[N],cnt=0;
void dfs(int u,int p){
    int child =0;
    low[u]=num[u]=++cnt;
    for(int v:tree[u]){
        if(v==p) continue;
        if (num[v]==0){
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v]) cau++;
            if (u==p){
                if (child>=2) ok[u]=1;
            }
            else {
                if(low[v]>=num[u]) ok[u]=1;
            }
        }
        else low[u]=min(low[u],num[v]);

    }
}
int main(){
    int khop=0;
    freopen("DOTHI.INP","r",stdin);
    freopen("DOTHI.OUT","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin >>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i=1;i<=n;i++) if(num[i]==0) dfs(i,i);
    for(int i=1;i<=n;i++) khop+=ok[i];
    cout <<khop<<" "<<cau;
}