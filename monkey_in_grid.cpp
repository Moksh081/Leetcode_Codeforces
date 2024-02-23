#include <iostream>
using namespace std;

void asquare()
{
   int n, m, x, y, l;
    cin >> n >> m >> x >> y >> l;
   int a = ((n - x) / l) + ((x - 1) / l) + 1;
   int b = ((m - y) / l) + ((y - 1) / l) + 1;
   long long ans = 1LL * a * b; // Ensure that the result does not overflow
    cout << ans << "\n";
}

//Main
int main()
{
    int t;
    cin >> t;
    while(t--){
        asquare();
    }
    return 0;
}

