#include <stdio.h>

int arr[]={10,20,7,27,16,-24,30,40,50,-12,-3,11,14};
int n=sizeof(arr)/sizeof(arr[0]);

void main()
{
    printf("Before Sorting:-\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    printf("\nAfter Sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
