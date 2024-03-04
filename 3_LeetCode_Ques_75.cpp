
  // Leet-Code : Q.No => 75 => Sort Colors -> 1st March 2024 


// 1. Using C++ 

    // inplace approach
    void sortColors(vector<int>& nums) 
    {
        int index = 0;   // iterate over loop
        int left = 0;   // left ptr  -> (0)
        int right = nums.size() - 1;  // right ptr  -> (2) 

        while(index <= right)
        {
            if(nums[index] == 0)
            {
                swap(nums[left],nums[index]);
                left++;
                index++;
            }
            else if(nums[index] == 2)
            {
                swap(nums[right],nums[index]);
                right--;
                // index++;  (cache here) -> right se kya aaya nahi pata hame (may be 0 aaya hoo)
            }
            else 
            {
                index++;
            }
        }
    }


    // counting approach 
    void sortColors(vector<int>& nums) 
    {
       int zeros = 0,ones = 0,twos = 0;

       for(int i=0;i<nums.size();i++)
       {
           if(nums[i] == 0)
           {
               zeros++;
           }
           else if(nums[i] == 1)
           {
               ones++;
           }
           else 
           {
               twos++;
           }
       }

       int i = 0;

       while(zeros--)
       {
           nums[i] = 0;
           i++;
       }

       while(ones--)
       {
           nums[i] = 1;
           i++;
       }

       while(twos--)
       {
           nums[i] = 2;
           i++;
       }
    }





    // 2. Using Java 

    public void swap(int nums[],int a,int b)    // to swap 2 no in array 
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public void sortColors(int[] nums) 
    {
        int index = 0;  // loop variable
        int left = 0;    // left pointer -> (0)
        int right = nums.length - 1;  // right pointer -> (2)

        while(index <= right)
        {
            if(nums[index] == 0)
            {
                swap(nums,left,index);
                left++;
                index++;
            }
            else if(nums[index] == 2)
            {
                swap(nums,right,index);
                right--;
                // index++; -> (cache) //No need to increment index here
            }
            else 
            {
                index++;
            }
        }   
    }