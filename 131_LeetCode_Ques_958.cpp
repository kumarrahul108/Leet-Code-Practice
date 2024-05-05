// Leet-Code : Q.No => 958 => Check Completeness of a Binary Tree => 5th May


    //  level order traversal + heaps basic + binary tree  



    // 1.******* Using C++ ******* 


    // Function to perform level order traversal of the binary tree
    bool levelOrderTraversal(TreeNode* root)
    {
        // create a queueu
        queue<TreeNode*> q;

        // insert 1st node in queue 
        q.push(root);

        // Flag to indicate if a null node has been encountered
        bool nullFound = false;

        // Perform level order traversal
        while(!q.empty())
        {
            // front of queue
            TreeNode* front = q.front();
            q.pop();   // remove front 

            // Check if the current node is null
            if(front == NULL)
            {
                nullFound = true;
            }
            else 
            {
                // If a null node has been encountered earlier, return false
                if(nullFound)
                {
                    return false;
                }
                // Add the left and right child nodes to the queue for traversal
                q.push(front->left);
                q.push(front->right);
            }
        }  

         // If all nodes have been traversed without encountering any null node after a non-null node, return true    
        return true;  
    }

    bool isCompleteTree(TreeNode* root) 
    {
        return levelOrderTraversal(root);            
    }




    // 2.******* Using Java *******         


    public boolean levelOrderTraversal(TreeNode root)
    {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean nullFound = false;

        while(!q.isEmpty())
        {
            TreeNode front = q.poll();
            
            if(front == null)
            {
                nullFound = true;
            }
            else 
            {
                if(nullFound)
                {
                    return false;
                }

                q.add(front.left);
                q.add(front.right);
            }
        }

        return true;

    }

    public boolean isCompleteTree(TreeNode root) 
    {
        return levelOrderTraversal(root);
    }
