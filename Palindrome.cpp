//Palindrome 
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
           return false;
        }else{
        long int sum=0;
        long int t = x;
        while(x != 0) {
            int n = x%10;
            sum = sum*10 + n;
             x = x/10;
        }
        if(sum==t){
            return true;
        }else{
            return false;
        }
        }
    }
};
