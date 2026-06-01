class StockSpanner {
public:
    vector<int>arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int cnt=0;
        int n=arr.size()-1;
        for(int j=n;j>=0;j--){
            if(arr[j]<=price)cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */