/* https://codeforces.com/gym/102219/problem/J 拓扑排序 */
#include<bits/stdc++.h>
using namespace std;
int degree[10]={0};
vector<char> tmp;
vector<vector<int> > rec(6);
void topo(){
    queue<int> q;
    int count=0;
    for(int i=0;i<5;i++){
        if(degree[i]==0){
            count++;
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        tmp.push_back((char)(cur+'A'));
        for(int i=0;i<rec[cur].size();i++){
            int next=rec[cur][i];
            degree[next]--;
            if(degree[next]==0){
                q.push(next);
            }
        }
    }
}
int main(){
    for(int i=0;i<5;i++){
        string s;
        cin>>s;
        if(s[1]=='>'){
            if(s[0]==s[2]){
                cout<<"impossible"<<endl;
                return 0;
            }
            degree[s[0]-'A']++;
            rec[s[2]-'A'].push_back(s[0]-'A');
        }else{
            if(s[0]==s[2]){
                cout<<"impossible"<<endl;
                return 0;
            }
            degree[s[2]-'A']++;
            rec[s[0]-'A'].push_back(s[2]-'A');
        }
    }
    topo();
    if(tmp.size()<5){
        cout<<"impossible"<<endl;
        return 0;
    }
    for(int i=0;i<tmp.size();i++){
        cout<<tmp[i]<<"";
    }
    return 0;
}