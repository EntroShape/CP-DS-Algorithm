#include<iostream>
#include<vector>
using namespace std;
const int mmax = 1e5+5;
int arr[mmax];

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