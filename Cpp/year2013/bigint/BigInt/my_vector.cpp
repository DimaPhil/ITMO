#include "my_vector.h"

my_vector::my_vector()
{
    object_type = 1;
    s.number = 0;
}

my_vector::my_vector(int size)
{
    s.number = 0;
    if (size <= 1)
    {
        object_type = 1 + size;
    }
    else
    {
        data = raii_data_container(size);
        s.links_count = new uint32_t(1);
        object_type = 0;
    }
}

my_vector::my_vector(my_vector const& other)
{
    if (other.object_type != 0)
    {
        object_type = other.object_type;
        s.number = other.s.number;
    }
    else
    {
        data = other.data;
        ++(*other.s.links_count);
        s.links_count = other.s.links_count;
        object_type = 0;
    }
}

my_vector::~my_vector()
{
    if (object_type == 0)
    {
        --(*s.links_count);
        if (*s.links_count == 0)
        {
            delete s.links_count;
        }
    }
}

void my_vector::copy_data()
{
    if (object_type == 0 && (*s.links_count) > 1)
    {
        --(*s.links_count);
        s.links_count = new uint32_t(1);
        data = raii_data_container(data->digits, data->msize);
    }
}

void my_vector::start()
{
    if (object_type != 0)
    {
        data = raii_data_container();
        if (object_type == 2)
            data->push_back(s.number);
        s.links_count = new uint32_t(1);
        object_type = 0;
  }
}

void my_vector::push_back(uint32_t x)
{
    if (object_type == 1)
    {
        s.number = x;
        object_type = 2;
    }
    else
    {
        copy_data();
        start();
        data->push_back(x);
    }
}

void my_vector::pop_back()
{
    if (object_type != 0)
    {
        object_type = 1;
        return;
    }
    copy_data();
    data->pop_back();
}

void my_vector::resize(int size)
{
    copy_data();
    start();
    data->resize(size);
}

void my_vector::clear()
{
    resize(0);
}

size_t my_vector::size() const
{
    if (object_type > 0)
        return object_type == 2;
    return data->size();
}

uint32_t const& my_vector::operator [] (int i) const
{
    if (object_type > 0)
        return s.number;
    return (*data)[i];
}

uint32_t& my_vector::operator [] (int i)
{
    if (object_type > 0)
        return s.number;
    copy_data();
    return (*data)[i];
}

my_vector& my_vector::operator = (my_vector const& other)
{
    if (this == &other)
        return *this;
    if (object_type == 0 && (*s.links_count) > 1)
    {
        --(*s.links_count);
        s.links_count = new uint32_t(1);
        data = raii_data_container(data->digits, data->msize);
    }
    if (other.object_type > 0)
    {
        if (object_type > 0)
        {
            object_type = other.object_type;
            s.number = other.s.number;
        }
        else
        {
            data->clear();
            if (other.object_type == 2)
                data->push_back(other.s.number);
        }
    }
    else
    {
        if (object_type == 0)
        {
            if (--(*s.links_count) == 0)
            {

                delete s.links_count;
            }
        }
        else
        {
            object_type = 0;
        }
        data = other.data;
        s.links_count = other.s.links_count;
        ++(*s.links_count);
    }
    return *this;
}

uint32_t const& my_vector::back() const
{
    if (object_type > 0)
        return s.number;
    return data->back();
}
