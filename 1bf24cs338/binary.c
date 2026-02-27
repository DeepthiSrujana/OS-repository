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
int low=0;
int high=n-1;
while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==key){
        printf("found at position  %d ",mid+1);
        break;
    }
    else if(arr[mid]<key){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
if(low>high){
    printf("not found");
}
return 0;
}
