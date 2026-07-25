//T.C=O(N logN)
//S.C=O(N)
class Solution {
public:
    int maxProduct(int n) {
        int val=n;
        vector<int>arr;
        while(val){
            int digit=val%10;
            arr.push_back(digit);
            val=val/10;
        }
        sort(arr.begin(),arr.end());
        int k=arr.size();
        return arr[k-1]*arr[k-2];
    }
};