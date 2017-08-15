// Jake Goldstein HW 9 Question 1-2
//
//  Binary Search Tree Class
//
//  Modified code from Weiss
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Comparable>
struct BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
    
    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
    : element{ theElement }, left{ lt }, right{ rt }{ }
    
    BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
    : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
};


// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// bool contains( x )     --> Return true if x is present
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************


template <typename Comparable>
class BinarySearchTree
{
public:
    typedef BinaryNode<Comparable> Node;
    
    BinarySearchTree( ) : root{ nullptr }
    {
    }
    
    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }
    
    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }
    
    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );
        return *this;
    }
    
    
    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }
    
    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }
    
    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }
    
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
    
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }

    //Only for testing purposes
    BinaryNode<Comparable>* get_root() {
        return root;
    }

    //Implement these
    // void levelOrderTraversal() const;
    // double average_node_depth() const;
    // void rangedPrint(int low, int high) const;
    // void stringy();



    // MY METHODS**********

    // For myself: vv
    void print() const{
        print(root);
    }

    void print(BinaryNode<Comparable>* myRoot) const{
        if (myRoot == nullptr){
            return;
        }
        else{
            // cout << "element: " << myRoot->element << ", ";
            print(myRoot->left);
            cout << "element: " << myRoot->element << ", ";
            print(myRoot->right);    
        }
        
    }
    // For myself: ^^

    void rangedPrint(int low, int high) const{
        rangedPrint(low, high, root);
    }

    void rangedPrint(int low, int high, BinaryNode<Comparable>* myRoot) const{
        if (myRoot){
            return;
        }
        // If low is smaller than the element that is being checked, go left
        if (low < myRoot->element){
            rangedPrint(low, high, myRoot->left);
        }
        // If the element being checked is in the range, print it
        if (low <= myRoot->element && myRoot->element <= high){
            cout << myRoot->element << ", ";    
        }
        // If high is larger than the element that is being checked, go right
        if (myRoot->element < high){ 
            rangedPrint(low, high, myRoot->right);
        }
    }

    BinaryNode<Comparable>* findMin(BinaryNode<Comparable>* t) const{
        while(t->left){
            t = t->left;
        }
        return t;
    }

    void stringy(){
        auto small = findMin(root);
        // Call the function
        stringy(root);
        // Set the root to be the smallest node
        root = small;
    }

    void stringy(BinaryNode<Comparable>* myRoot){
        // If (myRoot == nullptr) return
        if (myRoot){
            // Recursive call on left subtree
            stringy(myRoot->left);
            auto temp = myRoot->left;
            // Find the largest Node in the left subtree
            auto largeLeftSubtree = temp;
            if (largeLeftSubtree){
                while(largeLeftSubtree->right){
                    largeLeftSubtree = temp->right;
                }
            }
            // If the Node exists, have its right pointer point to myRoot
            if (largeLeftSubtree){
                largeLeftSubtree->right = myRoot;
            }
            // Find the smallest Node in the right subtree
            auto smallRightSubtree = myRoot->right;
            if (smallRightSubtree){
                while(smallRightSubtree->left){
                    smallRightSubtree = smallRightSubtree->left;
                }
            }
            // Recursive call on right subtree
            stringy(myRoot->right);
            // Left Node is null, right Node is the smallest item bigger than myRoot
            myRoot->right = smallRightSubtree;
            myRoot->left = nullptr;
        }
    }

    double average_node_depth() const{
        // Declare variabels
        double size = 1.0;
        double depth = 0.0;
        double level = 0.0;
        // Find the total depth of the left subtree
        if (root->left){
            findDepth(root->left, size, level, depth);
        }
        // Find the total depth of the right subtree
        if (root->left && root->right){
            findDepth(root->right, size, level, depth);
        }
        double result = depth/size;
        return result;
    }

    void findDepth(BinaryNode<Comparable>* myRoot, double& size, double& depth, double& result) const{
        if (!myRoot){
            return;
        }
        else{
            // Add one to the total size of the tree and to depth
            ++size;
            ++depth;
            // Add depth to the total depth
            result += depth; 
            // Find the depth of the left and right subtrees
            findDepth(myRoot->left, size, depth, result);
            findDepth(myRoot->right, size, depth, result);
            // Pop out a level and reduce the depth
            --depth;
        }
    }

    void levelOrderTraversal() const{
        auto curr = root;
        queue<BinaryNode<Comparable>*> someNodes;
        // Push the first node to a queue
        someNodes.push(curr);
        // While the queue is not empty
        while(someNodes.size() != 0){
            // Pop the node at the front of the queue, and get it
            curr = someNodes.front();
            someNodes.pop();
            // Print that node
            cout << curr->element << ", ";
            // If the node has a left node, push it
            if (curr->left){
                someNodes.push(curr->left);
            }
            // If the node has a right node, push it
            if (curr->right){
                someNodes.push(curr->right);
            }
        }
    }
    
