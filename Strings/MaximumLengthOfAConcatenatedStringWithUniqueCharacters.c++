class Solution {
public:
    int maxLength(vector<string>& arr) {
        return dfs(arr,0,"");
    }
    
private:
    int dfs(vector<string>& arr, int pos, string res) {
        unordered_set<char> setRes(res.begin(), res.end());
        
        if(res.size() != setRes.size())
            return 0;
        
        int best = res.size();
        for(int i=pos;i<arr.size();i++) {
            best = max(best, dfs(arr,i+1,res+arr[i]));
        }
        return best;
    }
};