#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter job number: " << endl;
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    sort(jobs.begin(), jobs.end(), cmp);
    int maxDeadline = 0;
    for (auto &j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);
    vector<int> slot(maxDeadline + 1, -1);
    int maxProfit = 0;
    vector<int> sequence;
    for (auto &j : jobs)
    {
        for (int d = j.deadline; d >= 1; d--)
        {
            if (slot[d] == -1)
            {
                slot[d] = j.id;
                maxProfit += j.profit;
                sequence.push_back(j.id);
                break;
            }
        }
    }
    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Jobs: ";
    for (int id : sequence)
        cout << id << " ";
    cout << endl;
    ;
    return 0;
}
