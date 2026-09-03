class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        
        int smallNum=*min_element(nums1.begin(),nums1.end());
        int cntOdd=0;
        int cntEven=0;
        for(auto it:nums1){
            if(it%2==0){
                cntEven++;
            }else{
                cntOdd++;
            }
        }

        if(smallNum%2==0 && cntOdd>0){
            return false;
        }

        return true;
    }
};