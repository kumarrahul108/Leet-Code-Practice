
// Leet-Code : Q.No => 268 => Missing Number -> 3rd March 2024 


    // 1. Using C++
    
    // SUm Approach 
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();  // actual size of array

        int actualSum = n * (n+1) / 2;   // actual sum upto n
        int numsSum = 0;   // store sum of elememt in array

        for(int i=0;i<n;i++)
        {
            numsSum += nums[i];   // adding each elelemnt of array
        }    

        // difference in their sum = elelemnt missing
        int ans = actualSum - numsSum;

        return ans;
        // return (actualSum - numsSum); 
    }


    // Xor Approaxh 
    int missingNumber(vector<int>& nums) 
    {
       int ans = 0;

       // Xor all value of array
       for(int i=0;i<nums.size();i++)
       {
           ans = ans ^ nums[i];
       }

       // Xor with all range items [0,n]
       for(int i=0;i<=nums.size();i++)
       {
           ans = ans ^ i;
       }

       return ans;
    }





    // 2. Using Java 

    public int missingNumber(int[] nums) 
    {
        int n = nums.length;
        int sum = 0;
        int totalSum = n * (n+1) / 2; 

        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }

        return (totalSum - sum);
    }
