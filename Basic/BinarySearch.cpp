//最大化查找
int find(int q){
int l=0,r=n+1 
while(l+1<r){//精度
    int mid = (l+r)>>1;
    if(arr[mid]<=q) l=mid;  //缩放左可行区
    else r = mid;
}
return l;
}
//最小化查找
int find(int q){
int l=0,r=n+1;
while(l+1<r){//精度
    int mid = (l+r)>>1;
    if(arr[mid]>=q) r = mid; //缩放右可行区
    else l = mid
    }
return r;
}
