class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> count(20001, 0);
        for (int num : nums) {
            count[num + 10000]++;
        }
        int totalSum = 0;
        bool take = true;
        for (int i = 0; i <= 20000; i++) {
            while (count[i] > 0) {
                if (take) {
                    totalSum += (i - 10000);
                }
                take = !take;
                count[i]--;
            }
        }
        return totalSum;
    }
};