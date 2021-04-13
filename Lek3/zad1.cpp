#include <iostream>
#include <random>
#include <cstring>

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T>
T* max(T *a, T *b)
{
	return ((*a) > (*b)) ? a : b;
}

template <typename T>
T max(T *data, size_t n)
{
	T _max = data[0];

	for(size_t i = 0; i < n; i++)
		if(data[i] > _max)
			_max = data[i];

	return _max;
}

template <>
char *max<char *>(char * a, char *b)
{
	return (strcmp(a, b) > 0) ? a : b;
}

template<> 
const char* max<const char *>(const char *a,const char *b) 
{
  	return (strcmp(a,b)>0)?a:b;
}

int main()
{
	std::cout << max(3, 4) << "\n";
	std::cout << max(5, 4) << "\n";


	int t[10];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 100);

	for(short i = 0; i < 10; i++)
		t[i] = distrib(gen);

	std::cout << max(t, 10) << "\n";
}
