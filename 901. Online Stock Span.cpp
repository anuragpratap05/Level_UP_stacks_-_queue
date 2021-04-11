class StockSpanner {
public:
    stack<vector<int>> st;
    int day=0;
    StockSpanner() {
        st.push({-1,-1});
        
    }
    
    int next(int price) {
        
        while(st.top()[0]!=-1 and st.top()[1]<=price)
        {
            st.pop();
        }
        int span=day-st.top()[0];
        st.push({day,price});
        day++;
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
