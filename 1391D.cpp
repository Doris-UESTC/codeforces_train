/* https://codeforces.com/contest/1391/problem/D */
#include<bits/stdc++.h>
using namespace std;
#define bit(x,n) ((x>>n)&1)
int change(int x,int y){
    int count=0;
    for(int i=0;i<4;i++){
        count+=(bit(x,i))^(bit(y,i));
    }
    return count;
}
int check1(int x,int y){
    return (bit(x,0)+bit(x,1)+bit(y,0)+bit(y,1))%2==1;
}

int check2(int x,int y){
    return (bit(x,0)+bit(x,1)+bit(y,0)+bit(y,1))%2==1 &&
        (bit(x,1)+bit(x,2)+bit(y,1)+bit(y,2))%2==1;
}

int a[5][1000005];
int main(){
    int n,m;
    cin>>n>>m;
    if(n>=4){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            a[i][j]=ch-'0';
        }
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==2){

    }
    if(n==3){

    }
}