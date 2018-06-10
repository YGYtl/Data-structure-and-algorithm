#include<stdio.h>
#define max 1000005
int main(){
    int n, k, i=0;
    int a[max];
    scanf("%d",&k);
    while(1){
        scanf("%d",&a[i]);
        if(a[i]<0)
            break;
        i++;
    }
    if(i-k>=0)
        printf("%d",a[i-k]);
    else
        printf("NULL"); 
    return 0;
}  
