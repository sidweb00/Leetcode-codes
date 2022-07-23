class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<int>current=intervals[0];
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            if(intervals[i][0]<=current[1]){
                current[1]=max(current[1],intervals[i][1]);
            }
            else{
                ans.push_back(current);
                current=intervals[i];
            }
        }
        
        ans.push_back(current);
        return ans;
    }
};