#pragma once

#include <cstdlib>
#include <cstddef>
#include <stdexcept>

namespace dsa
{
    template <typename Tp, std::size_t Sz>
    struct _Array_traits
    {
        using type = Tp[Sz];
    };

    template <typename Tp>
    struct _Array_traits<Tp, 0>
    {
        struct type
        {
            inline Tp &operator[](size_t) const noexcept
            {
                abort();
            }

            inline constexpr explicit operator Tp *() const noexcept
            {
                return nullptr;
            }
        };
    };

    /**
     * @brief Fixed size array
     *
     * @warning zero sized array not implemented, use it at your own risk
     */
    template <typename Tp, std::size_t Sz>
    class Array
    {
    public:
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Tp value_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef value_type *iterator;
        typedef const value_type *const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        // constructor

        Array() {}

        Array(value_type arr[Sz])
        {
            for (size_type i = 0; i < Sz; i++)
                m_data[i] = arr[i];
        }

        // capacity

        constexpr size_type size() noexcept
        {
            return Sz;
        }

        constexpr size_type empty() noexcept
        {
            return (size() == 0);
        }

        // element access

        inline constexpr pointer data() noexcept
        {
            return static_cast<pointer>(m_data);
        }

        inline constexpr const_pointer data() const noexcept
        {
            return static_cast<const_pointer>(m_data);
        }

        inline constexpr reference front() noexcept
        {
            return m_data[0];
        }

        inline constexpr const_reference front() const noexcept
        {
            return m_data[0];
        }

        inline constexpr reference back() noexcept
        {
            return m_data[size() - 1];
        }

        inline constexpr const_reference back() const noexcept
        {
            return m_data[size() - 1];
        }

        inline reference operator[](size_type index) noexcept
        {
            return m_data[index];
        }

        inline const_reference operator[](size_type index) const noexcept
        {
            return m_data[index];
        }

        inline reference at(size_type index)
        {
            if (index >= this->size())
                throw new std::out_of_range("Out of range index");

            return m_data[index];
        }

        inline const_reference at(size_type index) const
        {
            if (index >= this->size())
                throw new std::out_of_range("Out of range index");

            return m_data[index];
        }

    private:
        typename _Array_traits<Tp, Sz>::type m_data;
    };
} // namespace dsa
