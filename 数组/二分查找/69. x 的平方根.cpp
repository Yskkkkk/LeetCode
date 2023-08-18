class Solution {
public:
    int mySqrt(int x) {
        int left = 0,right = x,ans = -1;
        while(left <= right){
            int middle = left + (right - left)/2;
            if((long long)middle * middle <=x ){
                ans = middle;
                left = middle + 1;//需要找最接近的所以再往右边找，即更新左边界。
            }else{
                right = middle - 1;
            }
        }
        return ans;
    }   
};