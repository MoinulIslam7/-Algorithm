#include<bits/stdc++.h>
using namespace std;
float profit[100], weight[100];
float x[100];

void knapsack(int m, int n)
{
    for(int i=1; i<=n; i++)
    {
        int max = i;
        for(int j=i+1; j<=n; j++)
        {
            if(profit[j]/weight[j] > profit[max]/weight[max])
            {
                max = j;
            }
        }
        swap(profit[max], profit[i]);
        swap(weight[max], weight[i]);
    }
    int u=m;
    int i;
    for(i=1; i<=n; i++)
    {
        if(weight[i]>u)
            break;
        x[i]= 1;
        u = u - weight[i];
    }
    if(i<=n)
    {
        x[i] = u/weight[i];
    }
}
void profit_calculation(int n)
{
    float sum =0;
    for(int i=1; i<=n; i++)
    {
        sum+=x[i]*profit[i];
    }
    cout << sum <<endl;
}
int main()
{
    int n;
    cout << "Enter the number of item : ";
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cout << "Enter item number "<< i << " profit and weight : ";
        cin >> profit[i] >> weight[i];
    }
    int cap;
    cout << "Enter capacity : ";
    cin >> cap;
    knapsack(cap,n);
    cout << endl << "After sorting according to the unit profit : " << endl;
     for(int i=1; i<=n; i++)
        cout << profit[i] << " ";
        cout << endl;
    for(int i=1; i<=n; i++)
        cout << weight[i] << " ";
    cout << endl;
    cout << "we can take the item respectively portions of: "<< endl;
    for(int i=1; i<=n; i++)
        cout << x[i] << " ";
    cout << endl;
    cout << "Total profit is : ";
    profit_calculation(n);
    return 0;
}
