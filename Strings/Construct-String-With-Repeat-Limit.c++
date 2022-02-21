class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] = {0};
        // count
        for (auto it : s) {
            cnt[it - 'a']++;
        }
        priority_queue<pair<int, int>> pq;
        // put the character and the count
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0)
                pq.push({i, cnt[i]});
        }

        string ans = "";
        while (!pq.empty()) {
            // the largest guy you got with its freq
            int chr1 = pq.top().first;
            int frq1 = pq.top().second;
            pq.pop();

            // cout << chr1 << " " << frq1 << endl;

            if (ans.size() == 0 || ans.back() != (char)(chr1 + 'a')) {
                int times = min(frq1, repeatLimit);

                for (int j = 0; j < times; j++) {
                    ans += (char)(chr1 + 'a');
                }

                // reduce the frq as we have used to build the string
                frq1 -= times;
                // are you still left
                if (frq1) {
                    pq.push({chr1, frq1});
                }
            } else {
                if (pq.size() == 0)
                    break;
                int chr2 = pq.top().first;
                int frq2 = pq.top().second;
                pq.pop();

                // add one occurrence of the second largest as we can't put the first largest
                ans += (char)(chr2 + 'a');
                frq2--;

                if (frq2) {
                    pq.push({chr2, frq2});
                }
                pq.push({chr1, frq1});
            }
        }
        return ans;
    }
};