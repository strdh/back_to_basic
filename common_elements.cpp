#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> common_elements(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> s(arr1.begin(), arr1.end());
    vector<int> result;

    for (int i = 0; i < arr2.size(); i++) {
        if (s.count(arr2[i])) {
            result.push_back(arr2[i]);
            s.erase(arr2[i]);
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};

    vector<int> result = common_elements(arr1, arr2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
