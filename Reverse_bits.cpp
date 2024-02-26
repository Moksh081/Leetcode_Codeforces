class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;           // Left shift result to make space for the next bit
            result |= (n & 1);      // Set the least significant bit of result to the least significant bit of n
            n >>= 1;                // Right shift n to get the next bit
        }
        return result;
    }
};
