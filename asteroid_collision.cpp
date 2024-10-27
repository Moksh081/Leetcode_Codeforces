class Solution {
public:
    bool sameSign(int top, int n)
    {
        if((top<0 && n<0 )||(top>=0 && n>=0))
        {
            return true;
        }
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        for(int i = 1; i<asteroids.size(); i++)
        {   
            int n = asteroids[i];
            bool popped = false;
            while(!st.empty() && !sameSign(st.top(),n) && st.top()>0 )
            {
                int top = st.top();
                int n1 = n;
                if(abs(top)>abs(n1))
                {
                    popped = true;
                    break;
                }
                else if(abs(top)==abs(n1))
                {
                    st.pop();
                    popped = true;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(popped)
            {
                continue;
            }
            st.push(n);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
