#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+100;
char A[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int cnt=0;
int visited[N][N];
bool range (int x,int y){
    return x>=0 and x<n and y>=0 and y<m;
}
void dfs(int x,int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++) {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(range(X,Y) and A[X][Y] !='#' and !visited[X][Y] ) dfs(X,Y);
    }
}
int main(){
    freopen("DOTHI.INP","r",stdin);
    freopen("DOTHI.OUT","w",stdout);
    memset (visited,0,sizeof(visited));
    cin >>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >>A[i][j];

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(A[i][j]!='#' and !visited[i][j]) {
                dfs(i,j);
                cnt ++;
            }
        }
    }
    cout <<cnt<<endl;
}