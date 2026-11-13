class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        long long ans=0;
        long long cost=0;

        deque<pair<int,int>>dq;
        int j=n-1;
        
        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            int count=1;

            while(!dq.empty() && dq.back().first < num){
                int nextNum=dq.back().first;
                int nextCount=dq.back().second;
                dq.pop_back();

                count+=nextCount;

                cost+=1LL*(num-nextNum)*nextCount;
            }

            dq.push_back({num,count});

             // Shrink window if cost exceeds k
            while (cost > k) {

                int rightmostNum = dq.front().first;
                int rightmostCount = dq.front().second;

                dq.pop_front();

                // Remove the rightmost element's contribution
                cost -= (rightmostNum - nums[j]);

                j--;

                // Restore remaining elements of the group
                if (rightmostCount > 1) {
                    dq.push_front({rightmostNum, rightmostCount - 1});
                }
            }

            // Count valid subarrays starting at i
            ans += (j - i + 1);
        }
        return ans;
    }
};