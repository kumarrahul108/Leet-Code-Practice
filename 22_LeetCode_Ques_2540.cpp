// Leet-Code : Q.No => 2540 => Minimum Common Value -> 9th March 2024 


    // 2 pointer approach  


    // 1. Using C++

    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        // Get the sizes of both arrays
        int n = nums1.size();
        int m = nums2.size();

        // Initialize indices for both arrays
        int left = 0;
        int right = 0;

        // Iterate through both arrays
        while(left < n && right < m)
        {
            // If current elements in both arrays are equal, return the common element
            if(nums1[left] == nums2[right]) 
            {
                return nums1[left];
            }
            // If element in nums1 is greater than element in nums2, move to the next element in nums2
            else if(nums1[left] > nums2[right]) 
            {
                right++;
            }
            // If element in nums1 is less than element in nums2, move to the next element in nums1
            else 
            {
                left++;
            }
        }
         // If no common element is found, return -1
        return -1;
    }



    // 2. Using Java

    public int getCommon(int[] nums1, int[] nums2) 
    {
        int n1 = nums1.length;    
        int n2 = nums2.length;    

        int left = 0;
        int right = 0;

        while(left < n1  &&  right < n2)
        {
            if(nums1[left] == nums2[right])
            {
                return nums1[left];
            }
            else if(nums1[left] > nums2[right])
            {
                right++;
            }
            else  
            {
                left++;
            }
        }
        return -1;
    }

