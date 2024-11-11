#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <memory_resource>
#include <iterator>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

public:
    using allocator_type = std::pmr::polymorphic_allocator<Node>;

    DoublyLinkedList(std::pmr::memory_resource* mr = std::pmr::get_default_resource());
    ~DoublyLinkedList();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();

    class Iterator;
    Iterator begin();
    Iterator end();

private:
    Node* head_;
    Node* tail_;
    allocator_type allocator_;
};

#include "DoublyLinkedList.tpp"

#endif // DOUBLYLINKEDLIST_HPP
