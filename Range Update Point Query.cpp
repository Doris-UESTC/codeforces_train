// #include<bits/stdc++.h>
// using namespace std;
// int a[200005];
// int tree[800005];
// class Segment_tree{
//     public:
//     Segment_tree(){}
//     Segment_tree(int n){
        
//     }

//     int query(int node, int index, int st ,int sp){  
//         if(st>index || sp<index) return 0;    
//         if(st>=index&&sp<=index) return tree[node];
//         int lft = (node << 1) ;
//         int rght = lft + 1;
//         int mid = st + ((sp-st)>>1) ;
//         int res=0;
//         res+=query(lft,index,st,mid) ;
//         res+=query(rght,index,mid+1,sp) ;
//         return tree[node] + res;
//     }
//     void update(int node, int l,int r, int st , int sp,int value){
//         if(st > r || sp < l) return ;
//         if(st>=l && sp<=r){
//             tree[node] +=value ;
//             return;
//         }
//         else{
//             int lft = (node << 1);
//             int rght = lft + 1;
//             int mid = st + ((sp-st)>>1) ;
//             update(lft,l,r,st,mid,value);
//             update(rght,l,r,mid+1,sp,value);
//         }
//     }
// };
// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     int t;
//     cin>>t;
//     while(t--){
//         int n,q;
//         cin>>n>>q;
//         Segment_tree st(n+1);
//         for(int i=1;i<=n;i++){
//             cin>>a[i];
//         }
//         for(int i=0;i<q;i++){
//             int op;
//             cin>>op;
//             if(op==1){
//                 int l,r;
//                 cin>>l>>r;
//                 st.update(1,l,r,1,n,1);
//             }else if(op==2){
//                 int x;
//                 cin>>x;
//                 int time=st.query(1,x,1,n);
//                 int tmp=a[x];
//                 while(time--){
//                     int tmp_num=0;
//                     while(tmp){
//                         tmp_num+=tmp%10;
//                         tmp/=10;
//                     }
//                     tmp=tmp_num;
//                 }
//                 cout<<tmp<<endl;
//             }
//         }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        set<int> S;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=10) 
            S.insert(i);
        }
        for(int i=0;i<q;i++){
            int op;
            cin>>op;
            if(op==1){
                int l,r;
                cin>>l>>r;
                auto it=S.lower_bound(l);
                while(it!=S.end() && *it<=r){
                    int tmp=a[*it];
                    int tmp_num=0;
                    while(tmp){
                        tmp_num+=tmp%10;
                        tmp/=10;
                    }
                    a[*it]=tmp_num;
                    if(a[*it]<=9) S.erase(it++);
                    else it++;
                }
            }else if(op==2){
                int x;
                cin>>x;
                cout<<a[x]<<endl;
            }
        }
    }
}