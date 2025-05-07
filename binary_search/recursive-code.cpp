#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int tar) {
    if (low > high) {
        return -1; // Not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == tar) {
        return mid; 
    } else if (arr[mid] < tar) {
        return binarySearch(arr, mid + 1, high, tar);
    } else {
        return binarySearch(arr, low, mid - 1, tar);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 134, 121, 45, 21, 145, 66, 34};
    sort(arr.begin(), arr.end());

    int target = 121;
    int index = binarySearch(arr, 0, arr.size() - 1, target);

    if (index != -1) {
        cout << "Found " << target << " at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
