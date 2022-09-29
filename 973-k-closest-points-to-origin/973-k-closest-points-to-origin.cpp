class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        
        for(auto point:points){
            int x=point[0];
            int y=point[1];
            int ds=x*x+y*y;
            if(pq.size()<k){
                pq.push({ds,point});
            }
            else if(pq.top().first>ds){
                pq.pop();
                pq.push({ds,point});
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto v=pq.top().second;
            ans.push_back(v);
            pq.pop();
        }
        
        return ans;
    }
};