#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

/* PROBLEM11: DIVIDE AND CONQUER*/

class Solution {
public:
    bool check(int A[], int N, int M, int mid) {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < N; i++) {
            if (A[i] > mid) {
                return false;
            }
            if (sum + A[i] > mid) {
                count += 1;
                sum = A[i];
                if (count > M) {
                    return false;
                }
            }
            else {
                sum += A[i];
            }
        }
        return true;
    }

    int findPages(int A[], int N, int M) {
        if (N < M) {
            return -1;
        }

        int x = accumulate(A, A + N, 0);
        int low = 1, high = x, mid;
        int ans = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (check(A, N, M, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int N = 4;
    int A[] = { 12, 34, 67, 90 };
    int M = 2;
    cout << "Min number of pages: " << obj.findPages(A, N, M) << endl;
    return 0;
}