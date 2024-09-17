#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa
{
    /***
     * @brief Fixed size array
     */
    template <typename T, std::size_t S>
    class Array
    {
    private:
        T m_data[S];

    public:
        constexpr Array() : m_data{0} {}

        static constexpr std::size_t size()
        {
            return S;
        }

        constexpr T &operator[](std::size_t index)
        {
            return m_data[index];
        }

        constexpr T &at(std::size_t index)
        {
            if (index >= this->size())
                throw new std::out_of_range("Out of range index");

            return m_data[index];
        }
    };
} // namespace dsa
