/*
    暴力解法
    每个数平方之后，排个序
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }
};

/*
    双指针法

    数组其实是有序的， 只不过负数平方之后可能成为最大数了。
    那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
    此时可以考虑双指针法了，i指向起始位置，j指向终止位置。
    定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。
    如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。
    如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //开辟新容器存储排序后的数组
        vector<int> result(nums.size(),0);
        int k = nums.size() - 1;
        for(int left = 0,right = nums.size() - 1;left <= right; ){
            if(nums[left] * nums[left] > nums[right] * nums[right]){// 注意这里要 left <= right ，因为最后要处理两个元素
                result[k--] = nums[left] * nums[left]; 
                left++;
            }else{
                result[k--] = nums[right] * nums[right]; 
                right--;
            }
        }
        return result;
    }
};