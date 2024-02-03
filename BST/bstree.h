
// The following operations are typically performed on a binary search tree:
// • Search the binary search tree for a particular item.
// • Insert an item in the binary search tree.
// • Delete an item from the binary search tree.
// • Find the height of the binary search tree.
// • Find the number of nodes in the binary search tree.
// • Find the number of leaves in the binary search tree.
// • Traverse the binary search tree.
// • Copy the binary search tree.

struct Node
{
    int data;
    Node *leftLink;  // Stores address of the left child
    Node *rightLink; // Stores address of the right child
    Node()
    {
        leftLink = rightLink = NULL;
    }
};

class BinarySearchTree
{
private:
    Node *rootNode;
    void insertNode(Node *);
    void deleteNode(Node *);
    void postorder(Node *) const;
    void inorder(Node *) const;
    void preorder(Node *) const;
    void destroy(Node *);
    int nodeCount(Node *) const;
    int heightNode(Node *) const;
    int max(int x, int y) const;
    int countLeafNode(Node *) const;
    int countSubtree(Node *) const;
    Node *searchNode(Node *, const int searchItem) const;
    Node *getNodeHavingLargestItem(Node *temp) const;

public:
    BinarySearchTree() { rootNode = NULL; }
    ~BinarySearchTree() { destroy(rootNode); }
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight();
    int treeNodeCount();
    bool isEmpty() const;
    void destroyTree();
    int leavesCount() const;
    bool search(int searchKey) const;
    void insert(const int item);
    void remove(const int item);
};

int BinarySearchTree ::countSubtree(Node *curNode) const
{
    if ((curNode->leftLink == NULL) && (curNode->rightLink == NULL))
        return 0;
    else if (curNode->leftLink == NULL)
        return 1;
    else if (curNode->rightLink == NULL)
        return 1;
    else
        return 2;
}

Node *BinarySearchTree ::searchNode(Node *curNode, const int searchItem) const
{
    if (curNode == NULL)
        return NULL;
    else
    {
        if (curNode->data == searchItem)
            return curNode;
        else if (searchItem < curNode->data)
            return searchNode(curNode->leftLink, searchItem);
        else
            return searchNode(curNode->rightLink, searchItem);
    }
}
int BinarySearchTree ::leavesCount() const
{
    return countLeafNode(rootNode);
}

void BinarySearchTree ::inorderTraversal() const
{
    inorder(rootNode);
}

void BinarySearchTree ::preorderTraversal() const
{
    preorder(rootNode);
}

void BinarySearchTree ::postorderTraversal() const
{
    postorder(rootNode);
}

int BinarySearchTree ::treeHeight()
{
    return heightNode(rootNode);
}

int BinarySearchTree ::treeNodeCount()
{
    return nodeCount(rootNode);
}

bool BinarySearchTree ::isEmpty() const
{
    return (rootNode == NULL);
}

void BinarySearchTree ::destroyTree()
{
    destroy(rootNode);
    rootNode = NULL;
}

void BinarySearchTree::insertNode(Node *insNode)
{
}
void BinarySearchTree::deleteNode(Node *)
{
}

bool BinarySearchTree::search(const int searchKey) const
{
    Node *temp = rootNode;
    while (temp)
    {
        if (temp->data == searchKey)
            return true;
        else if (temp->data > searchKey)
            temp = temp->leftLink;
        else
            temp = temp->rightLink;
    }
    return false;
}

void BinarySearchTree::insert(const int item)
{
    Node *NewNode = new Node;
    NewNode->data = item;
    NewNode->leftLink = NULL;
    NewNode->rightLink = NULL;

    if (rootNode == NULL)
    {
        rootNode = NewNode;
        return;
    }
    Node *parentNode = rootNode;
    while (1)
    {
        if (NewNode->data < parentNode->data)
        {
            if (parentNode->leftLink == NULL)
            {
                parentNode->leftLink = NewNode;
                return;
            }
            else
            {
                parentNode = parentNode->leftLink;
            }
        }
        else if (NewNode->data > parentNode->data)
        {
            if (parentNode->rightLink == NULL)
            {
                parentNode->rightLink = NewNode;
                return;
            }
            else
                parentNode = parentNode->rightLink;
        }
        else
        {
            cout << "Duplicate data entry occurred!" << endl;
            return;
        }
    }
}

