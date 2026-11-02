class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int medianVal=0;
        if(n%2!=0){
            medianVal=nums[n/2];
        }else{
            medianVal=(nums[n/2]+nums[(n+1)/2])/2;
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=abs(medianVal-nums[i]);
        }
        return cnt;
    }
};