// Leet-Code : Q.No => 102 => Binary Tree Level Order Traversal => 26th March 2024 


    //  BFS + Traversal  


    // 1.******* Using C++ *******

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        // Initialize a vector to store the resulting level order traversal
        vector<vector<int>> ans;

        // If the root is NULL, return the empty vector
        if(root == NULL)
        {
            return ans;
        }

        // Initialize a queue to perform level order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Perform level order traversal using a queue
        while(!q.empty())
        {
            // Get the current size of the queue (number of nodes at the current level)
            int size = q.size();

            // Initialize a vector to store the values of nodes at the current level
            vector<int> level;

            // Traverse all nodes at the current level
            for(int i=0;i<size;i++)
            {
                // Get the front node of the queue
                TreeNode* temp = q.front();

                // Remove the front node from the queue
                q.pop();

                // If the left child of the current node exists, push it into the queue
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }

                // If the right child of the current node exists, push it into the queue
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                } 

                // Add the value of the current node to the level vector
                level.push_back(temp->val);
            }

            // Add the level vector to the result vector (ans)
            ans.push_back(level);
        }

        return ans;  // Return the resulting level order traversal
    }





    // 2.******* Using Java *******

    public List<List<Integer>> levelOrder(TreeNode root) 
    {
        List<List<Integer>> ans = new ArrayList<>();  

        if(root == null)
        {
            return ans;
        }      

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while(!q.isEmpty())
        {
            int size = q.size();
            List<Integer> level = new ArrayList<>();

            for(int i=0;i<size;i++)
            {
                TreeNode curr = q.peek();
                q.remove();

                if(curr.left != null)
                {
                    q.add(curr.left);
                }

                if(curr.right != null)
                {
                    q.add(curr.right);
                }

                level.add(curr.val);
            }

            ans.add(level);
        }

        return ans;
    }