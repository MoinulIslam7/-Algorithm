#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>
    myvec[10];
    int n=10;
    int e=17;
    int x,y,i;
    for(int i=0; i<15; i++)
    {
        cin >> x >> y;
        myvec[x].push_back(y);
    }

    for(int i=1; i<n; i++)
    {
        cout << i << "->";
        for(int j=0; j<myvec[i].size(); j++)
        {

            cout << myvec[i][j] << " ";

        }
         cout << endl;
    }
}

