#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        int knowledge=0;
        for(int i=0;i<n;i++){
            int tmp = knowledge;
            knowledge = knowledge | a[i];
            if((knowledge & x)==knowledge){
                continue;
            }else{
                knowledge = tmp;
                break;
            }
        }
        for(int i=0;i<n;i++){
            int tmp = knowledge;
            knowledge = knowledge | b[i];
            if((knowledge & x)==knowledge){
                continue;
            }else{
                knowledge = tmp;
                break;
            }
        }
        for(int i=0;i<n;i++){
            int tmp = knowledge;
            knowledge = knowledge | c[i];
            if((knowledge & x)==knowledge){
                continue;
            }else{
                knowledge = tmp;
                break;
            }
        }
        if(knowledge==x)
        cout<<"YES"<<"\n";
        else
        cout<<"NO"<<"\n";
    }
}