class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }
        vector<pair<char, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second > b.second;
        });
        string result;
        for (auto& p : vec) {
            result.append(p.second, p.first);
        }
        return result;
    }
};
