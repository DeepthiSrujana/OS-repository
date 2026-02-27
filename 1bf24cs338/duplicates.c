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
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                printf("duplicates are present \n ");
                break;
            }
}
}
return 0;
}
