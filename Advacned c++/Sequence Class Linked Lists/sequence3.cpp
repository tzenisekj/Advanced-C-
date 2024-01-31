#include "sequence3.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

namespace main_savitch_5 {
    // constructor 
    sequence::sequence() {
        head_ptr = NULL;
        tail_ptr = NULL; 
        cursor = NULL;
        precursor = NULL; 
        many_nodes = 0; 
    }

    // copy constructor
    sequence::sequence(const sequence& source) {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
        node* temp = source.head_ptr;
        cursor = head_ptr; 
        while (temp != NULL) {
            attach(temp->data());
            temp = temp->link();
        }
    }

    // deconstructor 
    sequence::~sequence() {
        while (head_ptr != NULL) {
            cursor = head_ptr; 
            while (cursor != NULL) {
                cursor = cursor->link();
            }
            delete cursor; 
            --many_nodes; 
        }
    }

    // MODIFICATION MEMBER FUNCTIONS
    void sequence::start() {
        if (head_ptr == NULL) {
            precursor = NULL; 
            cursor = NULL; 
        }
        else {
            precursor = NULL; 
            cursor = head_ptr; 
        }
    }

    void sequence::advance() {
        assert(is_item()); 
        if (cursor->link() == NULL) {
            precursor = cursor; 
            cursor = NULL; 
        }
        else {
            precursor = cursor; 
            cursor = cursor->link();
        }
    }

    void sequence::insert(const value_type& entry) {
        if (head_ptr == NULL) {
            node* new_Node = new node; 
            new_Node->set_data(entry); 
            new_Node->set_link(NULL); 
            head_ptr = new_Node; 
            tail_ptr = new_Node; 
            cursor = new_Node; 
            precursor = NULL; 
            ++many_nodes; 
        }
        else {
            if (cursor == NULL) {
                node* new_Node = new node; 
                new_Node->set_data(entry);
                new_Node->set_link(head_ptr->link()); 
                head_ptr = new_Node; 
                cursor = head_ptr; 
                while (cursor != NULL) {
                    cursor = cursor->link(); 
                }
                tail_ptr = cursor; 
                cursor = head_ptr; 
                precursor = NULL; 
                ++many_nodes; 
            }
            else {
                node* new_Node = new node; 
                new_Node->set_data(entry); 
                new_Node->set_link(cursor); 
                precursor->set_link(new_Node); 
                cursor = new_Node;
                ++many_nodes; 
            }
        }
    }

    void sequence::attach(const value_type& entry) {
        if (head_ptr == NULL) {
            node* new_Node = new node; 
            new_Node->set_data(entry); 
            new_Node->set_link(NULL); 
            head_ptr = new_Node; 
            tail_ptr = new_Node; 
            cursor = new_Node; 
            precursor = NULL; 
            ++many_nodes; 
        }
        else {
            if (cursor == NULL) {
                node* new_Node = new node;
                new_Node->set_data(entry);
                new_Node->set_link(NULL);
                tail_ptr->set_link(new_Node); 
                precursor = tail_ptr; 
                tail_ptr = new_Node;
                cursor = new_Node; 
                ++many_nodes;
            }
            else {
                node* new_Node = new node;
                new_Node->set_data(entry);
                precursor = cursor; 
                cursor = cursor->link(); 
                new_Node->set_link(cursor); 
                precursor->set_link(new_Node); 
                cursor = new_Node; 
                ++many_nodes; 
            }
        }
    }

    void sequence::operator =(const sequence& source) {
        while (head_ptr != NULL) {
            cursor = head_ptr;
            while (cursor != NULL) {
                cursor = cursor->link();
            }
            delete cursor;
            --many_nodes;
        }
        cursor = head_ptr; 
        node* temp = source.head_ptr; 
        while (temp != NULL) {
            attach(temp->data()); 
            temp = temp->link(); 
        }
    }

    void sequence::remove_current() {
        assert(is_item()); 
        precursor->set_link(cursor->link()); 
        delete cursor; 
        cursor = precursor->link(); 
        --many_nodes;
    }

    sequence::value_type sequence::current() const {
        assert(is_item()); 
        return cursor->data(); 
    }
}