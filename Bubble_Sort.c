#include <stdio.h>
void main()
{
    int arr[]={10,6,8,12,1,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);

   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(arr[j]<arr[i])
           {
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
       }
   }

   for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}


