class Solution {
public:
    int helper(string boxes, int i) {
        int sum = 0;
        for (int j = 0; j < boxes.size(); j++) {
            if (boxes[j] == '1') {  // Check if there's a ball in box j
                sum += abs(i - j);  // Calculate the distance and add to sum
            }
        }
        return sum;
    }

    vector<int> minOperations(string boxes) {
        vector<int> answers(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); i++) {
            answers[i] = helper(boxes, i);  // Call helper for each position
        }
        return answers;
    }
};

