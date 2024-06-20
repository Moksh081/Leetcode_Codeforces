//Replace words on diary 
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    // Convert the dictionary to a set for O(1) average-time complexity lookups
    set<string> dict(dictionary.begin(), dictionary.end());

    // Split the sentence into words
    istringstream iss(sentence);
    string word;
    string result;

    while (iss >> word) {
        string prefix;
        for (int i = 1; i <= word.length(); ++i) {
            prefix = word.substr(0, i);
            if (dict.find(prefix) != dict.end()) {
                break;
            }
        }
        result += prefix + " ";
    }

    // Remove the trailing space
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}
};
