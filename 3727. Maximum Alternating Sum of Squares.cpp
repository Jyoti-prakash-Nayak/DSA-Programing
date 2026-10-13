class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>arr;
        for(auto it:nums){
          arr.push_back(1ll*it*it);
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0;
        int j=n-1;

       long long sum1=0;
       long long sum2=0;
        while(i<j){
            sum1+=arr[j];
            sum2+=arr[i];
            i++;
            j--;
        }

        if(n%2!=0){
            sum1+=arr[j];
        }

        return sum1-sum2;
    }
};