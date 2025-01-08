#include <iostream>
using namespace std;

// Structure to define a node in the Binary Search Tree (BST)
struct BinarySearchTree {
    int data;                        // Data stored in the node
    BinarySearchTree* left;          // Pointer to the left child
    BinarySearchTree* right;         // Pointer to the right child
};

// Function to create a new node with a given value
BinarySearchTree* CreateNode(int value) {
    BinarySearchTree* newNode = new BinarySearchTree(); // Allocate memory for the new node
    newNode->data = value;          // Set the data value
    newNode->left = nullptr;        // Initialize left child as null
    newNode->right = nullptr;       // Initialize right child as null
    return newNode;
}

// Function to insert a new node into the BST
void insertBST(BinarySearchTree*& RNP, BinarySearchTree* NNP) {
    int inserted = 0;               // Flag to check if the node is inserted
    BinarySearchTree* temp = RNP;   // Temporary pointer to traverse the tree

    if (RNP == nullptr) {           // If the tree is empty
        RNP = NNP;                  // Make the new node the root
    } else {
        while (inserted == 0) {     // Traverse the tree until the node is inserted
            if (temp->data > NNP->data) {  // Go to the left subtree if data is smaller
                if (temp->left == nullptr) {
                    temp->left = NNP;      // Insert as the left child
                    inserted = 1;          // Mark as inserted
                } else {
                    temp = temp->left;     // Move to the left child
                }
            } else if (temp->data < NNP->data) { // Go to the right subtree if data is larger
                if (temp->right == nullptr) {
                    temp->right = NNP;     // Insert as the right child
                    inserted = 1;          // Mark as inserted
                } else {
                    temp = temp->right;    // Move to the right child
                }
            }
        }
    }
}

// Function to find the minimum value node in a subtree
BinarySearchTree* findMin(BinarySearchTree* root) {
    while (root && root->left != nullptr) {
        root = root->left;          // Traverse to the leftmost node
    }
    return root;
}

// Replacing the `deleteBST` function with the recursive `deleteNode` function
BinarySearchTree* deleteNode(BinarySearchTree* root, int key) {
    if (root == nullptr) {
        return root;                // Base case: Tree is empty or key not found
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);   // Search in the left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key); // Search in the right subtree
    } else {
        // Node found
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;            // Delete the node
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            BinarySearchTree* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BinarySearchTree* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            BinarySearchTree* temp = findMin(root->right); // Find inorder successor
            root->data = temp->data;                      // Replace data with successor's data
            root->right = deleteNode(root->right, temp->data); // Delete the successor
        }
    }
    return root;
}

// Function to perform preorder traversal (Root -> Left -> Right)
void preorder(BinarySearchTree* rootptr) {
    if (rootptr != nullptr) {
        cout << rootptr->data << " ";    // Visit the root
        preorder(rootptr->left);         // Traverse the left subtree
        preorder(rootptr->right);        // Traverse the right subtree
    }
}

// Function to perform in-order traversal (Left -> Root -> Right)
void inOrderTraversal(BinarySearchTree* rootptr) {
    if (rootptr != nullptr) {
        inOrderTraversal(rootptr->left);   // Visit the left subtree
        cout << rootptr->data << " ";      // Print root data
        inOrderTraversal(rootptr->right);  // Visit the right subtree
    }
}

// Function to perform postorder traversal (Left -> Right -> Root)
void postorder(BinarySearchTree* rootptr) {
    if (rootptr != nullptr) {
        postorder(rootptr->left);         // Traverse the left subtree
        postorder(rootptr->right);        // Traverse the right subtree
        cout << rootptr->data << " ";     // Visit the root
    }
}

// Function to search for a key in the BST
BinarySearchTree* searchingInBT(BinarySearchTree* rootptr, int key) {
    while (rootptr != nullptr) {
        if (rootptr->data == key) {
            // Found the key
            return rootptr;
        } else if (rootptr->data > key) {
            rootptr = rootptr->left; // Move to the left subtree
        } else {
            rootptr = rootptr->right; // Move to the right subtree
        }
    }
    return nullptr; // Key not found
}

// Function to find the maximum value in the BST
int FindMax(BinarySearchTree* rootptr) {
    if (rootptr == nullptr) {
        return -1; // Tree is empty
    } else if (rootptr->right == nullptr) {
        return rootptr->data; // Rightmost node found
    } else {
        return FindMax(rootptr->right); // Recur to the right subtree
    }
}

// Function to find the minimum value in the BST
int FindMinValue(BinarySearchTree* rootptr) {
    if (rootptr == nullptr) {
        return -1; // Tree is empty
    } else if (rootptr->left == nullptr) {
        return rootptr->data; // Leftmost node found
    } else {
        return FindMinValue(rootptr->left); // Recur to the left subtree
    }
}

// Main function
int main() {
    // Create and insert nodes into the BST
    BinarySearchTree* rootptr = nullptr;
    int values[] = {10, 5, 15, 3, 7, 13, 17};
    for (int value : values) {
        BinarySearchTree* newNode = CreateNode(value);
        insertBST(rootptr, newNode);
    }

    // Display the BST in sorted order (before deletion)
    cout << "In-order Traversal Before Deletion: ";
    inOrderTraversal(rootptr);
    cout << endl;

    // Delete a node (e.g., 10)
    cout << "Deleting node 10..." << endl;
    rootptr = deleteNode(rootptr, 10);

    // Display the BST in sorted order (after deletion)
    cout << "In-order Traversal After Deletion: ";
    inOrderTraversal(rootptr);
    cout << endl;

    return 0;
}
