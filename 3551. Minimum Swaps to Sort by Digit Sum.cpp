class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>digitSum;
        for(auto it:nums){
            int val=it;
            int sum=0;
            while(val){
                sum+=val%10;
                val=val/10;
            }
            digitSum.push_back(sum);
        }

        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({digitSum[i],nums[i]});
        }

        sort(arr.begin(),arr.end());

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[arr[i].second]=i;
        }

        int cnt=0;
        for(int i=0;i<n;i++){
           while(i!=mp[nums[i]]){
             swap(nums[i],nums[mp[nums[i]]]);
             cnt++;
           }
        }
        return cnt;
    }
};