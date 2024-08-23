class Solution {
public:
    std::string fractionAddition(std::string expression) {
        int num = 0;
        int den = 1;
        int n = expression.length();
        int i = 0;
        
        while (i < n) {
            int curNum = 0;
            int curDen = 0;
            bool isNeg = false;
            char ch = expression[i];
            
            if (ch == '+' || ch == '-') {
                if (ch == '-') {
                    isNeg = true;
                }
                i++;
            }

            // Form the numerator
            int start = i;
            while (isdigit(expression[i])) {
                i++;
            }
            curNum = std::stoi(expression.substr(start, i - start));
            if (isNeg) curNum *= -1;
            i++; // Skip '/'
            
            // Form the denominator
            start = i;
            while (i < n && isdigit(expression[i])) {
                i++;
            }
            curDen = std::stoi(expression.substr(start, i - start));
            
            num = num * curDen + curNum * den;
            den *= curDen;
        }

        int gcd = std::abs(std::gcd(num, den));
        num /= gcd;
        den /= gcd;
        
        return std::to_string(num) + "/" + std::to_string(den);
    }
};
