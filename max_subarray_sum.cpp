#include <iostream>

using namespace std;

int max_subarray_sum(int arr[], int n) {
    int max_sum = arr[0], current_sum = arr[0];
    for (int i = 1; i<n; i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int n = 8;
    int arr[n] = {1, -2, 3, 10, -4, 7, 2, -5};

    cout<<"max subarray sum : "<<max_subarray_sum(arr, n)<<endl;
    return 0;
}