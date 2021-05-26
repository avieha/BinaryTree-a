#pragma once
using namespace std;

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        // inner class
        class Node
        {
        public:
            T val;
            Node *left_son;
            Node *right_son;
            Node *father;
            Node(const T &v, Node *l, Node *r, Node *f = nullptr) : val(v), left_son(l), right_son(r), father(f){};
        };

    Node *root;

    public:
        BinaryTree() : root(nullptr){};
        BinaryTree<T> &add_root(T r) { return *this; };
        BinaryTree<T> &add_left(T father, T child) { return *this; };
        BinaryTree<T> &add_right(T father, T child) { return *this; };


        // inner class - pre_order_iterator
        class pre_order_iterator
        {
        private:
            Node *pointer_to_current_node;

        public:
            pre_order_iterator(Node *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            // Note that the method is const as this operator does not
            // allow changing of the iterator.
            // Note that it returns T& as it allows to change what it points to.
            // A const_iterator class will return const T&
            // and the method will still be const
            T &operator*() const
            {
                //return *pointer_to_current_node;
                return pointer_to_current_node->val;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->val);
            }

            // ++i;
            pre_order_iterator &operator++()
            {
                //++pointer_to_current_node;
                pointer_to_current_node = pointer_to_current_node->left_son;
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            const pre_order_iterator operator++(int)
            {
                pre_order_iterator tmp = *this;
                pointer_to_current_node = pointer_to_current_node->left_son;
                return tmp;
            }

            bool operator==(const pre_order_iterator &rhs) const
            {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const pre_order_iterator &rhs) const
            {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        }; // END OF CLASS ITERATOR



        // inner class - in_order_iterator
        class in_order_iterator
        {
        private:
            Node *pointer_to_current_node;

        public:
            in_order_iterator(Node *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            // Note that the method is const as this operator does not
            // allow changing of the iterator.
            // Note that it returns T& as it allows to change what it points to.
            // A const_iterator class will return const T&
            // and the method will still be const
            T &operator*() const
            {
                //return *pointer_to_current_node;
                return pointer_to_current_node->val;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->val);
            }

            // ++i;
            in_order_iterator &operator++()
            {
                //++pointer_to_current_node;
                pointer_to_current_node = pointer_to_current_node->left_son;
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            const in_order_iterator operator++(int)
            {
                in_order_iterator tmp = *this;
                pointer_to_current_node = pointer_to_current_node->left_son;
                return tmp;
            }

            bool operator==(const in_order_iterator &rhs) const
            {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const in_order_iterator &rhs) const
            {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        }; // END OF CLASS ITERATOR



        // inner class - post_order_iterator
        class post_order_iterator
        {
        private:
            Node *pointer_to_current_node;

        public:
            post_order_iterator(Node *ptr = nullptr)
                : pointer_to_current_node(ptr)
            {
            }

            // Note that the method is const as this operator does not
            // allow changing of the iterator.
            // Note that it returns T& as it allows to change what it points to.
            // A const_iterator class will return const T&
            // and the method will still be const
            T &operator*() const
            {
                //return *pointer_to_current_node;
                return pointer_to_current_node->val;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->val);
            }

            // ++i;
            post_order_iterator &operator++()
            {
                //++pointer_to_current_node;
                pointer_to_current_node = pointer_to_current_node->left_son;
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            const post_order_iterator operator++(int)
            {
                post_order_iterator tmp = *this;
                pointer_to_current_node = pointer_to_current_node->left_son;
                return tmp;
            }

            bool operator==(const post_order_iterator &rhs) const
            {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const post_order_iterator &rhs) const
            {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        }; // END OF CLASS ITERATOR

        pre_order_iterator begin(){return pre_order_iterator();};
        pre_order_iterator end(){return pre_order_iterator();};
        pre_order_iterator begin_preorder(){return pre_order_iterator();};
        pre_order_iterator end_preorder(){return pre_order_iterator();};
        in_order_iterator begin_inorder(){return in_order_iterator();};
        in_order_iterator end_inorder(){return in_order_iterator();};
        post_order_iterator begin_postorder(){return post_order_iterator();};
        post_order_iterator end_postorder(){return post_order_iterator();};
        friend ostream &operator<<(ostream &os, const BinaryTree<T> &b) { return os; };
    };
}