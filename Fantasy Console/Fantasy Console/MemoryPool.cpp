#include "MemoryPool.h"
#include <iostream>

MemoryPool* MemoryPool::instance = nullptr;

MemoryPool::MemoryPool(int size)
{
    this->size = size;
    memoryBlock = new char[size];
}

MemoryPool::~MemoryPool()
{
    delete[] memoryBlock;
}

MemoryPool* MemoryPool::GetInstance(int size)
{
    if (!instance)
    {
        instance = new MemoryPool(size);
    }
    return instance;
}

