class Solution {
public:
    unordered_map<TreeNode*, int> h;

    int getHeight(TreeNode* n) {
        if(n == NULL) return 0;
        return h[n];
    }

    int getBalance(TreeNode* n) {
        if(n == NULL) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        h[y] = max(getHeight(y->left), getHeight(y->right)) + 1;
        h[x] = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        h[x] = max(getHeight(x->left), getHeight(x->right)) + 1;
        h[y] = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    TreeNode* insert(TreeNode* root, int key) {
        if(root == NULL) {
            TreeNode* n = new TreeNode(key);
            h[n] = 1;
            return n;
        }

        if(key < root->val)
            root->left = insert(root->left, key);
        else if(key > root->val)
            root->right = insert(root->right, key);
        else
            return root;

        h[root] = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if(balance > 1 && key < root->left->val)
            return rightRotate(root);

        if(balance < -1 && key > root->right->val)
            return leftRotate(root);

        if(balance > 1 && key > root->left->val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if(balance < -1 && key < root->right->val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void traverse(TreeNode* root, TreeNode*& avlRoot) {
        if(root == NULL) return;

        traverse(root->left, avlRoot);
        avlRoot = insert(avlRoot, root->val);
        traverse(root->right, avlRoot);
    }

    TreeNode* balanceBST(TreeNode* root) {
        h.clear();

        TreeNode* avlRoot = NULL;
        traverse(root, avlRoot);

        return avlRoot;
    }
};