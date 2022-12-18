#include<bits/stdc++.h>
using namespace std;
string pushDominoes(string dominoes) {
    int n = dominoes.size();
    queue<int> q;
    vector<int> time(n, - 1);
    vector<string> force(n);
    for (int i = 0; i < n; i++) {
        if (dominoes[i] != '.') {
            q.emplace(i);
            time[i] = 0;
            force[i].push_back(dominoes[i]);
        }
    }
    string res(n, '.');
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (force[i].size() == 1) {
            char f = force[i][0];
            res[i] = f;
            int ni = (f == 'L') ? (i - 1) : (i + 1);
            if (ni >= 0 and ni < n) {
                int t = time[i];
                if (time[ni] == -1) {
                    q.emplace(ni);
                    time[ni] = t + 1;
                    force[ni].push_back(f);
                } else if(time[ni] == t + 1) {
                    force[ni].push_back(f);
                }
            }
        }
    }
    return res;
}
int main(){
    string s;
    int n;
    cin>>n;
    cin>>s;
    string ans=pushDominoes(s);
    int tmp=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]=='.'){
            tmp+=1;
        }
    }
    cout<<ans<<endl;
}