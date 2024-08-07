#include <string>
#include <vector>

class Solution {
private:
    std::vector<std::string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    std::vector<std::string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    std::vector<std::string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

public:
    std::string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return helper(num);
    }

private:
    std::string helper(int num) {
        if (num < 10) {
            return belowTen[num];
        } else if (num < 20) {
            return belowTwenty[num - 10];
        } else if (num < 100) {
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + belowTen[num % 10] : "");
        } else if (num < 1000) {
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + helper(num % 100) : "");
        } else if (num < 1000000) {
            return helper(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + helper(num % 1000) : "");
        } else if (num < 1000000000) {
            return helper(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + helper(num % 1000000) : "");
        } else {
            return helper(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + helper(num % 1000000000) : "");
        }
    }
};

