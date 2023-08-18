class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2){
            return true;
        }
        long left = 2,right = num / 2;
        while(left <= right){
            long middle = left + (right - left)/2;
            long square = middle * middle;
            if(square == num){
                return true;
            }else if(square < num){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return false;
    }
};