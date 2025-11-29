#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cout << "enter n " << endl;
    cin >> n;
    int a[n];
    cout << "enter n elements " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // ascending order-O(n^2)
    for(int i=0;i<n-1;++i)
    {
        bool isSwap=false;
        for(int j=0;j<n-i-1;++j)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap) break; // array is already sorted,so no swaping
    }
    cout << "after bubble sorting in ascending order: ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}