class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(true){
            if(n==1)
                return true;
            if(s.find(n)!=s.end())
                return false;
            s.insert(n);
            n = Caculate(n);
        }
    }
    int Caculate(int n){
        int ret=0;
        while(n!=0){
            ret+=(n%10)*(n%10);
            n=n/10;
        }
        return ret;
    }
};