#include <bits/stdc++.h>
using namespace std;

void asquare()
{
    int n;
    cin>>n;
    string s="";
    
    //convert to binary
    while(n>0){
        char ch='0'+(n%2);
        s+=ch;
        n/=2;
    }
    
    int curr=0;
    int ans=0;
    int total=s.size();
    int i;
    
    //till first 1 from end
    for(i=0;i<total;i++){
        if(s[i]=='1')break;
    }
    while(i<total){
        if(s[i]=='0'){
            s[i]='1';
            ans+=curr;
            curr=pow(2,i);
        }
        else{
            if(curr==0){
                curr=pow(2,i);
            }
            i++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        asquare();
    }
    return 0;
}

