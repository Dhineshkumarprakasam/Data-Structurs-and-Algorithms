#include <stdio.h>

void merge(int arr[],int l,int m,int r)
{
    int i,j,k;

    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        R[j]=arr[m+j+1];
    
    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}


void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}


void main()
{
    int arr[]={11,4,16,8,29,3,5,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);

    printf("\n\n");

    mergesort(arr,0,size-1);

    for(int j=0;j<size;j++)
        printf("%d ",arr[j]);
}
