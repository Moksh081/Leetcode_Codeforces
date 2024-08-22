#include <iostream>
#include <vector>
using namespace std;

void fn(vector<int> &ds, int ind, int arr[], int n) {
    if (ind >= n) {
        for (int i = 0; i < ds.size(); i++) {
            cout << ds[i] << " ";
        }
        if (ds.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    fn(ds, ind + 1, arr, n);  // Corrected semicolon to a comma
    ds.pop_back();
    fn(ds, ind + 1, arr, n);  // Corrected semicolon to a comma
}

int main() {
    int arr[] = {3, 2, 1};
    int n = 3;
    vector<int> ds;
    fn(ds, 0, arr, n);
    return 0;
}

