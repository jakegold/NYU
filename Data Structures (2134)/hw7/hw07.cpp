// Jake Goldstein HW 7 Question 1
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include <algorithm>
#include <string>

using namespace std;

template <typename Object>
class List
{
private:

    struct Node
    {
        Object  data;
        Node   *next;
        
        Node( const Object & d = Object{ },  Node * n = nullptr )
        : data{ d },  next{ n } { }
        
        Node( Object && d, Node * n = nullptr )
        : data{ std::move( d ) }, next{ n } { }
    };
    
public:
    class iterator
    {
    public:
        
        iterator( ): current( nullptr )
        { }
        
        Object & operator* ( )
        { return current->data; }
        
        const Object & operator* ( ) const
        { return  current->data; }
        
        iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }
        
        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }
        
        bool operator== ( const iterator & rhs ) const
        { return current == rhs.current; }
        
        bool operator!= ( const iterator & rhs ) const
        { return !( *this == rhs ); }
        
    private:
        Node * current;

        iterator( Node *p ) : current{ p }
        { }
        
        friend class List<Object>;
    };
    
public:
    List( )
    { header = new Node(); }
        
    // (a) The copy constructor, List( const List & rhs ). This method must take O(n) time.
    List( const List & rhs ):header{new Node}{
        auto rhsItr = rhs.begin();
        auto curr = header;
        while (rhsItr != nullptr){
            // Create a deep copy
            curr->next = new Node(*rhsItr);
            // Advance one element
            ++rhsItr;
            curr = curr->next;
        }
    }

    // (b) The destructor, ∼List( ). This method must take O(n) time.
    ~List( ){
    	auto curr = header->next;
        // While we are still in the list
    	while(curr != nullptr){
            // Hold the next element
            auto next = curr->next;
    		delete curr;
            // Move through the List
            curr = next;
    	}
    }

    List & operator= ( const List & rhs )
    {
        List copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    List( List && rhs ):header{ new Node }
    {
        header->next = rhs.header->next;
        rhs.header->next = nullptr;
    }
    
    List & operator= ( List && rhs )
    {
        std::swap( header, rhs.header );
        return *this;
    }
    
    iterator begin( ) const
    { return iterator( header->next ); }
    
    iterator end( ) const
    { return iterator( nullptr ); }
    
    iterator before_begin( ) const
    { return iterator( header ); }
    
    bool empty( ) const
    { return header->next == nullptr; }
    
    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }
    
    void push_front(Object data){
        header->data = data;
        Node* oldHeader = header;
        header = new Node;
        header->next = oldHeader;
    }

    void pop_front( )
    { erase_after( before_begin( ) ); }
    
    iterator insert_after( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        p->next = new Node{ x, p->next };
        
        return iterator(p->next);
    }

    iterator erase_after( iterator itr )
    {
        Node *p = itr.current;
        Node *oldNode = p->next;
        
        p->next = oldNode->next;
        delete oldNode;
        
        return iterator( p->next );
    }
    
    //     (c) The method front( ). It performs as stated in
    // www.cplusplus.com/reference/forward_list/forward_list/front/ This method must take O(1) time.
    Object & front( ){
        return header->next->data;
    }
    
    const Object & front( ) const{
        return header->next->data;
    }
    
    //     (d) The method merge( List & alist). It performs as stated in
    // www.cplusplus.com/reference/forward_list/forward_list/merge/
    void merge( List & alist ){
        // Create a temp to hold elements
        List<Object> temp;
        auto curr = temp.before_begin();
        // While both of them still have elements
        while(begin() != end() && alist.begin() != alist.end()){
            auto left = begin();
            auto right = alist.begin();
            // Put the smaller element in the temp
            // erase what was added, and adjust curr 
            if (*left < *right){
                insert_after(curr, *left);
                erase_after(header);
                curr++;
            }
            else{
                insert_after(curr, *right);
                erase_after(alist.header);
                curr++;
            }
        }
        // Once only one List has elements left, add all elements to the temp,
        // and then delete the added element and adjust curr
        while(begin() != end()){
            auto left = begin();
            insert_after(curr, *left);
            erase_after(header);
            curr++;
        }
        while(alist.begin() != alist.end()){
            auto right = alist.begin();
            insert_after(curr, *right);
            erase_after(alist.header);
            curr++;
        }
        // Swap the temp with the List function is acting on
        header->next = temp.header->next;
        temp.header->next = nullptr;
    }

    //     (e) The method remove adjacent duplicates( ). The method removes any element if it is adjacent to a node
    // containing the same item2
    // . Thus if the list contained a, a, a, b, b, c, c, c, c afterwards it would contain a, b, c. If
    // the list contains a, b, a, b, a then afterwards it contains a, b, a, b, a (i.e. no change, since no items adjacent to
    // each other were the same).
    void remove_adjacent_duplicates( ){
        auto trailer = before_begin();
        auto curr = begin();
        while(curr != end()){
            // If they are the same delete one
            if (*curr == *trailer){
                // Adjust curr
                curr++;
                erase_after(trailer);
            }
            else{
                // Advance one element
                curr++;
                trailer++;// = trailer->next;
            }
        }
    }
    
    //     (f) The method remove if( Predicate pred ) that performs as stated in
    // www.cplusplus.com/reference/forward_list/forward_list/remove_if/ This method must run in O(n)
    // time. Your method should call your method erase after.
    template<class Predicate>
    void remove_if( Predicate pred ){
        auto tester = begin();
        auto curr = header;
        while(tester != end()){
            // If tester is true for the pred
            if (pred(*tester)){
                // Erase that element
                erase_after(curr);
                // Adjust tester
                tester = curr->next;
            }
            else{
                // Advance one element
                ++tester;
                curr = curr->next;
            }
        }
    }
        
