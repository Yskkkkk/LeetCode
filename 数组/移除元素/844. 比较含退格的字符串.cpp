class Solution {
    public:
    bool backspaceCompare(string s, string t) {
        int S = s.length() - 1, T = t.length() - 1;
        int skipS = 0,skipT = 0;
        while(S >=0 || T >= 0){
            while(S >= 0){
                if(s[S] == '#'){
                    skipS++;
                    S--;
                }else if(skipS > 0){
                    skipS--;
                    S--;
                }else{
                    break;
                }
            }
            while(T >= 0){
                if(t[T] == '#'){
                    skipT++;
                    T--;
                }else if(skipT > 0){
                    skipT--;
                    T--;
                }else{
                    break;
                }
            }
            if(S >= 0 && T >= 0){
                if(s[S] != t[T]){
                    return false;
                }
            }else if(S >= 0 || T >=0){
                return false;
            }
            S--,T--;
        }
        return true;
    }
};