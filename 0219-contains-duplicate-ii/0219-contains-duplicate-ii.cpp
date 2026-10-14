class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeenIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            if (lastSeenIndex.count(currentNum)) {
                int previousIndex = lastSeenIndex[currentNum];
                if (i - previousIndex <= k) {
                    return true;
                }
            }
            lastSeenIndex[currentNum] = i;
        }
        return false;
    }
};