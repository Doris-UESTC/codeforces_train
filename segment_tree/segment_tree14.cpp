#include<bits/stdc++.h>
using namespace std;
#define int long long
int r;
struct matrix1{
    matrix1(){

    }
    long long a,b,c,d;
    matrix1(long long a,long long b,long long c,long long d):a(a),b(b),c(c),d(d){}
    matrix1 operator*(const matrix1 x)const{
        return matrix1((a*x.a+b*x.c)%r,(a*x.b+b*x.d)%r,(c*x.a+d*x.c)%r,(c*x.b+d*x.d)%r);
    }
} ;
class Segment_tree{
    public:
    vector<matrix1> tree;
    Segment_tree(int n){
        tree.resize(n*4) ;
    }
    matrix1 query(int node, int l,int r, int st ,int sp){
        if(l>sp || r<st) return matrix1(1,0,0,1);
        if(l<=st && r>=sp) return tree[node];
        int lft = (node << 1) ;
        int rght = lft + 1;
        int mid = st + ((sp-st)>>1);
        return query(lft,l,r,st,mid)*query(rght,l,r,mid+1,sp);
    }
    void build(int node, int st , int sp ,vector<matrix1> &x){
        if(st == sp){
            tree[node] = x[st] ;
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
    matrix1 operation(matrix1 l , matrix1 r){
        return l * r ;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>r>>n>>m;
    vector<matrix1> x(n+1);
    for(int i=1;i<=n;i++){  
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        x[i]=matrix1(a,b,c,d);
    }
    Segment_tree st(n+1);
    st.build(1,1,n,x);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        matrix1 ans = st.query(1,l,r,1,n);
        cout<<ans.a<<" "<<ans.b<<"\n";
        cout<<ans.c<<" "<<ans.d<<"\n";
        cout<<""<<"\n";
    }
    return 0 ;
}