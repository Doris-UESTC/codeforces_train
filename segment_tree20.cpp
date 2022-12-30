#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> element=make_pair(0,0);
class Segment_tree{
    public:
    vector<pair<int,int>> tree;
    Segment_tree(){}
    Segment_tree(int n){
        tree.assign(4*n,element);
    }
    pair<int,int> query(int node, int index, int st ,int sp){  
        if(st>index || sp<index) return element;    
        if(st>=index&&sp<=index) return tree[node];
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1);
        pair<int,int> res;
        // if(index<=mid){
        //     res=query(lft,index,st,mid);
        // }
        // else{
        //     res=query(rght,index,mid+1,sp);
        // }
        return operation(operation(query(lft,index,st,mid),query(rght,index,mid+1,sp)),tree[node]);
    }
    pair<int,int> operation(pair<int,int> l , pair<int,int> r){
        if(l.first>r.first){
            return l;
        }else{
            return r;
        }
    }
    void update(int node, int l,int r, int st , int sp,int value,int count){
        if(st > r || sp < l) return;
        if(st>=l && sp<=r){
            tree[node]=make_pair(count,value);
            return;
        }else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;
            update(lft,l,r,st,mid,value,count);
            update(rght,l,r,mid+1,sp,value,count);
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    Segment_tree st(n+1);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        int count=0;
        if(op==1){
            int l,r,v;
            cin>>l>>r>>v;
            count++;
            st.update(1,l+1,r,1,n,v,count);
        }else if(op==2){
            int a;
            cin>>a;
            cout<<st.query(1,a+1,1,n).first<<endl;
        }
    }
    return 0 ;
}