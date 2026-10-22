class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int x=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                x=i;
                break;
            }
        }

        bool desc=true;
        bool asc=true;

        for(int i=0;i<n;i++){
            int next=(i+1)%n;
            if(nums[next] != (nums[i]+1)%n){
                asc=false;
            }
            if(nums[next] != (nums[i]-1+n)%n){
                desc=false;
            }
        }

        if(!asc && !desc){
            return -1;
        }

        int ans=INT_MAX;
        if(asc){
            ans=min(ans,x);
            ans=min(ans,n-x+2);
        }

        if(desc){
            ans=min(ans,n-x);
            ans=min(ans,x+2);
        }
        return ans;
    }
};