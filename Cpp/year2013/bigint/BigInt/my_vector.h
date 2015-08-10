#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <algorithm>
#include <cstring>
#include <stdexcept>

using namespace std;

struct data_container
{
    static const int DEFAULT_CAPACITY = 16;

    uint32_t *digits;
    size_t msize;
    size_t capacity;

    data_container()
    {
        capacity = DEFAULT_CAPACITY;
        digits = new uint32_t[capacity];
        memset(digits, 0, sizeof(uint32_t) * capacity);
        msize = 0;
    }

    data_container(size_t size)
    {
        msize = size;
        capacity = 1;
        while (capacity < size)
            capacity <<= 1;
        digits = new uint32_t[capacity];
        memset(digits, 0, sizeof(uint32_t) * capacity);
    }

    data_container(uint32_t *_digits, size_t _size)
    {
        capacity = 1;
        while (capacity < _size)
            capacity <<= 1;
        digits = new uint32_t[capacity];
        memset(digits, 0, sizeof(uint32_t) * capacity);
        for (size_t i = 0; i != _size; ++i)
            digits[i] = _digits[i];
        msize = _size;
    }

    ~data_container()
    {
        delete [] digits;
    }

    void push_back(uint32_t x)
    {
        if (msize < capacity)
        {
            digits[msize++] = x;
        }
        else
        {
            capacity <<= 1;
            uint32_t *new_digits = new uint32_t[capacity];
            for (size_t i = 0; i != msize; ++i)
                new_digits[i] = digits[i];
            delete [] digits;
            digits = new_digits;
            digits[msize++] = x;
        }
    }

    void resize(size_t new_size)
    {
        if (new_size <= capacity)
            msize = new_size;
        else
        {
            capacity = 1;
            while (capacity < new_size)
                capacity <<= 1;
            uint32_t *new_digits = new uint32_t[capacity];
            for (size_t i = 0; i != msize; ++i)
                new_digits[i] = digits[i];
            msize = new_size;
            delete [] digits;
            digits = new_digits;
        }
    }

    void clear()
    {
        resize(0);
    }

    void pop_back()
    {
        if (msize == 0)
            throw runtime_error("Can't pop from empty vector");
        digits[--msize] = 0;
    }

    uint32_t const& operator [] (int i) const
    {
        return digits[i];
    }

    uint32_t& operator [] (int i)
    {
        return digits[i];
    }

    uint32_t& back()
    {
        return digits[msize - 1];
    }

    uint32_t const& back() const
    {
        return digits[msize - 1];
    }

    size_t size() const
    {
        return msize;
    }
};

struct raii_data_container
{
    data_container *data;
    raii_data_container(size_t size)
    {
        delete data;
        data = new data_container(size);
    }

    raii_data_container()
    {
        delete data;
        data = new data_container();
    }

    raii_data_container(uint32_t *digits, uint32_t size)
    {
        delete data;
        data = new data_container(digits, size);
    }

    raii_data_container(data_container *data)
    {
        delete this->data;
        this->data = data;
    }

    ~raii_data_container()
    {
        delete data;
    }
};

struct my_vector
{
private:
    raii_data_container data;
    union Links
    {
        uint32_t number;
        uint32_t *links_count;
    } s;
    int32_t object_type;
    void start();
    void copy_data();
public:
    my_vector();
    my_vector(int size);
    my_vector(my_vector const& other);
    ~my_vector();
    void push_back(uint32_t x);
    void pop_back();
    void resize(int size);
    void clear();

    size_t size() const;
    uint32_t const& operator [] (int i) const;
    uint32_t& operator [] (int i);

    my_vector& operator = (my_vector const& other);
    uint32_t const& back() const;
};

#endif //MY_VECTOR_H
