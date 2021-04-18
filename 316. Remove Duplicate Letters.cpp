# Level_UP_stacks_-_queue

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        
        string st="";

    	vector<bool> vis(26,false);
    	vector<int> freq(26,0);

    	for(auto ch:s)
    	{
    		freq[ch-'a']++;
    	}

    	for(auto ch:s)
    	{
    		freq[ch-'a']--;

    		if(vis[ch-'a'])
    		{
    			continue;
    		}

    		while(st.length()!=0 and st.back()>ch and freq[st.back()-'a']>0)
    		{
    			char rch=st.back();
    			st.pop_back();
    			vis[rch-'a']=false;
    		}

    		st.push_back(ch);
    		vis[ch-'a']=true;
    	}

    	return st;

        
    }
};
