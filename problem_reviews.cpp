#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int flag = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] <= 4) {
                flag = 1;
            }
        }
        
        if (flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

