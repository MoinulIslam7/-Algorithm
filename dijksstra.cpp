#include<iostream>
#include<stdio.h>
#define infinity 99
#define max 100
using namespace std;
int Graph[max][max];
void dijkstra(int n, int startnode)
{
    int distance[max], previous[max];
    int visited[max]= {0},cunt=0,mindistance,nextnode,i,j;
    for(i=0; i<n; i++)
    {
        previous[i]=startnode;
        distance[i]= Graph[startnode][i];
    }
    distance[startnode]=0;
    visited[startnode]=1;
    cunt =1;
    while(cunt<n-1)
    {
        mindistance = infinity;
        for(i=0; i<n; i++)
        {
            if(distance[i]< mindistance  && visited[i]==0)
            {
                mindistance=distance[i];
                nextnode=i;

            }
        }
        visited[nextnode]=1;
        for(i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                if(mindistance + Graph[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance + Graph[nextnode][i];
                    previous[i]=nextnode;
                }
            }
        }
        cunt++;
    }
    for(i=0; i<n; i++)
    {
        if(i!=startnode)
        {
            printf("\nDistance of node %c=%c", i+65, distance[i]+65);
            printf("\npath = %c",i+65);
            j=i;
            do
            {
                j=previous[j];
                printf(" <- %c",j+65);
            }
            while(j!=startnode);
        }
    }
}
int main()
{
    int i,j,n,start;
    cout << "enter number of vertex : ";
    cin >> n;
    cout << "enter the adjacency matrix : " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> Graph[i][j];
        }
    }
    cout << "Enter the starting node: ";
    cin >> start;
    dijkstra(n,start);
}

/*input
0 2 3 99 99 99
2 0 99 5 4 99
3 99 0 99 1 99
99 5 99 0 2 3
99 4 1 2 0 4
99 99 99 3 4 0
*/

