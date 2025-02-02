#include<iostream>
#include<cmath>
using namespace std;
const int llmax = 1000;
int f[llmax][llmax];
//循环条件是直到i+(1<<(j))-1<=n
//区间长度=K=log2(l-r+1)
//查询时是分别从左右两边查询
int main(){
    int n,m;
    cin>>n>>m;    
    for(int i=1;i<n;i++) cin>>f[i][0];
    
    for(int j=1;j<=20;j++){//构建Sparse_Table
        for(int i=1;i+(1<<(j))-1<=n;i++){//这个是区间终点
                f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);//左边和右边
            }
        }
    while(m--){//给定闭区间，给出最大值
        int l,r;
        cin>>l>>r;        
        int k=log2(l-r+1);
        cout<<max(f[l][k],f[r-l+1][k])<<endl;//
    }
    
    return 0;   
}
