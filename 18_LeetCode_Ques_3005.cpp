// Leet-Code : Q.No => 3005 => Count Elements With Maximum Frequency -> 8th March 2024 

    // Mapping 

    // 1. Using C++

    int maxFrequencyElements(vector<int>& nums)     
    {
        // using ordered map data structure
        map<int,int> mp;  // {element , freq}

        int maxFreq = 0;  // to store max frequency

        // storing frequency in Map w.r.t element (traverse array)
        for(int num : nums)
        {
            mp[num]++;
            maxFreq = max(maxFreq , mp[num]);  // storing max frequency 
        } 

        int maxFreqElement = 0;  // to store no of element having max frequency

        // traverse over map 
        for(auto e : mp)
        {
            int currEleFreq = e.second;  // storeing freq of current element
            
            if(currEleFreq == maxFreq)
            {
                maxFreqElement++;
            }
        }

        return maxFreq * maxFreqElement;
    }


    // 2. Using Java 

    public int maxFrequencyElements(int[] nums) 
    {
        Map<Integer, Integer> freqMap = new HashMap<>(); // {element , freq}
        int maxFreq = 0;

        // Storing frequency in Map
        for (int num : nums) 
        {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
            maxFreq = Math.max(maxFreq, freqMap.get(num));
        }

        int maxFreqElement = 0;

        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) 
        {
            int currEleFreq = entry.getValue();

            if (currEleFreq == maxFreq) 
            {
                maxFreqElement++;
            }
        }

        return maxFreq * maxFreqElement;
    }


