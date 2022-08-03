// Discount problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   int x;
	   cin>>x;
	   cout<<100-x<<endl;

	}
	return 0;
}


//Mileage matter 


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	 int dist,pl,dl,tp,td=0;
	 cin>>dist>>pl>>dl>>tp>>td;
	 
	 if( (dist / tp) * pl < (dist / td) * dl ){cout<<"PETROL"<<endl;}
	else if((dist / tp) * pl == (dist / td) * dl){cout<<"ANY"<<endl;}
	 else{cout<<"DIESEL"<<endl;}
	 
	}
	return 0;
}
