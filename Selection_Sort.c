#include <stdio.h>

int arr[]={10,20,7,27,16,-24,30,40,50,-12,-3,11,14};
int n=sizeof(arr)/sizeof(arr[0]);

void main()
{
    printf("\nBefore sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

    printf("\n\nAfter sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
