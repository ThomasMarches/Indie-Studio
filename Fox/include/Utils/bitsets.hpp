/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** bitsets.hpp
*/

#ifndef FOX_BITSET_HPP_
#define FOX_BITSET_HPP_

#include <iostream>
#include <cstring>

class bitset
{
private:
    char* data = nullptr;
    std::size_t m_lSize = 8;

public:
    bitset() : m_lSize(8), data(nullptr)
    {
        data = new char[m_lSize + 1]();
        data[m_lSize] = '\0';
        if (data) {
            data[m_lSize] = '\0';
            reset();
        }
    }

    bitset(std::size_t s) : m_lSize(s), data(nullptr)
    {
        data = new char[m_lSize + 1]();
        if (data) {
            data[m_lSize] = '\0';
            reset();
        }
    }

    bitset(const bitset& other)
        : m_lSize(other.m_lSize)
    {
        if (data)
            delete data;
        data = new char[m_lSize + 1];
        std::memcpy(data, other.data, m_lSize);
    }

    bitset(bitset&& other)
     : m_lSize(std::move(other.m_lSize))
    {
        if (data)
            delete data;
        data = std::move(other.data);
        other.data = nullptr;
    }

    ~bitset()
    {
        if (data) {
            m_lSize = 0;
            delete[] data;
            data = nullptr;
        }
    }

    bitset& operator=(const bitset& other)
    {
        m_lSize = other.m_lSize;
        if (data)
            delete data;
        data = new char[m_lSize + 1];
        std::memcpy(data, other.data, m_lSize);
        return *this;
    }

    bitset& operator=(bitset&& other)
    {
        m_lSize = std::move(other.m_lSize);
        if (data)
            delete data;
        data = std::move(other.data);
        other.data = nullptr;
        return *this;
    }

    const char* getData() const;

    std::size_t size() const;
    std::size_t count() const;
    bool test(std::size_t n);
    bool none();
    bool any();
    void set();
    void set(std::size_t n, bool v);
    void reset();
    void reset(std::size_t n);
    void flip(std::size_t n);

    char &operator[](const std::size_t &n);
    char &operator[](const std::size_t &n) const;
    bool operator==(const bitset& other);
};
bitset operator&(const bitset& lhs, const bitset& rhs);
std::ostream& operator<<(std::ostream& os, const bitset &b);
#endif