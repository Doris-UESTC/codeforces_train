#include<bits/stdc++.h>
using namespace std;
bool onSegment(int i1 , int j1 ,int i2 ,int j2 , int i3,int j3)
{
    if((i3 - i1) * (j2 - j1) == (i2 - i1) * (j3 - j1)  //叉乘 
       //保证Q点坐标在pi,pj之间 
       && min(i1 , i2) <= i3 && i3 <= max(i1 , i2)    
       && min(j1 , j2) <= j3 && j3 <= max(j1 , j2))
        return true;
    else
        return false;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,i1,j1,i2,j2,dir;
        string d;
        cin>>n>>m>>i1>>j1>>i2>>j2>>d;
        if(d=="DL"){
            int dis=min(n-i1,j2);
            int tmp_i1=i1+dis;
            int tmp_j1=j1-dis;
            if(onSegment(i1,j1,tmp_i1,tmp_j1,i2,j2)){
                cout<<"0"<<endl;
            }else{
                
            }
                
        }else if(d=="UR"){

        }else if(d=="DR"){

        }else{

        }
    }
}