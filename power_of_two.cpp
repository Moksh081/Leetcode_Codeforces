class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }else if(n<0){
            return false;
        }
         int k = log2(n);
         if(pow(2,k)==n){
             return true;
         }else{
             return false;
         }
    }
};
