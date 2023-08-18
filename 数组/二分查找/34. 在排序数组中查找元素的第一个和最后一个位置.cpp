
/* 寻找target在数组里的左右边界，有如下三种情况：
 ● 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
 ● 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
 ● 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}
 这三种情况都考虑到，说明就想的很清楚了。
 1.先进行一次二分，查找target在数组中是否存在，存在返回ans，不存在(即情况一、二)则返回{-1,-1};
 2.查找左右边界
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        //1.找到target对应的数组下标
        int ans = -1;
        while(left <= right){
            int middle = left + ((right - left)/2);
            if(nums[middle] == target){
                ans = middle;
                break;
            }
            if(nums[middle] < target){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
        if(ans == -1){
            return {-1,-1};
        }
        
        //找左边界
        left = 0,right=ans;
        int rightBorder,leftBorder;
        while(left <= right){
            int middle = left + ((right - left)/2);
            if(nums[middle] == target){
                leftBorder = middle;
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }
        //找右边界
        left = ans,right = size - 1;
        while(left <= right){
            int middle = left + ((right - left)/2);
            if(nums[middle] == target){
                rightBorder = middle;
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return {leftBorder,rightBorder};
    }
};