#include<bits/stdc++.h>
using namespace std;
string s;
string search_string;
bool find_substring(vector<int> &p,int L,int R){
    while(L<=R){
        int mid=(L+R)/2;
        string tmp=s.substr(p[mid],search_string.size());
        if(tmp==search_string){
            return true;
        }
        else if(tmp<search_string){
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }   
    return false;
}

int find_right_substring(vector<int> &p,int L,int R){
    while(L<=R){
        int mid=(L+R)/2;
        string tmp=s.substr(p[mid],search_string.size());
        if(tmp<=search_string){
            L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    return L;   
}

int find_left_substring(vector<int> &p,int L,int R){
    while(L<=R){
        int mid=(L+R)/2;
        string tmp=s.substr(p[mid],search_string.size());
        if(tmp>=search_string){
            R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    return R;   
}

void radix_sort(vector<pair<pair<int,int>,int> > &a){
    int n=a.size();
    {
        vector<int> cnt(n);
        for(auto x:a){
            cnt[x.first.second]++;
        }
        vector<pair<pair<int,int>,int>> a_new(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++){
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(auto x:a){
            int i=x.first.second;
            a_new[pos[i]]=x;
            pos[i]++;
        }
        a=a_new;
    }
    {
        vector<int> cnt(n);
        for(auto x:a){
            cnt[x.first.first]++;
        }
        vector<pair<pair<int,int>,int>> a_new(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++){
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(auto x:a){
            int i=x.first.first;
            a_new[pos[i]]=x;
            pos[i]++;
        }
        a=a_new;
    }
}
int main(){
    cin>>s;
    s+="$";
    int n=s.size();
    vector<int> p(n),c(n);
    vector<pair<char,int> > a(n);
    for(int i=0;i<n;i++){
        a[i]={s[i],i};
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        p[i]=a[i].second;
    }
    c[p[0]]=0;
    for(int i=1;i<n;i++){
        if(a[i].first==a[i-1].first){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
    int k=0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int> > a(n);
        for(int i=0;i<n;i++){
            a[i]={{c[i],c[(i+(1<<k))%n]},i};
        }
        radix_sort(a);
        for(int i=0;i<n;i++){
            p[i]=a[i].second;
        }
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(a[i].first==a[i-1].first){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
		k++;
    }
    int search_len;
    cin>>search_len;
    while(search_len){
        search_len--;
        cin>>search_string;
        bool judge=find_substring(p,0,p.size()-1);
        if(judge){
            cout<<find_right_substring(p,0,p.size()-1)-find_left_substring(p,0,p.size()-1)-1<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}