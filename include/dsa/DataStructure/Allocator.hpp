#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa
{
    /**
     * @brief Allocator virtual class.
     * Dynamically allocate/deallocate memory to be used by dynamic data structures.
     */
    template <typename Tp>
    class Allocator
    {
    public:
        typedef std::size_t size_type;
        typedef Tp value_type;

        /**
         * @brief Allocate new memory.
         * @param n Number of elements to be allocated.
         */
        virtual value_type *allocate(size_type n) = 0;

        /**
         * @brief Deallocate previously allocated memory.
         * @param p Pointer to the allocated memory.
         *
         * @warning Depending on the implementation, it may not be safe to deallocate
         * memory allocated by an allocator of another class or with another type of value.
         */
        virtual void deallocate(value_type *p) = 0;
    };

    /**
     * @brief Default allocator for the library.
     * Uses the new and delete operators in order to allocate and deallocate memory.
     */
    template <typename Tp>
    class DefaultAllocator : public Allocator<Tp>
    {
    public:
        typedef std::size_t size_type;
        typedef Tp value_type;

        virtual value_type *allocate(size_type n) override
        {
            return (value_type *)(::operator new(n * sizeof(value_type)));
        }

        virtual void deallocate(value_type *p) override
        {
            ::operator delete(p);
        }
    };
} // namespace dsa
