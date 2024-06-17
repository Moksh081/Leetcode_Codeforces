#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int function(int n, vector<int>& pages) {
        if (n < 2) return 0; 
        int k,sum;
        if(n%2==0){
        	k = n/2 - 1;
        	sum = pages[k] + pages[n-1];
		}else{
			k = n/2 ;
			sum = pages[k] + pages[k+k];
		}
        
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> pages(n);
        for (int i = 0; i < n; i++) {
            cin >> pages[i];
        }
        
        Solution solution;
        int result = solution.function(n, pages);
        cout << result << endl;
    }
    
    return 0;
}

