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
int key;
printf("element to search \n");
scanf("%d",&key);
int i;
for(i=0;i<n;i++){
    if(arr[i]==key){
        printf("found at position %d ",i+1);
        break;
    }
}
if(i==n){
    printf("not found ");
}
return 0;
}
