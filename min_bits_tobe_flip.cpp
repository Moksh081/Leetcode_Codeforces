class Solution {
public:
    // Function to count the number of 1s in the binary representation of a number
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1); // Check if the least significant bit is 1
            n >>= 1; // Right shift n by 1 to check the next bit
        }
        return count;
    }

    // Function to calculate minimum bit flips needed to convert start to goal
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal; // XOR gives the bits that are different
        return countSetBits(xorResult); // Count the number of set bits in the XOR result
    }
};

