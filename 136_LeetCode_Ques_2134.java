
// Leet-Code : Q.No => 2134 => Minimum Swaps to Group All 1's Together => 2 August




// 1.******* Using C++ ******* 


class Solution {
    public:
        int minSwaps(vector<int>& nums) 
        {
            // size of vector nums 
            int n = nums.size();
    
            // total no of 1s in the array
            int k = accumulate(nums.begin(),nums.end(),0);
    
            
            // edge cases 
            if(k == 0 || k == n) 
            {
                return 0;
            }  
    
            // calculate no of 1s in first window of size k 
            int curr = accumulate(nums.begin(),nums.begin() + k , 0);
    
            // initialise maximum count of 1s in any window of k size
            int maxi = curr;
    
            // sliding window 
            for(int i = k ; i < n + k ; i++) 
            {
                // add the next element in the window & substract the element that's sliding out 
                curr += nums[i % n] - nums[(i - k + n) % n];
    
                // update the maximum count 
                maxi = max(maxi,curr);
            }
    
            // The minimum number of swaps required is the difference between the total number of 1s and the maximum number of 1s in any window.
            return k-maxi;
    
    /*
            Expression Breakdown:
    nums[i % n]:
    
    i % n ensures that i wraps around the array.
    As i increases, i % n cycles through the indices 0 to n-1.
    nums[i % n] accesses the element at the current end of the window.
    nums[(i - k + n) % n]:
    
    i - k gives the index of the element that is sliding out of the window.
    Adding n ensures that the index does not become negative.
    (i - k + n) % n wraps this index around to stay within the bounds of the array.
    nums[(i - k + n) % n] accesses the element that is being removed from the window.  
    
    The difference k - mx gives the number of 0s in that optimal window (because k is the window size and mx is the number of 1s in that window).
    
    */
        }
    };





// 2.******* Using Java ******* 


class Solution {
    public int minSwaps(int[] nums) 
    {
        int k = 0;
        for(int a : nums)
        {
            k += a;
        } 

        int n = nums.length;
        int cnt = 0;

        for(int i=0;i<k;i++) 
        {
            cnt += nums[i];
        }

        int max = cnt;
        
        for(int i=k;i<n + k;i++) 
        {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            max = Math.max(max,cnt);
        }   

        return (k - max);
    }
}