class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int fastIndex = 1,slowIndex = 1;
        for(fastIndex = 1;fastIndex < n;fastIndex++){
            if(nums[fastIndex] != nums[fastIndex - 1]){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};