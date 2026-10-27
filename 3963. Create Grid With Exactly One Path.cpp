class Solution {
public:
    vector<string> createGrid(int m, int n) {
         vector<string>grid;
        string s;
        for(int j=0;j<n;j++){
            s+='.';
        }
        grid.push_back(s);
        for(int i=1;i<m;i++){
            string str;
            for(int j=0;j<n-1;j++){
                str+='#';
            }
            str+='.';
            grid.push_back(str);
        }
        return grid;
    }
};