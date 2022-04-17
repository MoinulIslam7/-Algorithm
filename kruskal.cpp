' #include<iostream>
using namespace std;
int V,E,int_max=10000;
int parent[100];
int cost[100][100];
int finder(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}
void union1(int i, int j)
{
    int a,b;
    a = finder(i);
    b = finder(j);
    parent[a] = b;
}
void kruskalMST()
{
    int min_cost = 0;
    int edge_cunt = 0;
    while(edge_cunt < V-1)
    {
        int min = int_max, a=-1, b=-1;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(finder(i)!= findervbbn    (j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a,b);
        cout << "Edge " << edge_cunt++ << ": ( " << a << " " << b << ") cost = " << min << endl;
        min_cost += min;
    }
    cout << endl << endl << "Minimum cost : " << min_cost << endl;
}
int main()
{
    cin >> V >> E;
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            cost[i][j]=int_max;
    for(int j=0; j<E; j++)
    {
        int m,n;
        cin >> m >> n;
        cin >> cost[m][n];
    }
    for(int i=0; i<V; i++)
        parent[i] = i;

    kruskalMST();
    return 0;
}
