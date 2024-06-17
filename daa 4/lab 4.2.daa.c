#include<stdio.h>
#include<string.h>
void strshift(char* s,int shift[][2],int shiftSize) {
    int val=0;
    for (int i=0;i<shiftSize;++i) {
        val+=shift[i][0]==0?-shift[i][1]:shift[i][1];
    }
    int len strlen(s);
    val=val%len;
    if (val<0){
        val=(val+len)%len;
    }
    char result[1001]; 
    if (val>0) {
        strncpy(result,s+len-val,val);
        strncpy(result+val,s,len-val);
    } else {
        strncpy(result,s,len);
    }
    result[len]='\0';
    printf("%s\n",result);
}
int main() {
    char s[] = "abc";
    int shift[][2] = {
        { 0, 1 },
        { 1, 2 }
    };
    int shiftSize = sizeof(shift) / sizeof(shift[0]);
    stringShift(s, shift, shiftSize);
    return 0;
}
