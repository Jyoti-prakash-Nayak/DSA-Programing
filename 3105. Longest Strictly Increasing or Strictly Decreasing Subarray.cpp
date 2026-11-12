class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();

        int maxInc=0;
        int i=0;
        int j=1;
        while(j<n){
            if(nums[j-1] < nums[j]){
               maxInc=max(maxInc,j-i+1);
            }else{
                i=j;
            }
            j++;
            cout<<maxInc<<endl;
        }
         maxInc=max(maxInc,j-i);
          cout<<maxInc<<endl;

        int maxDec=0;
        i=0;
        j=1;
        while(j<n){
            if(nums[j-1] > nums[j]){
               maxDec=max(maxDec,j-i+1);
            }else{
                i=j;
            }
            j++;
             cout<<maxDec<<endl;
        }
         maxDec=max(maxDec,j-i);
         cout<<maxDec<<endl;

        return max(maxInc,maxDec);
    }
};