#include<iostream>
using namespace std;
void insertion_sort(int n,int data[])
{
    int i,j,temp;
    for(i=0; i<n; i++)
    {
        j=i;
        while(j>0 && data[j] < data[j-1])
        {
            swap(data[j], data[j-1]);
            j--;
        }
    }
}
void print_elements(int n,int data[])
{
    int i;
    cout << "in ascending order : ";
    for(i=0; i<n; i++)
    {
        cout << data[i] << " ";
    }
}
int main()
{
    int n=10;
    int data[n]={99,88,77,66,55,44,33,22,11,00};
    insertion_sort(n,data);
    print_elements(n,data);
}
