#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int count1=0;
        int count2=0;
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp%2==0){
                count1+=tmp;
            }else{
                count2+=tmp;
            }
        }
        cout<<((count1>count2)?"YES":"NO")<<endl;
    }
    return 0;
}