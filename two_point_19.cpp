//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/I
#include<bits/stdc++.h>
using namespace std;
int n,s;
struct stk{
    vector<int> s;
    vector<bitset<1005>> val;
    void init(){
        bitset<1005> temp;
        temp[0]=1;
        val.push_back(temp);
    }
    void push(int x){
        s.push_back(x);
        bitset<1005> temp=val.back();
        val.push_back(temp|(temp<<x));
    }
    void pop(){
        s.pop_back();
        val.pop_back();
    }
    bitset<1005> v(){
        return val.back();
    }
    bool empty(){
        return s.empty();
    }
    int top(){
        return s.back();
    }
}s1,s2;
void add(int x){
    s2.push(x);
}
void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    s1.pop();
}
bool good(){
    bitset<1005> v1=s1.v();
    bitset<1005> v2=s2.v();
    for(int i=0;i<=s;i++){
        if(v1[i]&&v2[s-i]){
            return true;
        }
    }
    return false;
}
int main(){
    s1.init();
    s2.init();
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,ans=INT_MAX;
    for(int r=0;r<n;r++){
        add(a[r]);
        while(good()){
            ans=min(ans,r-l+1);
            remove();
            l++;
        }
    }
    if(ans==INT_MAX)
    ans=-1;
    cout<<ans<<endl;
}