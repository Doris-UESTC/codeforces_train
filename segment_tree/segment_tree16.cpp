#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Segment_tree{
    vector<int> tree;
    int num;
    void init(int n){
        num=n-1;
        tree.resize(n*4) ;
    }
    void build(int node, int st , int sp ,vector<int> &x){
        if(st == sp){
            tree[node] = x[st];
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            build(lft,st,mid,x) ;
            build(rght,mid+1,sp,x) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    void update(int node, int index, int st , int sp,int value){
        if(st > index || sp < index) return ;
        if(st == sp){
            tree[node] = value ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            update(lft,index,st,mid,value);
            update(rght,index,mid+1,sp,value);

            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    int operation(int l , int r){
        return min(l,r) ;
    }
    int query(int node, int l,int r, int st ,int sp,int p){
        if(l>sp || r<st) return 0;
        if(st==sp){
            if(tree[node]<=p) {
                update(1,st,1,num,INT_MAX);
                return 1;
            }
        }
        int lft = (node << 1) ;
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1) ;
        if(tree[node]<=p){
            int s1=(tree[lft]<=p)?query(lft,l,r,st,mid,p):0;
            int s2=(tree[rght]<=p)?query(rght,l,r,mid+1,sp,p):0;
            return s1+s2;
        }
        return 0;
    }
};
int32_t main(){
    #ifdef Online_Judge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int n,m;
    Segment_tree st;
    vector<int> init_array;
    cin>>n>>m;
    init_array.assign(n+1, INT_MAX);
    st.init(n+1);
    st.build(1,1,n,init_array);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int a,b;
            cin>>a>>b;
            st.update(1,a+1,1,n,b);
        }else if(op==2){
            int l,r,p;
            cin>>l>>r>>p;
            cout<<st.query(1,l+1,r,1,n,p)<<endl;
        }
    }
    return 0 ;
}