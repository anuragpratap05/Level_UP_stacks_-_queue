# Level_UP_stacks_-_queue
class Solution {
    
    
    
public:
    
    
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
};
