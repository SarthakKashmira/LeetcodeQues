class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m-1;
        int r=0;
        while(l>=0 && r<n)
        {
            if(nums1[l]>nums2[r])
            {
                swap(nums1[l],nums2[r]);
            }
            l--;r++;
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<n;i++)
        {nums1[m+i]=nums2[i];}

    }
};