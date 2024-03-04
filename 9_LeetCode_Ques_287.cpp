
// Leet-Code : Q.No => 287 => Find the Duplicate No. -> 4th March 2024 


    // 1. Using C++


    // Sorting Approach 
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }   

        return -1;    
    }


    // Negative Marking Method
    int findDuplicate(vector<int>& nums) 
    {
        int ans = -1;

        //  traverse over array
        for(int i=0;i<nums.size();i++)
        {
           int index = abs(nums[i]);    // index = num[i] -> jis index ko  -ve mark karna hai 

           // already visited
           if(nums[index] < 0)
           {
               ans = index;   // this place has already -ve 
               break;
           }

           // visit mark 
           nums[index] = nums[index] * -1;    // elemnt ko -ve mark 
        }   

       return ans;
    }


    // Positioning Approach
    int findDuplicate(vector<int>& nums) 
    {
        while(nums[0] != nums[nums[0]])
        {
            swap(nums[0],nums[nums[0]]);
        }

        return nums[0];
    }




    // 2. Using Java 

    // Negative Index Approach 
    public int findDuplicate(int[] nums) 
    {
        for(int i=0;i<nums.length;i++)
        {
            int index = Math.abs(nums[i]);

            // already visited     
            if(nums[index] < 0)
            {
                return index;   // duplicate 
            }

            // marking for visited elelemnt 
            nums[index] = nums[index] * -1;
        }            

        return -1;
    }



    


