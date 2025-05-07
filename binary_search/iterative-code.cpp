#include<iostream>
#include<vector>
#include<algorithm> // For sort
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 134, 121, 45, 21, 145, 66, 34};

    sort(arr.begin(), arr.end()); 

    int low = 0;
    int high = arr.size() - 1;
    int tar = 121;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == tar) {
            cout << "Found " << tar << " at index " << mid << endl;
            return 0;
        } else if (arr[mid] < tar) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return 0;
}
