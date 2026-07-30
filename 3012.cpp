class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = nums[0];
        for(auto x : nums) mn = min(mn,x);
        int cnt = 0;
        for(auto x : nums){
            if (x == mn) cnt++;
        }
        bool found = false;
        for(auto x : nums){
            if(x % mn != 0){
                return 1;
            }
        }
        return (cnt+1)/2;
    }
};