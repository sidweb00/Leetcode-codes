class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>count(3,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int curr=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<count[i];j++){
                nums[curr]=i;
                curr++;
            }
        }
    }
};