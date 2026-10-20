class Solution {
public:
    bool check(vector<int>&nums1,vector<int>&nums2){
        int L=nums1.size();
        for(int i=0;i<L-1;i++){
            if(nums1[i]>nums1[i+1]){
                vector<int>rotated;
                
                rotated.insert(rotated.end(),nums1.begin()+i+1,nums1.end());
                rotated.insert(rotated.end(),nums1.begin(),nums1.begin()+i+1);

                return rotated==nums2;
            }
        }
        return nums1==nums2;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();

        vector<int>fact;
        for(int x=1;x*x<=n;x++){
          if(n%x==0){
            fact.push_back(x);
            if(n/x!=x){
                fact.push_back(n/x);
            }
          }
        }

        vector<int>target=nums;
        sort(target.begin(),target.end());

        int ans=0;
        for(auto d:fact){
            bool allGood=true;
            for(int left=0; left<n; left+=d){
                int right=left+d-1;

                vector<int>sub1(nums.begin()+left,nums.begin()+right+1);
                vector<int>sub2(target.begin()+left,target.begin()+right+1);

                if(!check(sub1,sub2)){
                    allGood=false;
                    break;
                }
            }
            if(allGood){
               ans+=d;
            }
           
        }
        return ans;
    }
};