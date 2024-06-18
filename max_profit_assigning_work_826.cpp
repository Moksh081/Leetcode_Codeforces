#include <vector>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sum = 0;
        int n = difficulty.size();
        int m = worker.size();
        
        for(int j = 0; j < m; j++) {
            int maxProfitForWorker = 0;
            for(int i = 0; i < n; i++) {
                if(worker[j] >= difficulty[i]) {
                    maxProfitForWorker = max(maxProfitForWorker, profit[i]);
                }
            }
            sum += maxProfitForWorker;
        }
        
        return sum;
    }
};

