#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int scored[22];
        int wickets[22];
        int points[22];
        int max = 0;
        int k = 0; // Initialize k to avoid uninitialized value
        
        for (int i = 0; i < 22; i++) {
            cin >> scored[i] >> wickets[i];
        }
        
        for (int i = 0; i < 22; i++) {
            points[i] = scored[i] + (20 * wickets[i]);
            if (points[i] > max) {
                max = points[i];
                k = i + 1;
            }
        }
        
        cout << k << endl;
    }
    
    return 0;
}

