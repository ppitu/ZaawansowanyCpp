#include <iostream>
#include <cstring>

template <typename R, typename T> 
R sum(T *beg, T *end)
{
	R total = R();
	while(beg != end) {
		total += *beg;
		beg++;
	}

	return total;
}

int main()
{
	char name[] = "@ @ @";

	int length = strlen(name);

	std::cout << sum<int>(name, &name[length]) << "\n";
}
