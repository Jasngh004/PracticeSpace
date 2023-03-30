#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define ll long long
 
 //starter 83 good question 
 //i/p:
 /*3
6
aaabbb
7
abbbbbc
4
abcd*/
/* o/p: ab abbc abcd*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	ll baari;
	cin>>baari;
	while(baari--){
	    int l;
	    cin>>l;
	    
	    string s;
	    cin>>s;
	    
	    int cnt =1;
	    string ans ="";
	   char last = s[0];
	    
	    for(int i=1;i<l;i++)
	    {
	        if( last == s[i]){cnt++;}
	        else{
	            if(cnt%2 == 0){ans += last; ans += last;}
	            else{ans += last;}
	            
	            cnt =1;
	            last = s[i];
	        }
	    }
	     if(cnt%2 == 0){ans += last; ans += last;}
	            else{ans += last;}
	            
	            
	            cout<<ans<<endl;
	    
	    
	    
	}
	
	return 0;
}
