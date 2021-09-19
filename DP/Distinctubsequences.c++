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
#define ll long long int

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size(), i, j;
        vector<vector<unsigned long long int>> dp(n + 1, vector<unsigned long long int>(m + 1, 0));

        dp[0][0] = 1;
        for (i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];


                if (s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};