#include<iostream>
using namespace std;
class Solution{
	public:
	int function(int n, int a, int b){
		int k = min(n,b);
		int sum = 0;
		for(int i=1;i<k+1;i++){
			int p = b-i+1;
			int count = 0;
			if(p>a){
				sum = sum + (b-i+1);
				count++;
			}else if(count==0 && p<a){
				sum = n*a;
				count++;
			}else{
				sum = sum + a;
				count++;
			}
		}
		return sum;
	}
};
int main(){
	int t;
	cin>>t;
	int n,a,b;
	while(t--){
		 cin>>n;
		 cin>>a;
		 cin>>b;
		Solution solution;
		int result = solution.function(n,a,b);
		cout<<result<<endl;
	}	
	return 0;
}
