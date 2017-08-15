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





    BinaryNode<Comparable>* findMin( Node * t ) const{
        while( t->left != NULL && t != NULL ){
            t = t->left;
        }
        return t;
    }

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
        if (t == nullptr){
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

int main(){
    BinarySearchTree<char> myTree;
    BinarySearchTree<char> bst2;
    bst2.insert('d');
    bst2.insert('b');
    bst2.insert('a');
    bst2.insert('c');
    bst2.insert('e');




    myTree.insert('j');
    myTree.insert('d');
    myTree.insert('w');
    myTree.insert('z');
    myTree.insert('k');
    // myTree.insert('a');
    myTree.insert('e');
    cout << "normal print: " << endl;
    myTree.print();
    cout << endl;



    BinaryNode<char>* root = myTree.get_root();
    cout << "min: " << endl;
    cout << myTree.findMin(root)->element << endl;;
}