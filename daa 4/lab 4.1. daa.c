#include <stdio.h>
int cntEle(int* arr, int arrSize) {
    int cnt[1001]={0}; 
    for (int i=0;i<arrSize;i++) {
        cnt[arr[i]]++;
    }
    int ans = 0;
    for (int x=0;x<1000;x++) {
        if (cnt[x+1]>0){
            ans+=cnt[x];
        }
    }
    return ans;
}
int main() {
    int arr[]={1,2,3};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    int result=countElements(arr, arrSize);
    printf("Result: %d\n",result);
    return 0;
}
