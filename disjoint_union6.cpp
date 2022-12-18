#include<bits/stdc++.h>
using namespace std;
int n,m,p[1000005];
int find(int x){
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n+1;i++){
        p[i]=i;
    }
    char op;
    for(int i=0,x;i<m;i++){
        cin>>op>>x;
        if(op=='?'){
            if(find(x)==n+1) 
            cout<<-1<<"\n";
            else 
            cout<<find(x)<<"\n";
        }else{
            p[x]=find(x+1);
        }
    }
}