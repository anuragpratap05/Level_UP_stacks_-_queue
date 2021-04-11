class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
		vector<int> ans;
		ans.resize(n, -1);


		stack<pair<int, int>> st;


		for (int i = 0; i < 2 * n; i++)
		{
			while (st.size() != 0 and nums[i % n] > st.top().first )
			{
				ans[st.top().second] = nums[i % n];
				st.pop();
			}
			if (i < n)
				st.push(make_pair(nums[i % n], i));
		}

		return ans;
        
        
        
    }
};
