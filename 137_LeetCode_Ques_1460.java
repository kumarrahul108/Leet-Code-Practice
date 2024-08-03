
// Leet-Code : Q.No => 1460 => Make Two Arrays Equal by Reversing SubArrays => 3 August



// 1.******* Using C++ ******* 


// *** APproach 1 

class Solution {
    public:
        bool canBeEqual(vector<int>& target, vector<int>& arr) 
        {
            // Array to store the frequency of elements (assuming elements range between 0 and 1000)
            int count[1001] = {0};
    
            // Increment the frequency count for elements in target and decrement for elements in arr
            for (int i = 0; i < target.size(); i++)
            {
                count[target[i]]++;
                count[arr[i]]--;
            }
    
            // Check if all counts are zero
            for (int i = 0; i < 1001; i++)
            {
                if (count[i] != 0)
                {
                    return false;
                }
            }
    
            // If all counts are zero, arrays can be made equal
            return true;
        }
    };



// *** APproach 1

class Solution {
    public:
        bool canBeEqual(vector<int>& target, vector<int>& arr) 
        {
            // Declare two maps to store the frequency of elements in target and arr
            map<int, int> mp1;
            map<int, int> mp2;
    
            // Populate the frequency map for the target vector
            for (auto x : target)
            {
                mp1[x]++;
            }
    
            // Populate the frequency map for the arr vector
            for (auto x : arr) 
            {
                mp2[x]++;
            }
    
            // Initialize an iterator for the second map
            auto itr2 = mp2.begin();
    
            // Iterate through the first map
            for (auto itr1 : mp1) 
            {
                // Check if the current key and value in both maps are not equal
                if (itr1.first != itr2->first || itr1.second != itr2->second)
                {
                    // If there is a mismatch, return false
                    return false;
                }
    
                // Move to the next element in the second map
                itr2++;
            }
    
            // If all elements match, return true
            return true;
        }
    };




// 2.******* Using Java ******* 

class Solution {
    public boolean canBeEqual(int[] target, int[] arr) 
    {
        Map<Integer,Integer> targetMap = new HashMap<>();     
        Map<Integer,Integer> arrMap = new HashMap<>();

        for(int num : target)
        {
            targetMap.put(num, targetMap.getOrDefault(num,0) + 1);
        }   

        for(int num : arr)
        {
            arrMap.put(num, arrMap.getOrDefault(num,0) + 1);
        }
        
        if(targetMap.equals(arrMap))
        {
            return true;
        }

        return false;
    }
}