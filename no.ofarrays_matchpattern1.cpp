class Solution {
public:
    int countMatchingSubarrays(vector<int>& v, vector<int>& p) {
        int n=v.size();
        int m=p.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int f=0;
            if(i+m>=n)
                break;
            for(int j=i;j+1<=i+m;j++) {
                if(p[j-i]==-1 && v[j]>v[j+1])
                    continue;
                if(p[j-i]==0 && v[j]==v[j+1])
                    continue;
                if(p[j-i]==1 && v[j]<v[j+1])
                    continue;
                f=1;
                break;
            }
            if(f==0)
                ans++;
        }
        return ans;
    }
};
