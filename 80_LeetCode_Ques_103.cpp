// Leet-Code : Q.No => 103 => Binary Tree Zigzag Level Order Traversal => 8th April 2024 


    // level order traversal + B.T    


    // 1.******* Using C++ *******

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    // Initialize a vector to store the result
    vector<vector<int>> ans;

    // Base case: If the root is NULL, return an empty result
    if(root == NULL)
    {
        return ans;
    }

    // Variable to track the direction of traversal (left to right or right to left)
    bool LtoRdir = true;

    // Initialize a queue to perform level-order traversal
    queue<TreeNode*> q;
    q.push(root);

    // Perform level-order traversal
    while(!q.empty())
    {
        // Get the width (number of nodes at the current level)
        int width = q.size();
        
        // Initialize a vector to store the values of nodes at the current level
        vector<int> oneLevel(width);

        // Traverse the current level
        for(int i = 0; i < width; i++)
        {
            // Get the front node from the queue
            TreeNode* front = q.front();
            q.pop();

            // Calculate the index based on the traversal direction
            int index = LtoRdir ? i : width - i - 1;

            // Store the value of the node at the calculated index
            oneLevel[index++] = front->val;

            // Enqueue the left child if it exists
            if(front->left != NULL)
            {
                q.push(front->left);
            }

            // Enqueue the right child if it exists
            if(front->right != NULL)
            {
                q.push(front->right);
            }
        }

        // Reverse the traversal direction for the next level
        LtoRdir = !LtoRdir;
        
        // Store the values of nodes at the current level in the result vector
        ans.push_back(oneLevel);
    }

    // Return the result vector
    return ans;
}





    // 2.******* Using Java *******

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) 
    {
        Queue<TreeNode> queue = new LinkedList<>();

        List<List<Integer>> ans = new ArrayList<>();

        if(root == null)
            return ans;

        boolean flag = true;
        queue.add(root);

        while (!queue.isEmpty()) 
        {
            int n = queue.size();
            List<Integer> temp = new ArrayList<>();

            for (int i = 0; i < n; i++) 
            {
                temp.add(queue.peek().val);

                if (queue.peek().left != null) 
                {
                    queue.add(queue.peek().left);
                }

                if (queue.peek().right != null) 
                {
                    queue.add(queue.peek().right);
                }

                queue.poll();
            }

            if(!flag)
            {
                Collections.reverse(temp);
            }
            
            ans.add(temp);
            flag = !flag;
        }
        return ans;            
    }