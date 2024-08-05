
// Leet-Code : Q.No => 2053 => Kth Distinct String in an Array  => 5 August



// 1.******* Using C++ *******


class Solution {
    public:
        string kthDistinct(vector<string>& arr, int k) 
        {
            // unordered_map to keep track of the distinctness of each string
            unordered_map<string, bool> mp;
            int count = 0;
    
            // First pass: determine if each string is distinct
            for(string item : arr) 
            {
                if(mp.find(item) != mp.end()) 
                {
                    // If the string is already in the map, it is not distinct
                    mp[item] = false;
                } 
                else 
                {
                    // If the string is not in the map, mark it as distinct
                    mp[item] = true;
                }
            }
    
            // Second pass: find the k-th distinct string
            for(string item : arr) 
            {
                if(mp[item] == true) 
                {
                    // Increment count if the string is distinct
                    count++;
                    if(count == k) 
                    {
                        // Return the string if count matches k
                        return item;
                    }
                }
            }
    
            // If no k-th distinct string is found, return an empty string
            return "";    
        }
    };




// 2.******* Using Java ******* 

class Solution {
    public String kthDistinct(String[] arr, int k) 
    {
        // HashMap to keep track of the distinctness of each string
        HashMap<String, Boolean> map = new HashMap<>();

        int count = 0;

        // First pass: determine if each string is distinct
        for (int i = 0; i < arr.length; i++) 
        {
            if (map.containsKey(arr[i])) 
            {
                // If the string is already in the map, it is not distinct
                map.put(arr[i], false);
            } 
            else 
            {
                // If the string is not in the map, mark it as distinct
                map.put(arr[i], true);
            }
        }

        // Second pass: find the k-th distinct string
        for (String item : arr) 
        {
            if (map.get(item) == true) 
            {
                // Increment count if the string is distinct
                count++;
                if (count == k) 
                {
                    // Return the string if count matches k
                    return item;
                }
            }
        }

        // If no k-th distinct string is found, return an empty string
        return "";
    }
}