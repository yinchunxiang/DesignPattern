#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Singleton {
public:
	static T& instance() {
		// C++11 thread-safe  local-static-initialization
		static T* t = new T();
		return *t;
	}

private:
	//non instance
	Singleton() = delete;
	~Singleton() = delete;

	//noncopyable
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main(int argc, const char* argv[]) {
	Singleton<string>::instance() = "Hello world!";
	cout << Singleton<string>::instance() << endl;
	return 0;
}


