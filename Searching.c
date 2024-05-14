#include <stdio.h>

void binary(int arr[],int element,int n)
{
    int l=0;
    int h=n;

    while(l<h)
    {
        int m=(l+h)/2;
        if(arr[m]==element)
        {
            printf("Found\n");
            return;
        }

        else if(arr[m]<element)
        {
            l=m+1;
        }
        else if(arr[m]>element)
        {
            h=m-1;
        }
    }
    printf("Not found\n");
}

void lin(int arr[],int element,int n)
{
    for(int i=0;i<n;i++)
        if(element==arr[i])
        {
            printf("Found\n");
            return;
        }
    printf("Not Found\n");
}

void main()
{
    int arr[]={-5,-2,0,4,9,12,13,67,78,97,101};
    int n=sizeof(arr)/sizeof(arr[0]);

    binary(arr,10,n);
    lin(arr,101,n);
    binary(arr,101,n);
}

