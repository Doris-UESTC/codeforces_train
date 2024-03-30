// #include<bits/stdc++.h>
// using namespace std;
// unordered_map<int,int> mp;
// int main(){
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int num[n];
//         mp.clear();
//         int p = ((1LL)<<31)-1;
//         for(int i=0;i<n;i++){
//             cin>>num[i];
//             mp[num[i]]++;
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(mp[num[i]]==0)
//                 continue;
//             int w = p&(~num[i]);
//             mp[num[i]]--;
//             if(mp[w])
//             mp[w]--;
//             ans++;
//         }
//         cout<<ans<<"\n";
//     }   
//     return 0;
// }

// #include<bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// using ll = long long;
// using db = double;
// using pii = pair<ll, ll>;
// const int maxn = 2e5+10;
// const ll N = 1e9 + 7;

// int nega(int x) {
// 	int tmp = ~x; // 取反
// 	int mask = 2147483647;  
// 	return tmp & mask;
// }

// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(nullptr);
// 	cout.tie(nullptr);
// 	int t; cin >> t;
// 	while (t--) {
// 		int n; cin >> n;
// 		map<int, int>cnt;
// 		for (int i = 0; i < n; i++) {
// 			int a; cin >> a;
// 			cnt[a]++;
// 		}

// 		int ans = 0;
// 		for (auto it : cnt) {
// 			if (it.second == 0)continue;
// 			int num = it.first;
// 			while (cnt[num] != 0) {
// 				int fit = nega(num);
// 				if (cnt[fit] != 0)cnt[fit]--;
// 				cnt[num]--;
// 				ans++;
// 			}
// 		}
// 		//cout << "=========";
// 		cout << ans << endl;
// 	}
// 	return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int nega(int x) {
	int tmp = ~x; // 取反
	int mask = 2147483647;  
	return tmp & mask;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> mp;

        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            mp[tmp]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==0)
            continue;
            int num = it.first;
            while(mp[num]!=0){
                int w = nega(num);
				if (mp[w] != 0)
                mp[w]--;
				mp[num]--;
				ans++;
            }
        }
        // for(int i=0;i<n;i++){
        //     if(mp[num[i]]==0)
        //         continue;
        //     int w = p&(~num[i]);
        //     mp[num[i]]--;
        //     if(mp[w])
        //     mp[w]--;
        //     ans++;
        // }
        cout<<ans<<"\n";
    }   
    return 0;
}