class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());

        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=abs(nums[i]-mini);
        }
        return cnt;
    }
};