/*codeforces 1186D https://codeforces.com/problemset/problem/1186/D*/
/*输入为n，以及n个数，这n个小数和为0，对这n个小数进行ceil或者floor操作，使得操作之后和仍为0，输出结果*/
#include<bits/stdc++.h>
using namespace std;
double rec[100050];
int ceil_rec[100050];
double EPS=1e-8;
int main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>rec[i];
        ceil_rec[i]=ceil(rec[i]);
        sum+=ceil_rec[i];
    }
    for(int i=0;i<n;i++){
        if(abs(ceil_rec[i]-rec[i])<EPS){
            cout<<ceil_rec[i]<<endl;
        }else{
            if(sum>0){
                cout<<ceil_rec[i]-1<<endl;
                sum--;
            }else{
                cout<<ceil_rec[i]<<endl;
            }
        }
    }
    return 0;
}
/*几个需要注意的问题，double和float的区别  如何判断为整数*/