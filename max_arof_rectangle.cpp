#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxHist(vector<int>& row) 
    { 
        stack<int> result; 
        int top_val; 
        int max_area = 0; 
        int area = 0; 
        int i = 0; 
        int C = row.size();
        
        while (i < C) { 
            if (result.empty() || row[result.top()] <= row[i]) 
                result.push(i++); 
            else { 
                top_val = row[result.top()]; 
                result.pop(); 
                area = top_val * i; 

                if (!result.empty()) 
                    area = top_val * (i - result.top() - 1); 

                max_area = max(area, max_area); 
            } 
        } 

        while (!result.empty()) { 
            top_val = row[result.top()]; 
            result.pop(); 
            area = top_val * i; 

            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 

            max_area = max(area, max_area); 
        } 
        return max_area; 
    } 
  
    int maximalRectangle(vector<vector<char>>& A) 
    { 
        if (A.empty()) return 0;
        
        int R = A.size();
        int C = A[0].size();
        int result = 0;
        
        vector<int> heights(C, 0);

        for (int i = 0; i < R; i++) { 
            for (int j = 0; j < C; j++) { 
                if (A[i][j] == '1') 
                    heights[j] += 1;
                else 
                    heights[j] = 0;
            } 
            result = max(result, maxHist(heights)); 
        } 

        return result; 
    } 
};

