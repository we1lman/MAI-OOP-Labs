#ifndef DOUBLYLINKEDLIST_TPP
#define DOUBLYLINKEDLIST_TPP

#include "DoublyLinkedList.hpp"

template <typename T>
class DoublyLinkedList<T>::Iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator(Node* node = nullptr) : node_(node) {}

    reference operator*() const { return node_->data; }
    pointer operator->() const { return &(node_->data); }

    Iterator& operator++() {
        node_ = node_->next;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        node_ = node_->next;
        return temp;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
        return a.node_ == b.node_;
    }

    friend bool operator!=(const Iterator& a, const Iterator& b) {
        return a.node_ != b.node_;
    }

private:
    Node* node_;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::pmr::memory_resource* mr)
    : head_(nullptr), tail_(nullptr), allocator_(mr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = head_;
    while (current) {
        Node* next = current->next;
        allocator_.destroy(current);
        allocator_.deallocate(current, 1);
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = allocator_.allocate(1);
    allocator_.construct(new_node, Node{value, tail_, nullptr});

    if (tail_) {
        tail_->next = new_node;
    } else {
        head_ = new_node;
    }
    tail_ = new_node;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* new_node = allocator_.allocate(1);
    allocator_.construct(new_node, Node{value, nullptr, head_});

    if (head_) {
        head_->prev = new_node;
    } else {
        tail_ = new_node;
    }
    head_ = new_node;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!tail_) return;

    Node* to_delete = tail_;
    tail_ = tail_->prev;

    if (tail_) {
        tail_->next = nullptr;
    } else {
        head_ = nullptr;
    }

    allocator_.destroy(to_delete);
    allocator_.deallocate(to_delete, 1);
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (!head_) return;

    Node* to_delete = head_;
    head_ = head_->next;

    if (head_) {
        head_->prev = nullptr;
    } else {
        tail_ = nullptr;
    }

    allocator_.destroy(to_delete);
    allocator_.deallocate(to_delete, 1);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
    return Iterator(head_);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
    return Iterator(nullptr);
}

#endif // DOUBLYLINKEDLIST_TPP
