class Solution {
public:
    
    int lower_bound(vector<int>a,int t){
        int l=0,r=a.size();
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            
            if(a[mid]>=t){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sols;
        
        for(auto v:nums){
            if(sols.empty()|| v>sols.back()){
                sols.push_back(v);
            }
            else{
                int i=lower_bound(sols,v);
                sols[i]=v;
            }
        }
        return sols.size();
    }
};