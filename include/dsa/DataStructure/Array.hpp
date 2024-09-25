#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa
{
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
        typedef Tp value_type;
        typedef value_type &reference;
        typedef value_type const &const_reference;

        static constexpr size_type size()
        {
            return Sz;
        }

        inline reference operator[](size_type index)
        {
            return m_data[index];
        }

        inline const_reference operator[](size_type index) const
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
        value_type m_data[Sz];
    };
} // namespace dsa
