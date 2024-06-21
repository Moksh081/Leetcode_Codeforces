class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int n = customers.size();
       int sum = 0;
       vector<int> visited(n, 0);
       
       // Calculate initial satisfaction when the owner is not grumpy
       for (int i = 0; i < n; i++) {
           if (grumpy[i] == 0) {
               sum += customers[i];
               visited[i] = 1; // Mark as satisfied
           }
       }
       
       // Use a sliding window approach to calculate the additional satisfaction
       int max_additional_satisfaction = 0;
       int current_additional_satisfaction = 0;
       
       // Initial window of size 'minutes'
       for (int i = 0; i < minutes; i++) {
           if (grumpy[i] == 1) {
               current_additional_satisfaction += customers[i];
               visited[i] = 1; // Mark as satisfied in the current window
           }
       }
       max_additional_satisfaction = current_additional_satisfaction;
       
       // Slide the window over the array
       for (int i = minutes; i < n; i++) {
           if (grumpy[i] == 1) {
               current_additional_satisfaction += customers[i];
               visited[i] = 1; // Mark as satisfied in the current window
           }
           if (grumpy[i - minutes] == 1) {
               current_additional_satisfaction -= customers[i - minutes];
               visited[i - minutes] = 0; // Unmark as satisfied as it is out of the window
           }
           max_additional_satisfaction = max(max_additional_satisfaction, current_additional_satisfaction);
       }
       
       // Adding additional satisfied customers from the best window
       sum += max_additional_satisfaction;
       
       return sum;
    }
};