Node *BinarySearchTree::getNodeHavingLargestItem(Node *temp) const
{
    while (temp->rightLink != NULL)
    {
        temp = temp->rightLink;
    }
    return temp;
}

void BinarySearchTree::remove(const int delItem)
{
    if (rootNode == NULL)
    {
        cout << "The tree is empty!" << endl;
        return;
    }

    Node *parent = NULL;
    Node *curNode = rootNode;
    while (curNode && curNode->data != delItem)
    {
        parent = curNode;
        if (curNode->data > delItem)
            curNode = curNode->leftLink;
        else
            curNode = curNode->rightLink;
    }
    if (curNode)
    {
        if (parent == NULL)
        {
            if (curNode->leftLink != NULL)
            {
                // curNode has left subtree
                Node *nodeHavingLargestItem = getNodeHavingLargestItem(curNode->leftLink);
                nodeHavingLargestItem->rightLink = curNode->rightLink;
                rootNode = curNode->leftLink;
            }
            else
                rootNode = rootNode->rightLink;
        }
        else
        {
            if (parent->leftLink == curNode)
            {
                // CurNode if the left subtree of its parent
                if (curNode->leftLink == NULL && (curNode->rightLink == NULL))
                {
                    parent->leftLink = NULL;
                }
                else if (curNode->rightLink == NULL)
                {
                    parent->leftLink = curNode->leftLink;
                }
                else if (curNode->leftLink == NULL)
                {
                    parent->leftLink = curNode->rightLink;
                }

                else
                {
                    // curNode has 2 subtrees
                    parent->leftLink = curNode->leftLink;
                    Node *nodeHavingLargestItem = getNodeHavingLargestItem(curNode->leftLink);
                    nodeHavingLargestItem->rightLink = curNode->rightLink;
                }
            }
            else
            { // Parent->rightLink == curNode
                // and CurNode if the right subtree of its parent
                if (curNode->leftLink == NULL && (curNode->rightLink == NULL))
                {
                    // curNode is a leaf Node
                    parent->rightLink = NULL;
                }
                else if (curNode->rightLink == NULL)
                {
                    // CurNode has not a right subtree
                    parent->rightLink = curNode->leftLink;
                }
                else if (curNode->leftLink == NULL)
                {
                    // curNode has right subtree
                    parent->rightLink = curNode->rightLink;
                }
                else
                {
                    // curNode has 2 subtrees
                    parent->rightLink = curNode->leftLink;
                    Node *nodeHavingLargestItem = getNodeHavingLargestItem(curNode->leftLink);
                    nodeHavingLargestItem->rightLink = curNode->rightLink;
                }
            }
        }
        cout << curNode->data << " is deleted from the tree" << endl;
    }
    else
    {
        cout << "The tree does not contain " << delItem << endl;
    }
}

void BinarySearchTree::postorder(Node *curNode) const
{
    if (curNode)
    {
        postorder(curNode->leftLink);
        postorder(curNode->rightLink);
        cout << curNode->data << " ";
    }
}

void BinarySearchTree::inorder(Node *curNode) const
{
    if (curNode)
    {
        inorder(curNode->leftLink);
        cout << curNode->data << " ";
        inorder(curNode->rightLink);
    }
}

void BinarySearchTree::preorder(Node *curNode) const
{
    if (curNode)
    {
        cout << curNode->data << " ";
        preorder(curNode->leftLink);
        preorder(curNode->rightLink);
    }
}

void BinarySearchTree::destroy(Node *curNode)
{
    if (curNode)
    {
        destroy(curNode->leftLink);
        destroy(curNode->rightLink);
        delete curNode;
        curNode = NULL;
    }
}

int BinarySearchTree::nodeCount(Node *curNode) const
{
    if (curNode == NULL)
        return 0;
    else
        return 1 + nodeCount(curNode->leftLink) + nodeCount(curNode->rightLink);
}

int BinarySearchTree::heightNode(Node *curNode) const
{
    if (curNode == NULL)
        return 0;
    else
        return 1 + max(heightNode(curNode->leftLink), heightNode(curNode->rightLink));
}

int BinarySearchTree::max(int x, int y) const
{
    return x >= y ? x : y;
}

int BinarySearchTree::countLeafNode(Node *curNode) const
{
    if (curNode == NULL)
        return 0;
    else if ((curNode->leftLink == NULL) && (curNode->rightLink == NULL))
        return 1;
    else
        return (countLeafNode(curNode->leftLink) + countLeafNode(curNode->rightLink));
}