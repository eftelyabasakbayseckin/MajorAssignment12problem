#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*PROBLEM2: GREEDY ALGORITHM*/

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
        int max_deadline = arr[0].dead;
        for (int i = 1; i < n; i++)
            max_deadline = max(max_deadline, arr[i].dead);
        vector<int> sequence(max_deadline + 1, -1);
        sort(arr, arr + n, comp);

        int countJobs = 0;
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {

            for (int j = arr[i].dead; j > 0; j--) {
                if (sequence[j] == -1) {
                    sequence[j] = arr[i].id;
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return { countJobs, maxProfit };
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