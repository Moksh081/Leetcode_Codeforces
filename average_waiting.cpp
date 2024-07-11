class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long curr = 0;  // Initialize current time to 0
        long long sum = 0;   // To store the total waiting time
        int n = customers.size();

        for (int i = 0; i < n; i++) {
            // If the chef is idle, start at the customer's arrival time
            if (curr < customers[i][0]) {
                curr = customers[i][0];
            }
            curr += customers[i][1];  // Add the cooking time to the current time
            sum += curr - customers[i][0];  // Calculate waiting time and add to the sum
        }

        return static_cast<double>(sum) / n;  // Return the average waiting time
    }
};

