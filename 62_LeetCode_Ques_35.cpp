// Leet-Code : Q.No => 35 => Search Insert Position => 29th March 2024 


    //  using linear search  + binary serach + stack  


    // 1.******* Using C++ *******


    // ***** Using Linear Serach ******* 

    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();

        // Linear search to find the index where target should be inserted
        for(int i=0;i<n;i++)
        {
            if(nums[i] >= target)
            {
                return i;   // Found the index where target should be inserted
            }
        }  

        return n;   // If target is greater than all elements in the array, insert it at the end
    }




    // ****** Using Binary Serach ******** 


    int searchInsert(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end)
        {
            int mid = (start + end)/2;

            if(nums[mid] == target)
            {
                return mid;  // Found the target
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;   // Search in the right half
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;   // Search in the left half
            }   
        } 

        // If target is not found, return the index where it should be inserted
        return start;   
    }




    // ****** Using Stacks ******** 

    int searchInsert(vector<int>& nums, int target) 
    {
        stack<int> st;
        int i;

        for(i=0;i<nums.size();i++)
        {
            if(nums[i] >= target)
            {
                break;
            }

            st.push(nums[i]);
        }    

        while(!st.empty())
        {
            st.pop();    
        }   

        return i;
    }





    // 2.******* Using Java *******


    public int searchInsert(int[] nums, int target) 
    {
        int start = 0;
        int end = nums.length - 1;

        while(start <= end)
        {
            int mid = (start + end)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
        }  

        return start;  
    }


