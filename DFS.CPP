#include<bits/stdc++.h>
using namespace std;
vector <int> v[100000];
int tham[100000];
int n,m;
void DFS(int u){
    tham[u]=1;
    for(int x:v[u]){
        if(tham[x]==0){
            DFS(x);
        }
    }
}
int main(){
    memset(tham,0,sizeof tham);
    cin >>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(tham[i]==0){
            DFS(i);
            cnt ++;
        }
    }
    cout <<cnt;
}