private:
    
    BinaryNode<Comparable> *root;
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, Node * & t )
    {
        if( t == nullptr )
            t = new Node{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, Node * & t )
    {
        if( t == nullptr )
            t = new Node{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else
            ;  // Duplicate; do nothing

    }
    
    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( Node * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
    
    
    /**
     * Internal method to clone subtree.
     */
    Node * clone( Node *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new Node{ t->element, clone( t->left ), clone( t->right ) };
    }
    
    //implement this
    bool contains(const Comparable& x, Node* t) const{
        bool result;
        // If were all out, return false
        if (!t){
            result = false;
        }
        else{
            // If this is the element, return true
            if (t->element == x){
                result = true;
            }
            // If X is smaller, go left
            else if (x < t->element){
                return contains(x, t->left);
            }
            // If X is larger, go right
            else if(t->element < x){
                return contains(x, t->right);
            }
        }
        return result;
    }
    
};

//For testing purposes
template<class tp>
vector<tp> toVec(stringstream& strm) {
    tp i;
    vector<tp> vec;
    while (strm >> i) {
        vec.push_back(i);
        if (strm.peek() == ' ' || strm.peek() == '\n' || strm.peek() == ',') {
            strm.ignore();
        }
    }
    return vec;
}

//For testing purposes
struct cout_redirect {
    cout_redirect(std::streambuf * new_buffer)
        : old(std::cout.rdbuf(new_buffer))
    { }

    ~cout_redirect() {
        std::cout.rdbuf(old);
    }

private:
    std::streambuf * old;
};

SCENARIO("Testing the BinarySearchTree class") {
    GIVEN("A Binary Search tree with values inserted") {
        BinarySearchTree<int> bst;
        bst.insert(31);
        bst.insert(12);
        bst.insert(53);
        bst.insert(4);
        bst.insert(25);
        bst.insert(46);
        bst.insert(67);
        WHEN("Method contains is used") {
            bool Con_31 = bst.contains(31);
            bool Con_25 = bst.contains(25);
            bool Con_1 = bst.contains(1);
            THEN("31 and 25 should be true, but 1 should be false") {
                REQUIRE(Con_31 == true);
                REQUIRE(Con_25 == true);
                REQUIRE(Con_1 == false);
            }
        }
        WHEN("Method rangedPrint is called") {
            stringstream buffer;
            cout_redirect redir(buffer.rdbuf());
            bst.rangedPrint(12, 53);
            vector<int> resVec = { 12,25,31,46,53 };
            vector<int> asVec = toVec<int>(buffer);
            THEN("It should print out all objects in the given range") {
                for (int x = 0; x < asVec.size(); ++x) {
                    REQUIRE(resVec[x] == asVec[x]);
                }
            }
        }
        WHEN("Method average_node_depth is called") {
            double depth = bst.average_node_depth();
            REQUIRE(depth <= 1.429);
            REQUIRE(depth >= 1.427);
        }
        WHEN("Method levelOrderTraversal is called") {
            stringstream buffer;
            cout_redirect redir(buffer.rdbuf());
            bst.levelOrderTraversal();
            vector<int> resVec = { 31, 12, 53, 4, 25, 46, 67 };
            vector<int> asVec = toVec<int>(buffer);
            THEN("It should print out items in every level before the next level") {
                for (int x = 0; x < asVec.size(); ++x) {
                    REQUIRE(resVec[x] == asVec[x]);
                }
            }
        }
    }
    GIVEN("A Binary Search Tree with values 'a' to 'f' inserted") {
        BinarySearchTree<char> bst2;
        bst2.insert('d');
        bst2.insert('b');
        bst2.insert('f');
        bst2.insert('a');
        bst2.insert('c');
        bst2.insert('e');
        WHEN("Method stringy is called") {
            bst2.stringy();
            THEN("All nodes should have nullptr in left member and tree height should be n-1") {
                int size = -1;
                BinaryNode<char>* root = bst2.get_root();
                vector<char> resVec = { 'a', 'b', 'c', 'd', 'e', 'f' };
                while (root != nullptr) {
                    REQUIRE(root->left == nullptr);
                    REQUIRE(resVec[size + 1] == root->element);
                    size += 1;
                    root = root->right;
                }
                REQUIRE(size == 5);
            }

        }
    }
}
