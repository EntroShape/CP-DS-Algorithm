#include<iostream>
using namespace std;
const int llmax = 1e6+5;
int brr[llmax],arr[llmax];
long long res;

void msort(int l,int r){
if (l==r) return;    
int mid = (l+r)>>1;
msort(l,mid),msort(mid+1,r);

int i=l,j=mid+1,k=l;
while(i<=mid && j<=r){
    if(arr[i]>arr[j]){
        brr[k++]=arr[i++],
        //res+=r-j+1;
    }
    else brr[k++]=arr[j++];
    } 
while(i<=mid) brr[k++]=arr[i++];
while(j<=r) brr[k++]=arr[j++];

for(int i=l;i<=r;i++){
        arr[i]=brr[i];
    }
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    msort(0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    //cout<<res;
    return 0;    
}
