class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();

        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());

        vector<int>arr;
        for(int i=0;i<n;i++){
            if(nums[i]!=temp[i]){
                arr.push_back(nums[i]);
            }
        }

        if(arr.size()==0){
            return 0;
        }
        
        int val=arr[0];
        for(int i=1;i<arr.size();i++){
            val=val & arr[i];
        }
        return val;
    }
};