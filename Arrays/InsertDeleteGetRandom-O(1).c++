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


class RandomizedSet {
public:
    int n = nums.size();
    RandomizedSet() {

    }

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;
        mp[val] = n;
        nums.pb(val);
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) != mp.end())
            return false;
        int valIndx = mp[val];
        int tempVal = nums[n];
        swap(nums[valIndx], nums[n]);
        nums.ppb();
        // changing index of the swapped value
        mp[tempVal] = mp[val];
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % n];
    }

private:
    vector<int> nums;
    unordered_map<int, int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */