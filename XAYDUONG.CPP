#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5+100;
vector <int> v[N];
int visited[N];
int dapan[N];
int tong=0;
void dfs(int u){
    visited[u]=1;
    for(int x:v[u]){
        if(visited[x]==-1){
            dfs(x);
        }
    }
}
int main(){
    memset(visited,-1,sizeof(visited));
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==-1){
            dapan[tong]=i;
            tong ++;
            dfs(i);
        }
    }
    cout <<tong-1;
    cout <<endl;
    for(int i=0;i<tong-1;i++) cout<<dapan[i]<<" "<<dapan[i+1]<<endl;
}