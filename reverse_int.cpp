class Solution {
public:
    int reverse(int x) {
        // 123456
        // 654321
        // long bawah = pow(-2,31);
        // long atas = pow(2,31)-1;
        long ans =0;
        while(x!=0){
            ans = ans*10 + x%10;
            

            x /=10;
        }
        return (ans<INT_MIN||ans>INT_MAX) ? 0 :ans;;
    }
};
