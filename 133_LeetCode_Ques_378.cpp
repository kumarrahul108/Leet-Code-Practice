// Leet-Code : Q.No => 378 => Kth Smallest Element in a Sorted Matrix => 7th May


    //  priority queue + 2d array 



    // 1.******* Using C++ ******* 


    // **** A. Using Max-Heap **** 

    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        // Get the number of rows and columns in the matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Create a max heap to store the k smallest elements
        priority_queue<int> maxHeap;

        // Traverse the matrix
        for(int row = 0; row < m; row++) 
        {
            for(int col = 0; col < n; col++) 
            {
                // Push the current element into the max heap
                maxHeap.push(matrix[row][col]);

                // If the size of the max heap exceeds k, pop the largest element
                if(maxHeap.size() > k) 
                {
                    maxHeap.pop();
                }
            }
        }

        // The top element of the max heap is the kth smallest element
        return maxHeap.top();    
    }






    // 2.******* Using Java *******     


    public int kthSmallest(int[][] matrix, int k) 
    {
        int m = matrix.length;        
        int n = matrix[0].length;   

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((o1, o2) -> Integer.compare(o2, o1)); 

        for (int r = 0; r < m; ++r) 
        {
            for (int c = 0; c < n; ++c) 
            {
                maxHeap.offer(matrix[r][c]);
                if (maxHeap.size() > k) 
                {
                    maxHeap.poll();
                }
            }
        }
        
        return maxHeap.poll();    
    }
