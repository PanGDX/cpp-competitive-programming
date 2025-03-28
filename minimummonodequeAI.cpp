#include <iostream>
#include <deque>
using namespace std;

void print_sliding_window_min(int arr[], int n, int k) {
    // Create a deque and add first k elements to it
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] <= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process rest of the elements
    for (int i = k; i < n; i++) {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] <= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()];
}

int main() {
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    print_sliding_window_min(arr, n, k);
    return 0;
}

