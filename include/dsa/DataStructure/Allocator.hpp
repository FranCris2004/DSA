#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa
{
    /**
     * @brief Allocator virtual class.
     * Dynamically (not necessarily automatic) allocate/deallocate memory to be used by dynamic data structures.
     *
     * @warning It is intended to be used by a dynamic data structure, not directly.
     */
    template <typename _Tp>
    class Allocator
    {
    public:
        typedef std::size_t size_type;
        typedef _Tp value_type;

        /**
         * @brief Allocate new aligned memory
         * @param n number of elements to be allocated
         * @param a alignment bytes
         */
        virtual value_type *allocate(size_type n, size_type a) = 0;

        /**
         * @brief Deallocate previously allocated memory.
         * @param p Pointer to the allocated memory.
         *
         * @warning Depending on the implementation, it may not be safe to deallocate
         * memory allocated by an allocator of another class or with another type of value.
         */
        virtual void deallocate(value_type *p) = 0;
    };
} // namespace dsa
