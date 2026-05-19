class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;

        while(low <= high){

            int i = (low + high) / 2;
            int j = (n + m + 1) / 2 - i;

            int Aleft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == n) ? INT_MAX : nums1[i];

            int Bleft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == m) ? INT_MAX : nums2[j];

            if(Aleft <= Bright && Bleft <= Aright){

                if((n + m) % 2 == 0){
                    return (max(Aleft, Bleft) +
                            min(Aright, Bright)) / 2.0;
                }

                return max(Aleft, Bleft);
            }

            else if(Aleft > Bright){
                high = i - 1;
            }

            else{
                low = i + 1;
            }
        }

        return 0;
    }
};
