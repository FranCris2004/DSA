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

        static constexpr size_type size()
        {
            return Sz;
        }

        inline value_type &operator[](size_type index)
        {
            return m_data[index];
        }

        inline value_type &at(size_type index)
        {
            if (index >= this->size())
                throw new std::out_of_range("Out of range index");

            return m_data[index];
        }

    private:
        value_type m_data[Sz];
    };
} // namespace dsa
