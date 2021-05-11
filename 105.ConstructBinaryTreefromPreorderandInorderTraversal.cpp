'''
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
'''

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        TreeNode * ptr = helper(preorder, inorder, rootIdx, 0, inorder.size() - 1);
        return ptr;
    }
    
    TreeNode *helper(vector<int> & preorder, vector<int> &inorder, int &rootIdx, int front, int rear){
        
        if (front > rear) return NULL;
        TreeNode *root = new TreeNode(preorder[rootIdx]);
        int pivot = front;
        
        while (inorder[pivot] != preorder[rootIdx]) pivot++;
        rootIdx++;
        root->left = helper(preorder, inorder, rootIdx, front, pivot - 1);
        root->right = helper(preorder, inorder, rootIdx, pivot + 1, rear);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int IdxPre = 1, IdxIn = 0, n = preorder.size();
        std:stack<TreeNode *> Nodes;
        TreeNode * root = new TreeNode(preorder[0]);
        TreeNode * prev = root;
        Nodes.push(root);
        int RightFlag = 0;
        
        while (IdxPre < n && IdxIn < n){
            
            if (!Nodes.empty() && Nodes.top() -> val == inorder[IdxIn]){
                prev = Nodes.top();
                Nodes.pop();
                IdxIn++;
                RightFlag = 1;
            }
            else{
                TreeNode *NewNode = new TreeNode(preorder[IdxPre]);
                if (RightFlag) {
                    prev -> right = NewNode;
                    prev = prev -> right;
                }
                else {
                    prev -> left = NewNode;
                    prev = prev ->left;
                }
                Nodes.push(NewNode);
                IdxPre++;
                RightFlag = 0;
                
            }
        }
        return root;
    }
};

'''
this is a tree - construct tree probem
one solution is to construct recursively
there are two key observations:
    1. each preorder[i] is a root
    2. elems to the left of inorder[j] form the left subtree of preorder[i] if preorder[i] == inorder[j]
       elems to the right of inorder[j] form the right subtree of preorder[i] if preorder[i] == inorder[j]

another solution is to construct iteratively
the key is to use stack to store nodes we have visited so that we can go back to the root after we have constructed the left subtree
Note that we use stack to undo, or more precisely to go backwards here
'''