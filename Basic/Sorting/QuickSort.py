#include<iostream>
#include<vector>
using namespace std;
const int mmax = 1e5+5;
int arr[mmax];
//输入格式
//第一行为一个正整数
//第二行包含 N 个空格隔开的正整数 ，为你需要进行排序的数。
//输出格式
//将给定的 N 个数从小到大输出，数之间空格隔开，行末换行且无空格
void qsort(int l,int r) {
    if(l==r) return;
    int i=l-1, j=r+1, x=arr[(l+r)/2];
    while(i<j){
        while(arr[++i]<x);
        while(arr[--j]>x);
        if(i<j) swap(arr[j],arr[i]);
    }
    qsort(l,j),qsort(j+1,r);
}
 
int main() {
    int n;
    cin>>n;
     arr[n] = {};
    for(int i=0;i!=n;i++)(cin>>arr[i]);
    qsort(0,n-1);
    for(int i=0;i!=n;i++)(cout<<arr[i]<<" ");
    return 0;    
}
