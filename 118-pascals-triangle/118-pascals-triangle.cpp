class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        vector<int>prev;
        prev.push_back(1);
        ans.push_back(prev);
        
        for(int i=1;i<numRows;i++){ 
            vector<int>curr;
            int n=prev.size();
            curr.push_back(prev[0]);
            for(int i=1;i<n;i++){
                curr.push_back(prev[i-1]+prev[i]);
            }
            curr.push_back(prev[n-1]);
            ans.push_back(curr);
            prev=curr;
            curr.clear();
        }
        
        return ans;
    }
};