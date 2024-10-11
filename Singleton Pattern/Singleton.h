#pragma once

#include <string>
#include <mutex>

//#define SINGLETON Singleton::getInstance()

using namespace std;

class Singleton {
private:
	static Singleton* instance;
	string mVal;
	static std::mutex mMutexLock;
	Singleton(const string &name);
	~Singleton() = default;

public:
	static Singleton* getInstance(const string &name);
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
	const string& getValue() const;
};