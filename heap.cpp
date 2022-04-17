#include <iostream>
using namespace std;
void max_heapify(int heap[], int n, int i)
{
    int largest = i,t;
    int left = 2*i;
    int right = 2*i + 1;
    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        t= heap[i];
        heap[i]= heap[largest];
        heap[largest]= t;

        max_heapify(heap, n, largest);
    }
}
void heap_Sort(int heap[], int n)
{
    int t;
    for (int i = n / 2 - 1; i >= 1; i--)
        max_heapify(heap, n, i);
    for (int i=n-1; i>1; i--)
    {
         t= heap[1];
        heap[1]= heap[i];
        heap[i]= t;
        max_heapify(heap, i, 1);
    }
}
void print_heap(int heap[], int n)
{
    for (int i=1; i<n; ++i)
        cout << heap[i] << " ";
}
int main()
{
    int heap[10] = {0,30,3,20,11,1,8,2,17,4};
    int n = 10;

    heap_Sort(heap, n);
    cout << "Sorted heap is : ";
    print_heap(heap, n);
}
