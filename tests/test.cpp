#include <gtest/gtest.h>
#include "../include/CustomMemoryResource.hpp"
#include "../include/DoublyLinkedList.hpp"
#include <string>

struct ComplexType {
    int a_;
    double b_;
    std::string c_;

    ComplexType(int a, double b, const std::string& c)
        : a_(a), b_(b), c_(c) {}
};

// Тесты для CustomMemoryResource
TEST(CustomMemoryResourceTest, AllocationDeallocation) {
    CustomMemoryResource mr;

    void* ptr1 = mr.allocate(32);
    EXPECT_NE(ptr1, nullptr);

    void* ptr2 = mr.allocate(64);
    EXPECT_NE(ptr2, nullptr);

    mr.deallocate(ptr1, 32);
    mr.deallocate(ptr2, 64);

    void* ptr3 = mr.allocate(32);
    EXPECT_EQ(ptr3, ptr1); // Должен переиспользовать освобожденный блок

    mr.deallocate(ptr3, 32);
}

// Тесты для DoublyLinkedList с типом int
TEST(DoublyLinkedListTest, IntPushBack) {
    CustomMemoryResource mr;
    DoublyLinkedList<int> list(&mr);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(DoublyLinkedListTest, IntPushFront) {
    CustomMemoryResource mr;
    DoublyLinkedList<int> list(&mr);

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    auto it = list.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}

TEST(DoublyLinkedListTest, IntPopBack) {
    CustomMemoryResource mr;
    DoublyLinkedList<int> list(&mr);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();
    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(DoublyLinkedListTest, IntPopFront) {
    CustomMemoryResource mr;
    DoublyLinkedList<int> list(&mr);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();
    auto it = list.begin();
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
}

// Тесты для DoublyLinkedList с ComplexType
TEST(DoublyLinkedListTest, ComplexTypeOperations) {
    CustomMemoryResource mr;
    DoublyLinkedList<ComplexType> list(&mr);

    list.push_back(ComplexType(1, 1.1, "one"));
    list.push_front(ComplexType(2, 2.2, "two"));
    list.push_back(ComplexType(3, 3.3, "three"));

    auto it = list.begin();
    EXPECT_EQ(it->a_, 2);
    EXPECT_EQ(it->b_, 2.2);
    EXPECT_EQ(it->c_, "two");
    ++it;
    EXPECT_EQ(it->a_, 1);
    EXPECT_EQ(it->b_, 1.1);
    EXPECT_EQ(it->c_, "one");
    ++it;
    EXPECT_EQ(it->a_, 3);
    EXPECT_EQ(it->b_, 3.3);
    EXPECT_EQ(it->c_, "three");
}

// Тест итератора
TEST(DoublyLinkedListTest, IteratorTraversal) {
    CustomMemoryResource mr;
    DoublyLinkedList<int> list(&mr);

    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    int expected = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected);
        ++expected;
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
