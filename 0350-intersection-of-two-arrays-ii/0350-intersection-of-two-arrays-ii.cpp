class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> counts;
        for ( int n : nums1) {
            counts[n]++;
        }
        vector<int> result;
        for (int n : nums2) {
            auto it = counts.find(n);
            if (it != counts.end() && it->second > 0) {
                result.push_back(n);
                it->second--;
            }
        }
        return result;
    }
};