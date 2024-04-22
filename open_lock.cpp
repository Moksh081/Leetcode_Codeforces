class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dict(deadends.begin(), deadends.end());
        unordered_set<string> used;
        
        string st = "0000";
        if(dict.count(st))
            return -1;
        
        int cnt=0;
        queue<string> q;
        q.push(st);
        used.insert(st);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string curr = q.front();
                q.pop();
                
                if(curr == target)
                    return cnt;

                for(int i=0; i<4; i++) {
                    string tmp = curr;
                    
                    char ch = tmp[i];
                    int num = ch -'0';
                    int x = (num+11)%10, y=(num+9)%10;
                    
                    tmp[i] = x+'0';
                    if(!used.count(tmp) && !dict.count(tmp)) {
                        q.push(tmp);
                        used.insert(tmp);
                    }
                    
                    tmp[i] = y+'0';
                    if(!used.count(tmp) && !dict.count(tmp)) {
                        q.push(tmp);
                        used.insert(tmp);
                    }
                }
            }
            cnt++;
        }
        
        return -1;
    }
};
