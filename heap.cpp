#include<iostream>
#include<queue>
#define dad(x) (x/2)
#define left_son(x) 2*x
#define right_son(x) 2*x+1
using namespace std;
struct heap{
    int tot,w[1000005];
    void up_wf(int x){ 
        if(x==1)
        return;
        if(w[dad(x)]>w[x]){
            swap(w[dad(x)],w[x]);
            up_wf(dad(x));
            return;
        }
    }
    void down_wf(int x){
        if(w[left_son(x)]==0&&w[right_son(x)]==0)
        return;
        int hh;
        if((w[left_son(x)]<=w[right_son(x)]&&w[left_son(x)!=0])||w[right_son(x)]==0)
        hh=left_son(x);
        else
        hh=right_son(x);
        if(w[x]>w[hh]){
            swap(w[x],w[hh]);
            down_wf(hh);
        }
        return;
    }
    void push(int x){
        tot++;
        w[tot]=x;
        up_wf(tot);
        return;
    }
    int top(){
        return w[1];
    }
    void pop(){
        swap(w[1],w[tot]);
        w[tot--]=0;
        down_wf(1);
        return;
    }
};
heap d;
int main(){
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            int num;
            cin>>num;
            d.push(num);
        }else if(op==2){
            cout<<d.top()<<endl;;
        }else{  
            d.pop();
        }
    }
    return 0;
}