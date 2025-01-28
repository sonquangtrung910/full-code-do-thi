#include<bits/stdc++.h>
using namespace std;
const int N=1e4+300;
int n,m,k,s,t;
typedef pair<int,int> ii;
vector<ii>v[N];
int f[N];
void dsj(int s){
    priority_queue<ii,vector<ii>,greater<ii> >pq;
    f[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        int val=pq.top().first;
        pq.pop();
        if(val>f[u]) continue;
        for(ii x:v[u]){
            if(f[x.first]>val+x.second){
                f[x.first]=val+x.second;
                pq.push({f[x.first],x.first});
            }
        }
    }
}
int main(){
    cin >>n>>m>>k>>s>>t;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
    }
}