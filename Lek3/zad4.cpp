#include <iostream>
#include <vector>

template <typename T, int N = 100, typename R = T*>
class Stack;

template <typename T, int N>
class Stack<T, N, T*>
{
	public:
		Stack() : _top(0){};
		void push(T e) { _rep[_top++] = e; }
		T pop() { return _rep[--_top]; }

	private:
		T _rep[N];
		unsigned int _top;
};

template <typename T, int N, template<typename E> class Sequence>
class Stack<T, N, Sequence<T> >
{
	public:
		void push(T e) {_rep.push_back(e); }
		T pop() { T top = _rep.top(); _rep.pop_back(); return top; }
		bool is_empty() const {return _rep.empty(); }
	private:
		Sequence<T> _rep;
};

int main()
{
	Stack<int, 100> s_default;
	Stack<int, 0, std::vector<int> > s_container;
}
