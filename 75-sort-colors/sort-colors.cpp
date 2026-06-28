class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt1 = 0, cnt2= 0, cnt3 = 0;
        for(int x : nums){
            if(x == 0)  cnt1 ++;
            else if(x == 1) cnt2 ++;
            else
                cnt3++;
        }
        int k = 0;
        while(cnt1--){
            nums[k++] = 0;
        }
        while(cnt2--){
            nums[k++] = 1;
        }
        while(cnt3--){
            nums[k++] = 2;
        }
    }
};