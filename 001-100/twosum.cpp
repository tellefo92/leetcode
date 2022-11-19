class Solution {
public:
     std::vector<int> twoSum(vector<int>& nums, int target) {
         std::vector<int> solution = {0,0};
         std::map<int,int> nums2;
         int i, k = 0;
         for (auto& n : nums) {
             i = std::abs(target - n);
             if (nums2.find(i) != nums2.end()) {
                 solution[0] = k;
                 solution[1] = nums2[k];
                 break;
             } else {
                 nums2[i] = k;
             }
             k++;
         }
         return solution;
    }
};