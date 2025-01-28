#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[N];
const int N=1e5+100;
queue<int> p;
int h[N];
void bfs(){
    p.push(1);
    while (!p.empty()){
        int u=p.front();
        p.pop();
        for(int a:v[u]){
            if(h[a]==-1){
                h[a]=h[u]+1;
                p.push(a);
            }
        }
        
    }
}
int main(){
    h[1]=0;
    cin >>m>>n;
    for(int i=1;i<=m;i++) {
        int a,b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}