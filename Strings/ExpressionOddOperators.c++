typedef long long ll;

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
    vector<string> res;

    void solve(string num, int target, int start, string s, ll sum, ll last) {
        int n = num.size();

        if (n == start) {
            if (target == sum) {
                res.pb(s);
            }
            return;
        }

        ll x = 0;
        string r = "";

        for (int i = start; i < n; i++) {
            x = x * 10 + num[i] - '0';
            r += num[i];

            if (start == 0)
                solve(num, target, i + 1, s + r, x, x);
            else {
                solve(num, target, i + 1, s + "*" + r, sum - last + x * last, x * last);
                solve(num, target, i + 1, s + "+" + r, sum + x, x);
                solve(num, target, i + 1, s + "-" + r, sum - x, -x);
            }

            if (x == 0)
                break;
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, "", 0, 0);
        return res;
    }

};