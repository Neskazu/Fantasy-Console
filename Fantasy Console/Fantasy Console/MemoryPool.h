#pragma once

class MemoryPool
{
private:
    char* memoryBlock;
    int size;
    static MemoryPool* instance;
    MemoryPool(int size);
public:
    ~MemoryPool();
    static MemoryPool* getInstance(int size);

    template <typename T>
    T* Allocate(void* address, int count = 1) {
        if (sizeof(T) * count <= size) {
            T* allocatedPtr = reinterpret_cast<T*>(address);
            return allocatedPtr;
        }
        else {
           
            return nullptr;
        }
    }

    char* GetMemoryBlock() const { return memoryBlock; }
};