private:
    Node *header;
};

SCENARIO("Testing Copy Constructor"){
    GIVEN("An instance of the list class"){
        List<int> l;
        l.push_front(3);
        l.push_front(2);
        l.push_front(1);
        WHEN("The copy constructor is invoked"){
            List<int> l2(l); 
            THEN("A deep copy should have been made"){
                List<int>::iterator itr1 = l.begin();
                List<int>::iterator itr2 = l2.begin();
                while(itr2 != l2.end() && itr1 != l.end()){
                    REQUIRE(*itr2 == *itr1);
                    ++itr2;
                    ++itr1;
                }
                REQUIRE(itr1 == l.end());
                REQUIRE(itr2 == l2.end());
                l.clear();
                REQUIRE(l.empty());
                REQUIRE(!l2.empty());
            }
        }
    }
}

SCENARIO("Testing the method front()"){
    GIVEN("An instance of the list class with elements inserted"){
        List<int> l;
        l.push_front(3);
        l.push_front(2);
        l.push_front(1);
        WHEN("front() is called"){
            REQUIRE(l.front() == 1);
        }
    }
}

SCENARIO("Testing the method merge()"){
    GIVEN("Two Instances of the list class with elements in relative sorted order for each"){
        List<int> l1;
        l1.push_front(6);
        l1.push_front(4);
        l1.push_front(2);
        List<int> l2;
        l2.push_front(5);
        l2.push_front(3);
        l2.push_front(1);
        WHEN("Merge is called"){
            l1.merge(l2);
            THEN("The elements should be in sorted order"){
                List<int>::iterator lead = l1.begin();
                List<int>::iterator tail = lead;
                ++lead;
                for(; lead!= l1.end(); ++lead){
                    REQUIRE(*tail < *lead);
                } 
            }
            THEN("l2 should be empty"){
                REQUIRE(l2.empty());  
            }
        }
    }
}

SCENARIO("Testing remove_adjacent_duplicates()"){
    GIVEN("A list with a ton of adjacent duplicates"){
        List<char> l;
        for(int x = 0; x < 5; ++x){
            l.push_front('c');
        }
        for(int x = 0; x < 3; ++x){
            l.push_front('b'); 
        }
        for(int x = 0; x < 5; ++x){
            l.push_front('c');
        }
        for(int x = 0; x < 2; ++x){
            l.push_front('a'); 
        }
        WHEN("remove_adjacent_duplicates() is called"){
            l.remove_adjacent_duplicates();
            THEN("The resulting list should be a->c->b->c"){
                List<char>::iterator iter = l.begin();
                REQUIRE(*iter == 'a');
                ++iter;
                REQUIRE(*iter == 'c');
                ++iter;
                REQUIRE(*iter == 'b');
                ++iter;
                REQUIRE(*iter == 'c');
            }
        }
    }
}

// Ignore this pred used for testing
template<class Foo> 
class aPred{
    public:
        aPred(Foo bar):myFoo(bar){}
        bool operator()(Foo otherBar){
            return myFoo != otherBar;
        }
    private:
        Foo myFoo;
};

SCENARIO("testing remove_if"){
    GIVEN("A list with things to remove and a pred"){
        List<string> l;
        l.push_front("Scott");
        l.push_front("Maliat");
        l.push_front("Nico");
        l.push_front("Anam");
        l.push_front("Xinran");
        l.push_front("Lolaly");
        aPred<string> myPred("Nico");
        WHEN("remove_if is used"){
            l.remove_if(myPred);  
            THEN("Only Nico should be left."){
                REQUIRE(l.front() == "Nico");
            }
        }
    }
}
