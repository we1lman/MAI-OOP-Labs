#ifndef CUSTOMMEMORYRESOURCE_HPP
#define CUSTOMMEMORYRESOURCE_HPP

#include <memory_resource>
#include <list>
#include <cstddef>

class CustomMemoryResource : public std::pmr::memory_resource {
public:
    CustomMemoryResource();
    ~CustomMemoryResource();

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    struct MemoryBlock {
        void* ptr;
        std::size_t size;
        std::size_t alignment;
    };

    std::list<MemoryBlock> allocated_blocks_;
    std::list<MemoryBlock> free_blocks_;
};

#endif // CUSTOMMEMORYRESOURCE_HPP
