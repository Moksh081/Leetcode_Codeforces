class Solution {
public:
    int function(int x, int y){
        int c = 1;
        int ans = 0;
        while(x>=0 && y>=0){
            if(c%2==1){
                x -= c;
            }else{
                y -= c;
            }
        if(x<0 || y<0){
          break;
        }
            ans++;
            c++;
        }
        return ans;
    }
    int maxHeightOfTriangle(int red, int blue) {
       int r = function(red,blue);
        int b = function(blue,red);
        return max(r,b);
    }
};

