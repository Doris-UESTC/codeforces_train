/* https://codeforces.com/contest/1573/problem/C 注意一下超时的问题 读写优化 */
#include<bits/stdc++.h>
using namespace std;
int dp[200005]={0};
int indegree[200050]={0};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        queue<int> q;
        vector<vector<int> > rec(n+1);
        int cnt=0;
        for(int i=1;i<=n;i++){
            rec[i].clear();
            dp[i]=0;
            indegree[i]=0;
        }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(k==0){
                q.push(i);
                dp[i]=1;
                cnt++;
            }
            indegree[i]=k;
            for(int j=0;j<k;j++){
                int tmp;
                cin>>tmp;
                rec[tmp].push_back(i);
                
            }
        }
        int ans=0;
        while(!q.empty()){  
            int x=q.front();
            q.pop();
            /*for(int i=0;i<rec[x].size();i++){
                indegree[rec[x][i]]--;
                if(x>rec[x][i]){
                    dp[rec[x][i]]=max(dp[rec[x][i]],dp[x]+1);
                }else if(x<rec[x][i]){
                    dp[rec[x][i]]=max(dp[rec[x][i]],dp[x]);
                }
                if(indegree[rec[x][i]]==0){
                    cnt++;
                    q.push(rec[x][i]);
                }
            }*/
            for(auto i:rec[x]){
                indegree[i]--;
                if(x>i){
                    dp[i]=max(dp[i],dp[x]+1);
                }else if(x<i){
                    dp[i]=max(dp[i],dp[x]);
                }
                if(indegree[i]==0){
                    cnt++;
                    q.push(i);
                }
            }
        }
        if(cnt!=n)
        cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++){
                ans=max(ans,dp[i]);
            }
            cout<<ans<<endl;
        }
    }
}