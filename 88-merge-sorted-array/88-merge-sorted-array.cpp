class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int first=m-1;
        int second=n-1;
        
        for(int i=m+n-1;i>=0;i--){
            if(second>=0 && (first<0 || nums2[second]>nums1[first])){
                nums1[i]=nums2[second];
                second--;
            }
            else{
                nums1[i]=nums1[first];
                first--;
            }
        }
    }
};