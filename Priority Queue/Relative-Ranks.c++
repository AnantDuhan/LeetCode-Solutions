class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push(make_pair(score[i], i));
        }

        vector<string> res(n, "");

        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (cnt == 1) {
                res[pq.top().second] = "Gold Medal";
                cnt++;
            }
            else if (cnt == 2) {
                res[pq.top().second] = "Silver Medal";
                cnt++;
            } else if (cnt == 3) {
                res[pq.top().second] = "Bronze Medal";
                cnt++;
            } else {
                res[pq.top().second] = to_string(cnt);
                cnt++;
            }
            pq.pop();
        }
        return res;
    }
};