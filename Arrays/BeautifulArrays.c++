class Solution {
public:
    vector<int> beautifulArray(int n) {        
        if(_memo.count(n)) return _memo[n];
        vector<int> ans(n);
        if(n == 1) ans[0]=1;
        else{
            int t = 0;
            for(int x: beautifulArray((n+1)/2)) ans[t++] = 2* x - 1; // odds
            for(int x: beautifulArray(n/2)) ans[t++] = 2* x;  // evens
        }
        return _memo[n]=ans;        
    }
    
private:
    unordered_map<int, vector<int> > _memo;
};