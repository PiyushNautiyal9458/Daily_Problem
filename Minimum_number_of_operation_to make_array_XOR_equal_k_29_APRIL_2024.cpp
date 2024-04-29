class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorall=nums[0];
        for(int i=1;i<nums.size();i++){
           xorall^=nums[i];
        }
        int xorval=k^xorall;
        return __builtin_popcount(xorval);
    }
};