#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PROBLEM#1: GREEDY ALGORITHM

class Solution {
public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({ end[i], start[i] });
        }
        sort(arr.begin(), arr.end());
        int ans = arr[0].first;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i].second > ans) {
                ans = arr[i].first;
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n = 6;
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };

    Solution ob;
    int ans = ob.maxMeetings(start, end, n);
    cout << "Maximum meeting: " << ans << endl;

    return 0;
}