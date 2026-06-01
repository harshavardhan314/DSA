class StockSpanner {
public:
    stack<pair<int,int>>st; // element,idx
    StockSpanner() {
        
    }
    
    int next(int price) {
        int idx=st.empty()?0:st.top().second+1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int left=st.empty()?-1:st.top().second;
        st.push({price,idx});
        return idx-left;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */