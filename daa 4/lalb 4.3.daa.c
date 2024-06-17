#include <stdio.h>
#include <limits.h>
#define N 3
int search(int mat[N][N],int n,int m) {
    int a=INT_MAX;
    for (int i=0;i<n;i++) {
        int low=0;
        int high=m-1;
        int ans=INT_MAX;
        while(low<=high) {
            int mid=(low+high)/2;
            if (mat[i][mid]==1) {
                if (mid==0) {
                    ans=0;
                    break;
                } else if (mat[i][mid-1]==0) {
                    ans=mid;
                    break;
                }
            }
            if (mat[i][mid]==1) {
                high=mid-1;
            } else {
                low=mid + 1;
            }
        }
        if (ans<a){
            a=ans;
        }
    }
    if (a==INT_MAX) {
        return -1;
    }
    return a+1;
}
int main() {
    int mat[N][N]={
        {0,0,0},
        {0,0,1},
        {0,1,1}
    };
    printf("%d\n",search(mat,N,N));
    return 0;
}
