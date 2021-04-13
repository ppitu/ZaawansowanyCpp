#include <iostream>

template <typename T, typename U>
T convert(U u)
{
	return static_cast<T>(u);
}
template <> int convert<int, double> (double u) { return static_cast<int>(u); }
template <> double convert<double, double> (double u) { return u; }

int main()
{
	std::cout << convert<int>(3.14) << "\n"; 
	std::cout << convert<double>(3.56) << "\n";
}
