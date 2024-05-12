#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*PROBLEM 3 REPEAT PREVIOUS PROBLEM 2 USING DYNAMIC PROGRAMMING*/

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    static bool comp(const Job& job1, const Job& job2) {
        return job1.profit > job2.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comp);
        int maxDeadline = 0;
        for (int i = 0; i < n; ++i) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        vector<int> dp(maxDeadline + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = arr[i].dead; j > 0; --j) {
                if (dp[j] == 0) {
                    dp[j] = arr[i].profit;
                    break;
                }
            }
        }
        int totalProfit = 0;
        int scheduledJobs = 0;
        for (int i = 1; i <= maxDeadline; ++i) {
            totalProfit += dp[i];
            if (dp[i] > 0) {
                ++scheduledJobs;
            }
        }
        return { scheduledJobs, totalProfit };
    }
};

int main() {
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    Solution solution;
    vector<int> result = solution.JobScheduling(jobs, n);
    cout << "Number of jobs scheduled: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;
    return 0;
}