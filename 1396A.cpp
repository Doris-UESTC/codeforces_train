/* https://codeforces.com/problemset/problem/1396/A */
#include<bits/stdc++.h>
using namespace std;
long long rec[100010]={0};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>rec[i];
    }
    if(n==1){
        cout<<"1 1"<<endl;
        cout<<-rec[0]<<endl;
        cout<<"1 1"<<endl;
        cout<<"0"<<endl;
        cout<<"1 1"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    cout<<"1 1"<<endl;
    cout<<-rec[0]<<endl;
    rec[0]=0;
    cout<<"2 "<<n<<endl;
    for(int i=1;i<n;i++){
        cout<<(long long)rec[i]*(n-1)<<" ";
    }
    cout<<""<<endl;
    cout<<"1 "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<-(long long)rec[i]*n<<" ";
    }
    return 0;
}