//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
#include<bits/stdc++.h>
using namespace std;
int cal(int a1,int a2,int a3,int a4){
    return max(max(a1,a2),max(a3,a4))-min(min(a1,a2),min(a3,a4));
}
int main(){
    int n1,n2,n3,n4;
    cin>>n1;
    vector<int> a(n1);
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    cin>>n2;
    vector<int> b(n2);
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }
    cin>>n3;
    vector<int> c(n3);
    for(int i=0;i<n3;i++){
        cin>>c[i];
    }
    cin>>n4;
    vector<int> d(n4);
    for(int i=0;i<n4;i++){
        cin>>d[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    int l1=0,l2=0,l3=0,l4=0;
    int tmp1,tmp2,tmp3,tmp4;
    int mn=INT_MAX;
    while(l1<n1&&l2<n2&&l3<n3&&l4<n4){
        int diff=cal(a[l1],b[l2],c[l3],d[l4]);
        if(diff<mn){
            mn=diff;
            tmp1=a[l1];
            tmp2=b[l2];
            tmp3=c[l3];
            tmp4=d[l4];
        }
        if(a[l1]<=b[l2]&&a[l1]<=c[l3]&&a[l1]<=d[l4]){
            l1++;
        }
        else if(b[l2]<=a[l1]&&b[l2]<=c[l3]&&b[l2]<=d[l4]){
            l2++;
        }
        else if(c[l3]<=a[l1]&&c[l3]<=b[l2]&&c[l3]<=d[l4]){
            l3++;
        }
        else if(d[l4]<=a[l1]&&d[l4]<=b[l2]&&d[l4]<=c[l3]){
            l4++;
        }
    }
    cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<endl;
}