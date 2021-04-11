// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to calculate span
// price[]: price array in input
// n: size of array

class Solution{
    public:
    
  vector<int> ngor(int arr[], int n)
	{
		stack<int> st;
		vector<int> ans;
		ans.resize(n, -1);
		for (int i = n - 1; i >= 0; i--)
		{
			while (st.size() != 0 and arr[i] > arr[st.top()])
			{
				ans[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		return ans;
	}
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
     vector<int> ans = ngor(arr, n);

	

		vector<int> final;
		final.resize(n, 0);
		final[0] = 1;
		for (int i = 1; i < n; i++)
		{
			final[i] = i - ans[i];
		}
		return final;
     
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
