#ifndef BASE_STRUCTURES_HPP
# define BASE_STRUCTURES_HPP

namespace ft {

    template<class T>
    struct bstree {
        T content;
        bstree* parent;
        bstree* left;
        bstree* right;
    };


    template<class T>
    bstree<T>* _min_value(bstree<T>* node) {
        bstree<T>* current = node;
        while(current->left)
            current = current->left;
        return current;
    }
    template<class T>
    bstree<T>* _max_value(bstree<T>* node) {
        bstree<T>* current = node;
        while(current->right)
            current = current->right;
        return current;
    }
    template<class T>
    bstree<T>* _find_next(bstree<T>* node) {
        if (node->right)
            return _min_value(node->right);
        bstree<T>* parent = node->parent;
        while (parent && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
    template<class T>
    bstree<T>* _find_prev(bstree<T>* node) {
        if (node->left)
            return _max_value(node->left);
        bstree<T>* parent = node->parent;
        while(parent && node == parent->left) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

#endif
