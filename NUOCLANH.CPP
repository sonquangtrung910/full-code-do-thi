#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int h[N];
vector<int>v[N];
int n,m;
void dfs(int u,int par){
    for(int child:v[u]){
        if(child !=par){
            h[child]=h[u]+1;
            dfs(child,u);
        }
    }
}
int main(){
   
    cin >>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >>c>>a>>b;
        v[c].push_back(a);
        v[c].push_back(b);
    }
    h[1]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout <<h[i]+1<<endl;
    }
}