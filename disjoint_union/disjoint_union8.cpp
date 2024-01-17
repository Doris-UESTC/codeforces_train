#include<bits/stdc++.h>
using namespace std;
int p[200005],r[200005];
int find_p(int x){
    if(x!=p[x]){
        p[x]=find_p(p[x]);
    }
    return p[x];
}
int find_r(int x){
    if(x!=r[x]){
        r[x]=find_r(r[x]);
    }
    return r[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        p[i]=i;
        r[i]=i;
    }
    for(int i=0;i<q;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            p[find_p(x)]=find_p(y);
        }else if(op==2){
            int now=find_r(x);
            while(now+1<=y){
                r[now]=find_r(now+1);
                p[find_p(now)]=find_p(r[now]);
                now=r[now];
            }
        }else{
            if(find_p(x)==find_p(y))
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
}