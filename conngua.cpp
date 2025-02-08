#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,-1,1,1,-2,-2,2,2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int f[10][10];
typedef pair<int,int> ii;
bool antoan(int x,int y){
    if(x>=1 and x<=8 and y<=8 and y>=1) return true;
    return false;
}
void bfs(int s1,int s2,int t1,int t2){
    queue<ii>p;
    f[s1][s2]=0;
    p.push({s1,s2});
    while(!p.empty()){
        int cx=p.front().first;
        int cy=p.front().second;
        p.pop();
        if(cx==t1 and cy==t2){
            cout<<f[cx][cy]<<"\n";
            return;
        }
        for(int i=0;i<8;i++){
             int nx=cx+dx[i];
             int ny=cy+dy[i];
             if(antoan(nx,ny)and f[nx][ny]==-1){
                f[nx][ny]=f[cx][cy]+1;
                p.push({nx,ny});
             }
        }
        
    }
    cout<<"HETCUU"<<"\n";
}
int main(){
    iostream::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        memset(f,-1,sizeof(f));
        string a,b;
        cin >>a>>b;
        int s1,s2;
        int t1,t2;
        if(a[0]=='a') s1=1;
        if(a[0]=='b') s1=2;
        if(a[0]=='c') s1=3;
        if(a[0]=='d') s1=4;
        if(a[0]=='e') s1=5;
        if(a[0]=='f') s1=6;
        if(a[0]=='g') s1=7;
        if(a[0]=='h') s1=8;
        s2=a[1]-'0';
        if(b[0]=='a') t1=1;
        if(b[0]=='b') t1=2;
        if(b[0]=='c') t1=3;
        if(b[0]=='d') t1=4;
        if(b[0]=='e') t1=5;
        if(b[0]=='f') t1=6;
        if(b[0]=='g') t1=7;
        if(b[0]=='h') t1=8;
        t2=b[1]-'0';
        bfs(s1,s2,t1,t2);
}}