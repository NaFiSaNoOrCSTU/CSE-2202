#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> activity(n);
    for (int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        activity[i] = {f, s};
    }

    sort(activity.begin(), activity.end());
    int count = 1;
    int lastFinish = activity[0].first;

    for (int i = 1; i < n; i++)
    {
        if (activity[i].second >= lastFinish)
        {
            count++;
            lastFinish = activity[i].first;
        }
    }
    cout << "Maximum count: " << count << endl;
    return 0;
}
