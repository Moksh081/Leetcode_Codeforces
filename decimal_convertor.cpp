class Solution {
public:
    int hammingWeight(uint32_t n) {
        int binaryNum[32]; // Assuming 32-bit integer

        int i = 0;
        while (n > 0) {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        int k = i; // Use the value of i as the size of the array
        int count = 0;
        for(int j = 0; j < k; j++){ // Changed the loop variable to j to avoid conflict
            if(binaryNum[j] == 1){
                count++;
            }
        }
        return count;
    }
};

