#include<stdio.h>
int main(){
int n;
printf("enter number of elements in array\n");
scanf("%d",&n);
int arr[n];
printf("enter elements \n");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int small=arr[0];
int i;
for(i=0;i<n;i++){
    if(arr[i]<small){
        small=arr[i];
        printf("smallest element is %d and found at %d ",small,i+1);
    }
}
return 0;
}
