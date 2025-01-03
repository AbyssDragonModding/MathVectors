// Single header math vector library
// Created on 01/02/2025

#ifndef MATHVECTORS_HPP
#define MATHVECTORS_HPP

#define THROW_RUNTIME_ERROR(msg) throw std::runtime_error(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " - " + msg)
#pragma once
#include <iostream>
#include <array>
#include <stdexcept>
#include <sstream>
#include <algorithm>

namespace MathVectors
{

    template <typename T, std::size_t S>
    class Vector
    {
    public:
        // Constructor and Destructor
        // Default Constructor
        Vector() : m_Data{}, m_Size(S) {};

        // Constructor with initializer list
        Vector(std::initializer_list<T> data)
        {
            try
            {
                if (data.size() != S)
                {
                    THROW_RUNTIME_ERROR("\nERROR: \nFile: " + std::string(__FILE__) + "\nLine: " + std::to_string(__LINE__) + "\nType: Vector size mismatch, required (" +
                                        std::to_string(S) + "), found (" + std::to_string(data.size()) + ")");
                }

                // Move the initializer list data into the array
                std::copy(data.begin(), data.end(), this->m_Data.begin());
                this->m_Size = S;
            }
            catch (std::runtime_error &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }

        // Copy Constructor
        Vector(const Vector<T, S> &other) = default;

        // Move Constructor
        Vector(const Vector<T, S> &&other) noexcept : m_Data(std::move(other.m_Data)), m_Size(other.m_Size) {}

        // Functions
        std::size_t Size() const
        {
            return m_Size;
        }

        // Debug printing
        void Print(const char varName[])
        {
            std::cout << varName << ": ";
            this->Print();
        }
        void Print()
        {
            std::cout << "(";
            for (std::size_t i = 0; i < this->m_Size; i++)
            {
                if (i == this->m_Size - 1)
                {
                    std::cout << this->m_Data[i];
                }
                else
                {
                    std::cout << this->m_Data[i] << ", ";
                }
            }
            std::cout << ")" << std::endl;
        }

        // Operator Overloads
        // Array access overload
        T operator[](std::size_t index) const
        {
            return m_Data.at(index);
        }
        T &operator[](std::size_t index)
        {
            return m_Data.at(index);
        }
        // Friend function for output stream
        friend std::ostream &operator<<(std::ostream &os, const Vector<T, S> &vec)
        {
            os << "(";
            for (std::size_t i = 0; i < S; ++i)
            {
                os << vec.m_Data[i];
                if (i < S - 1)
                {
                    os << ", ";
                }
            }
            os << ")";
            return os;
        }

        // Friend function for input stream
        friend std::istream &operator>>(std::istream &is, Vector<T, S> &vec)
        {
            for (std::size_t i = 0; i < S; ++i)
            {
                is >> vec.m_Data[i];
            }
            return is;
        }

        // Equality
        bool operator==(const Vector<T, S> &other) const
        {
            return this->m_Data == other.m_Data;
        }

        // Not Equal
        bool operator!=(const Vector<T, S> &other) const
        {
            return this->m_Data != other.m_Data;
        }

        // Subtraction
        Vector<T, S> operator-(const Vector<T, S> &other) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                result[i] = this->m_Data[i] - other[i];
            }
            return result;
        }
        // Scalar Subtraction
        Vector<T, S> operator-(const T &scalar) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                result[i] = this->m_Data[i] - scalar;
            }
            return result;
        }

        // Addition
        Vector<T, S> operator+(const Vector<T, S> &other) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                result[i] = this->m_Data[i] + other[i];
            }
            return result;
        }

        // Scalar Addition
        Vector<T, S> operator+(const T &scalar) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                result[i] = this->m_Data[i] + scalar;
            }
            return result;
        }

        // Multiplication
        Vector<T, S> operator*(const Vector<T, S> &other) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                result[i] = this->m_Data[i] * other[i];
            }
            return result;
        }

        // Scalar Multiplication
        Vector<T, S> operator*(const T &scalar) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                result[i] = this->m_Data[i] * scalar;
            }
            return result;
        }

        // Division
        Vector<T, S> operator/(const Vector<T, S> &other) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                if (other[i] == 0)
                {
                    THROW_RUNTIME_ERROR("Division by zero in vector division");
                }
                result[i] = this->m_Data[i] / other[i];
            }
            return result;
        }
        
        // Scalar Division
        Vector<T, S> operator/(const T &scalar) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                if (scalar == 0 || scalar == 0.0)
                {
                    THROW_RUNTIME_ERROR("Division by zero in vector scalar division");
                }
                result[i] = this->m_Data[i] / scalar;
            }
            return result;
        }

        // Modulus
        Vector<T, S> operator%(const Vector<T, S> &other) const
        {
            Vector<T, S> result{};
            for (std::size_t i = 0; i < S; i++)
            {
                if (other[i] == 0)
                {
                    THROW_RUNTIME_ERROR("Division by zero in vector modulus");
                }
                result[i] = this->m_Data[i] % other[i];
            }
            return result;
        }

    private:
        // Private variables
        std::array<T, S> m_Data;
        std::size_t m_Size;
    };
}
#endif