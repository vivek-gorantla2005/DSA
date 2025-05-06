#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
public:
    void inputArray(vector<int>& arr) {
        int n;
        cout << "Enter number of elements in the array: ";
        cin >> n;
        cout << "Enter the elements in the array: ";
        for (int i = 0; i < n; i++) {
            int inp;
            cin >> inp;
            arr.push_back(inp);
        }
    }

    void sort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

private:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int start = low;
        int end = mid + 1;

        while (start <= mid && end <= high) {
            if (arr[start] <= arr[end]) {
                temp.push_back(arr[start++]);
            } else {
                temp.push_back(arr[end++]);
            }
        }

        while (start <= mid) temp.push_back(arr[start++]);
        while (end <= high) temp.push_back(arr[end++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
};

int main() {
    vector<int> arr;
    MergeSort ms;
    ms.inputArray(arr);
    ms.sort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
