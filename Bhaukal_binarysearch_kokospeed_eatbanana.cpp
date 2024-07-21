class Solution {
public:
    int helper(int speed, vector<int>& piles) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;  // This is equivalent to ceil(pile / speed)
        }
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hoursNeeded = helper(mid, piles);
            
            if (hoursNeeded <= h) {
                right = mid;  // Try to find a smaller speed
            } else {
                left = mid + 1;  // Increase the speed
            }
        }
        
        return left;
    }
};

