#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        int rec_a=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            rec_a=rec_a^a[i];
        }
        int rec_b=0;
        for(int i=0;i<m;i++){
            cin>>b[i];
            rec_b=rec_b|b[i];
        }
        if(n%2==0){
            int tmp=0;
            for(int i=0;i<n;i++){
                tmp=tmp^(a[i]|rec_b);
            }
            cout<<tmp<<" "<<rec_a<<endl;
        }else{
            int tmp=0;
            for(int i=0;i<n;i++){
                tmp=tmp^(a[i]|rec_b);
            }
            cout<<rec_a<<" "<<tmp<<endl;
        }

    }
    return 0;
}