/******** rotate binary search ********
    Binary search on a sorted array that was rotated once
**************************************/

#include <iostream>
using namespace std;

// get rotation offset
int getOffset(int a[], int len) {
    int high = len - 1, low = 0, mid = low + (high - low) / 2;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[low] < a[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// binary search with offset
int search(int a[], int len, int elem) {
    int offset = getOffset(a, len);
    int low = 0, high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[(mid + offset) % len] < elem)
            low = mid + 1;
        else if (a[(mid + offset) % len] > elem)
            high = mid - 1;
        else
            return (mid + offset) % len;
    }
    return -1;
}
