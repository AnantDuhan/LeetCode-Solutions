class Solution {
public:
    vector<int> v = {1};
    
    int numTrees(int n) {
        if(v.size() >= n+1)
            return v[n];
        
        int total = 0;
        for(int i=1; i<=n; i++)
            total += numTrees(i-1) * numTrees(n-i);

        v.push_back(total);
        return total;
    }
};