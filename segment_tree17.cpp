#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item{
    int inv;
    int num[45]={0};
};
item Neutral_element;
struct Segment_tree{
    vector<item> tree;
    void init(int n){
        for(int i=0;i<45;i++){
            Neutral_element.num[i]=0;
        }
        tree.assign(4*n,Neutral_element);
    }
    void build(int node, int st , int sp ,vector<int> &x){
        if(st == sp){
            if(st<x.size())
            tree[node].num[x[st]]++;
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
    void update(int node, int index,int pv,int v, int st , int sp){
        if(st > index || sp < index) return ;
        if(st == sp){
            tree[node].num[pv]--;
            tree[node].num[v]++;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;
            update(lft,index,pv,v,st,mid);
            update(rght,index,pv,v,mid+1,sp);
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }
    item operation(item l , item r){
        item res;
        res.inv=l.inv+r.inv;
        int prev[45]={0};
        prev[1]=r.num[1];
        res.num[1]=l.num[1]+r.num[1];
        for(int i=2;i<=40;i++){
            res.num[i]=l.num[i]+r.num[i];
            res.inv+=l.num[i]*prev[i-1];
            prev[i]=prev[i-1]+r.num[i];
        }
        return res;
    }
    item query(int node, int l,int r, int st ,int sp){
        if(l>sp || r<st) return Neutral_element;
        if(st>=l && sp<=r){
            return tree[node];
        }
        int lft = (node << 1);
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1) ;
        item ans=operation(query(lft,l,r,st,mid),query(rght,l,r,mid+1,sp));
        return ans;
    }
};
int32_t main(){
    #ifdef Online_Judge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int n,q;
    Segment_tree st;
    vector<int> init_array;
    cin>>n>>q;
    init_array.assign(n+1,0);
    st.init(n+1);
    for(int i=1;i<=n;i++){
        cin>>init_array[i];
    }
    st.build(1,1,n,init_array);
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==2){
            int a,b;
            cin>>a>>b;
            st.update(1,a,init_array[a],b,1,n);
            init_array[a]=b;
        }else if(op==1){
            int a,b;
            cin>>a>>b;
            cout<<st.query(1,a,b,1,n).inv<<endl;
        }
    }
    return 0 ;
}