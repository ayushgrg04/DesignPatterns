#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
mutex Singleton::mMutexLock;

Singleton::Singleton(const string& name)
{
    mVal = name;
}

Singleton* Singleton::getInstance(const string &value)
{
    if (instance == nullptr) {
        lock_guard<mutex> lock(mMutexLock);
        if (instance == nullptr)
            instance = new Singleton(value);
    }

    return instance;
}

const string& Singleton::getValue() const
{
    return mVal;
    // TODO: insert return statement here
}
