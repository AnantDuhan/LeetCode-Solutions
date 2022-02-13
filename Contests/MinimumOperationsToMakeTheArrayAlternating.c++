class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cntEven = 0, cntOdd = 0;

        unordered_map<int, int> evenMap, oddMap;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                cntEven++;
                evenMap[nums[i]]++;;
            }
            else {
                cntOdd++;
                oddMap[nums[i]]++;
            }
        }

        int firstEvenCnt = 0, firstEven = 0;
        int secondEvenCnt = 0, secondEven = 0;

        for (auto it = evenMap.begin(); it != evenMap.end(); it++) {
            int num = it->first;
            int cnt = it->second;

            if (cnt >= firstEvenCnt) {
                secondEvenCnt = firstEvenCnt;
                secondEven = firstEven;
                firstEvenCnt = cnt;
                firstEven = num;
            } else if (cnt >= secondEvenCnt) {
                secondEvenCnt = cnt;
                secondEven = num;
            }
        }

        int firstOddCnt = 0, firstOdd = 0;
        int secondOddCnt = 0, secondOdd = 0;

        for (auto it = oddMap.begin(); it != oddMap.end(); it++) {
            int num = it->first;
            int cnt = it->second;

            if (cnt >= firstOddCnt) {
                secondOddCnt = firstOddCnt;
                secondOdd = firstOdd;
                firstOddCnt = cnt;
                firstOdd = num;
            } else if (cnt >= secondOddCnt) {
                secondOddCnt = cnt;
                secondOdd = num;
            }
        }

        int evenOp = 0, oddOp = 0;

        evenOp = cntEven - firstEvenCnt;
        if (firstEven != firstOdd)
            evenOp += (cntOdd - firstOddCnt);
        else
            evenOp += (cntOdd - secondOddCnt);


        oddOp = cntOdd - firstOddCnt;
        if (firstOdd != firstEven)
            oddOp += (cntEven - firstEvenCnt);
        else
            oddOp += (cntEven - secondEvenCnt);


        return min(evenOp, oddOp);


    }
};