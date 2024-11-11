#include "../include/CustomMemoryResource.hpp"
#include <cstdlib>
#include <new>

CustomMemoryResource::CustomMemoryResource() {}

CustomMemoryResource::~CustomMemoryResource() {
    for (auto& block : allocated_blocks_) {
        ::operator delete(block.ptr, std::align_val_t(block.alignment));
    }

    for (auto& block : free_blocks_) {
        ::operator delete(block.ptr, std::align_val_t(block.alignment));
    }
}

void* CustomMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    for (auto it = free_blocks_.begin(); it != free_blocks_.end(); ++it) {
        if (it->size >= bytes && it->alignment == alignment) {
            MemoryBlock block = *it;
            free_blocks_.erase(it);
            allocated_blocks_.push_back(block);
            return block.ptr;
        }
    }

    void* ptr = ::operator new(bytes, std::align_val_t(alignment));
    if (!ptr) {
        throw std::bad_alloc();
    }

    allocated_blocks_.push_back({ ptr, bytes, alignment });
    return ptr;
}

void CustomMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    (void)bytes;
    (void)alignment;

    for (auto it = allocated_blocks_.begin(); it != allocated_blocks_.end(); ++it) {
        if (it->ptr == p) {
            MemoryBlock block = *it;
            allocated_blocks_.erase(it);
            free_blocks_.push_back(block);
            return;
        }
    }
}

bool CustomMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
