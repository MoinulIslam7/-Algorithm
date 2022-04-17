#include<iostream>
using namespace std;
void Merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(i=0; i<n1; i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]= arr[m+1+j];
    }
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
            arr[k]= R[j];
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
        arr[k]= R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}
void printarray(int A[], int size)
{
    int i;
    for(i=0; i< size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10]= {12,11,13,5,7,6,22,21,1,35};
    int array_size= 10;

    mergesort(arr,0,array_size-1);
    cout << "Sorted array is : ";
    printarray(arr,array_size);
    return 0;
}
