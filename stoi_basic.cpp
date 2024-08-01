class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0; 
        for(int i = 0; i < details.size(); i++){
            string agee = details[i].substr(11, 2);
            int age = stoi(agee);
            if(age > 60){
                count++;
            }
        }
        return count;
    }
};

