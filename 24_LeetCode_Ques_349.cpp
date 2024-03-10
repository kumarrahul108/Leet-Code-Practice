// Leet-Code : Q.No => 33 => Search in Rotated Sorted ARray -> 9th March 2024 


    // mapping concept (Hashing) 


    // 1. Using C++

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {   
        set<int> s1;  // Create a set to store unique elements from nums1
        vector<int> ans;  // Create a vector to store the final intersection

        // Insert elements of nums1 into the set to remove duplicates
        for(int i=0;i<nums1.size();i++)
        {
            s1.insert(nums1[i]);
        }        

        // Iterate through elements of nums2
        for(int i=0;i<nums2.size();i++)
        {   
            // Find the current element of nums2 in the set s1
            auto val = s1.find(nums2[i]);

            // If the element is found in the set
            if(val != s1.end())
            {
                // Add the element to the final intersection vector
                ans.push_back(nums2[i]);
                 
                // Erase the found element from the set to avoid duplicates 
                auto it = s1.find(nums2[i]); 
                if (it != s1.end()) 
                {
                    s1.erase(it);  
                }
            }
        }

        return ans;  // Return the final intersection vector
    }



    // 2. Using Java  

    public int[] intersection(int[] nums1, int[] nums2) 
    {
        Set<Integer> set1 = new HashSet<>();
        List<Integer> ans = new ArrayList<>();

        for (int num : nums1) 
        {
            set1.add(num);
        }

        for (int num : nums2) 
        {
            if (set1.contains(num)) 
            {
                ans.add(num);
                set1.remove(num);
            }
        } 

        int arr[] = new int[ans.size()];

        for(int i=0;i<ans.size();i++)
        {
            arr[i] = ans.get(i);
        } 

        return arr;
    }
