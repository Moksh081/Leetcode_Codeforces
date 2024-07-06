class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int direction = 1;  // 1 for forward, -1 for backward
        
        while (time > 0) {
            i += direction;
            time--;
            
            // Change direction if we reach the first or last person
            if (i == n || i == 1) {
                direction = -direction;
            }
        }
        
        return i;
    }
};

