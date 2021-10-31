#define MOD 10000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>

class Solution {
public:
    void makeCombitn(vector<vector<int>>& ans, vector<int>& temp, int n, int left, int k) {
        if(k==0) {
            ans.pb(temp);
            return;
        }
        
        for(int i = left;i<=n;i++) {
            temp.pb(i);
            makeCombitn(ans, temp, n, i+1, k-1);
            temp.ppb();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        makeCombitn(ans, temp, n, 1, k);
        return ans;
    }
};
