#include <iostream>
using namespace std;

/*PROBLEM 10: DIVIDE AND CONQUER*/ 

int find(int arr1[], int arr2[], int m, int n, int k) {
    int d = 0, i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            d++;
            if (d == k)
                return arr1[i];
            i++;
        }
        else {
            d++;
            if (d == k)
                return arr2[j];
            j++;
        }
    }

    while (i < m && d < k) {
        d++;
        if (d == k)
            return arr1[i];
        i++;
    }

    while (j < n && d < k) {
        d++;
        if (d == k)
            return arr2[j];
        j++;
    }

    // If k is out of bounds
    return -1; // Indicate that k is out of bounds
}

int main()
{
    int A[5] = { 2, 3, 6, 7, 9 };
    int B[4] = { 1, 4, 8, 10 };
    int k = 5;
    cout << find(A, B, 5, 4, k);
    return 0;
}