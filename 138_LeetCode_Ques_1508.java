
// Leet-Code : Q.No => 1508 => Range Sum of Sorted SubArray Sums => 4 August



// 1.******* Using C++ ******* 


class Solution {
    public:
        int rangeSum(vector<int>& nums, int n, int left, int right) 
        {
            // Vector to store the sums of all subarrays
            vector<int> result;
    
            // Calculate the sum of all possible subarrays
            for(int i = 0; i < n; i++)
            {
                int sum = 0;  // Initialize sum for the current starting point
                for(int j = i; j < n; j++)
                {
                    sum += nums[j];  // Add the current element to the sum
                    result.push_back(sum);  // Store the sum in the result vector
                }
            }
    
            // Sort the result vector containing all subarray sums
            sort(result.begin(), result.end());
    
            // Calculate the sum of the elements between indices left-1 and right-1
            int sum = 0;  // Initialize the final sum
            int Mod = 1000000007;  // Modulo value to handle large numbers and prevent overflow
            for(int i = left - 1; i < right; i++)
            {
                sum = (sum + result[i]) % Mod;  // Add the current element and take modulo to avoid overflow
            }
    
            return sum;  // Return the final computed sum
        }
    };





// 2.******* Using Java ******* 


class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) 
    {
        // List to store the sums of all subarrays
        List<Integer> result = new ArrayList<>();   

        // Calculate the sum of all possible subarrays
        for(int i = 0; i < n; i++)
        {
            int sum = 0;  // Initialize sum for the current starting point
            for(int j = i; j < n; j++)
            {
                sum += nums[j];  // Add the current element to the sum
                result.add(sum);  // Store the sum in the result list
            }
        } 

        // Sort the result list containing all subarray sums
        Collections.sort(result);

        // Calculate the sum of the elements between indices left-1 and right-1
        int sum = 0;  // Initialize the final sum
        int mod = 1000000007;  // Modulo value to handle large numbers and prevent overflow
        for(int i = left - 1; i < right; i++)
        {
            sum = (sum + result.get(i)) % mod;  // Add the current element and take modulo to avoid overflow
        }

        return sum;  // Return the final computed sum
    }
}
