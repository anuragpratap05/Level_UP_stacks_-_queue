class Solution {
public:
    
    
     
     vector<int> nsor(vector<int> arr)
    {
        stack<pair<int, int>> st;
        int n = arr.size();
        vector<int> ans(n, n);

        for (int i = 0; i < n; i++)
        {

            if (st.empty())
            {
                st.push(make_pair(i, arr[i]));
                continue;
            }

            while (st.size() != 0 and st.top().second > arr[i])
            {

                ans[st.top().first] = i;
                st.pop();

            }
            st.push( make_pair( i, arr[i]));


        }
        return ans;


    }
    
    
       vector<int> nsol(vector<int> arr)
    {

        stack<pair<int, int>> st;



        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {

            if (st.empty())
            {
                st.push(make_pair(i, arr[i]));
                continue;
            }

            while (st.size() != 0 and st.top().second > arr[i])
            {

                ans[st.top().first] = i;
                st.pop();

            }
            st.push( make_pair( i, arr[i]));


        }
	    return ans;


    }
    
    
    int largestRectangleArea(vector<int>& arr) {
        
   
        
    vector<int> a = nsol(arr);
	vector<int> b = nsor(arr);
	int area = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		int h = arr[i];
		int w = (b[i] - a[i]) - 1;
		area = max(h * w, area);

	}

        return area;   
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
    

    	int n=matrix.size();
        if(n==0)
        {
            return 0;
        }
    	int m=matrix[0].size();

    	vector<int> prefix(m,0);
    	int ans=INT_MIN;


    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			if(matrix[i][j]=='0' )
    			{
    				prefix[j]=0;
    			}
    			else
    			{
    				prefix[j]+=1;
    			}

    		}

    		int val= largestRectangleArea(prefix);

    		ans=max(ans,val);

    	}




        return ans;
        

        
        
        
    }
};
