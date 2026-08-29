// T.C=O(NlogN)
// S.C=O(N)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>valueInxPairs;
        int n=nums.size();

        for(int i=0;i<n;i++){
            valueInxPairs.push_back({nums[i],i});
        }

        sort(valueInxPairs.begin(),valueInxPairs.end());

        vector<vector<pair<int,int>>> groupedPairs;
        groupedPairs.push_back({valueInxPairs[0]});

        for(int i=1;i<n;i++){
            if(valueInxPairs[i].first - valueInxPairs[i-1].first <= limit){
                groupedPairs.back().push_back({valueInxPairs[i]});
            }else{
                groupedPairs.push_back({valueInxPairs[i]});
            }
        }

        for(auto group:groupedPairs){
            vector<int>ind;
            for(auto [value,index]:group){
                ind.push_back(index);
            }

            sort(ind.begin(),ind.end());

            for(int i=0;i<ind.size();i++){
                nums[ind[i]]=group[i].first;
            }
        }
        return nums;
    }
};