class Solution {
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); // Corrected: Convert string to lowercase using transform

        int k = s.size();
        int count_a = 0, count_b = 0; // Corrected: Added comma to declare both variables separately

        for (int i = 0; i < k / 2; ++i) { // Corrected: Changed condition to i < k / 2
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count_a++;
            }
        }

        for (int i = k / 2; i < k; ++i) { // Corrected: Changed condition to i < k
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count_b++;
            }
        }

        return count_a == count_b;
    }
};
