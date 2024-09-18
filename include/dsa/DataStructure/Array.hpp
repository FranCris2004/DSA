#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa
{
    /***
     * @brief Fixed size array
     */
    template <typename _Tp, std::size_t _Sz>
    class Array
    {
    public:
        typedef Array<_Tp, _Sz> type;
        typedef std::size_t size_type;
        typedef _Tp value_type;
        typedef value_type &reference;

    private:
        value_type m_data[_Sz];

    public:
        constexpr Array() : m_data{0} {}

        static constexpr size_type size()
        {
            return _Sz;
        }

        constexpr reference operator[](size_type index)
        {
            return m_data[index];
        }

        constexpr reference at(size_type index)
        {
            if (index >= this->size())
                throw new std::out_of_range("Out of range index");

            return m_data[index];
        }
    };
} // namespace dsa
