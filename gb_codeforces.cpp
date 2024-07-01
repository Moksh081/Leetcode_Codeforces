#include <iostream>
using namespace std;

int helper(int n, int k) {
    return n + (n - 1) * (k - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = helper(n, k);
        cout << ans << endl;
    }
    return 0;
}

