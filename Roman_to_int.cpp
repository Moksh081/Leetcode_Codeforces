class Solution {
public:
    int romanToInt(string s) {
        
        int nStr = s.length();
        if(nStr == 1)
        {
            return Map(s[0]);
        }
        int prevNum = Map(s[nStr-1]);
        int result = prevNum;

        for(int i = nStr - 2; i >= 0; --i)
        {
            int num = Map(s[i]);
            if(num < prevNum)
            {
                result -= num;
            }
            else
            {
                result += num;
            }
            prevNum = num;
        }
        return result;
    }

    int Map(char c)
    {
        switch(c)
        {
            case 'I':
            return 1;
            case 'V':
            return 5;
            case 'X':
            return 10;
            case 'L':
            return 50;
            case 'C':
            return 100;
            case 'D':
            return 500;
            case 'M':
            return 1000;
            default: 
            return 0;
        }
    }
};
