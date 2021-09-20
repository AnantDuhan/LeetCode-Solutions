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
    string tictactoe(vector<vector<int>>& moves) {
        const vector<vector<int>> pos {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
        const vector<vector<int>> win {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

        string res {"_________"};
        for (int i = 0; i < moves.size(); ++i)
            res[pos[moves[i][0]][moves[i][1]]] = i % 2 ? 'B' : 'A';

        for (const auto& i : win) {
            int A = 0, B = 0;
            for (auto j : i) {
                if (res[j] == 'A') {if (++A == 3) return "A";}
                else if (res[j] == 'B') {if (++B == 3) return "B";}
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};