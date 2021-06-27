/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Any.cpp
*/

#include "Utils/Any.hpp"

Any::Any(void* data, std::function<void(void*)> dtor)
    : m_pData(data)
    , m_dtor(dtor)
{
}

Any::Any(Any&& other)
    : m_pData(other.m_pData)
    , m_dtor(std::move(other.m_dtor))
{
    other.m_pData = nullptr;
}

Any::~Any()
{
    if (m_pData)
        m_dtor(m_pData);
    m_pData = nullptr;
}