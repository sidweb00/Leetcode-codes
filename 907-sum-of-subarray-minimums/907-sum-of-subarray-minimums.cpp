class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        st.push(0);
        int mod=1e9+7;
        int n=arr.size();
        
        int right[n];
        
        for(int i=0;i<n;i++){
            right[i]=i;
        }
        
        for(int i=1;i<n;i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                right[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        vector<int>dp(n,0);
        
        dp[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            if(right[i]==i){
                dp[i]=(n-i)*arr[i]%mod;
            }
            else{
                dp[i]=((right[i]-i)*arr[i]%mod+dp[right[i]]%mod)%mod;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};