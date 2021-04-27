#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <list>
using std::list;

#include <iterator>
using std::iterator_traits;
using std::forward_iterator_tag;
using std::random_access_iterator_tag;
using std::bidirectional_iterator_tag;

template <typename Iter>
int operacja_impl(Iter i, forward_iterator_tag)
{
    cout << "Iterator jednokierunkowy (albo lepszy).\n";
    // Tu umieĹÄ wersjÄ algorytmu, ktĂłra zadziaĹa dla iteratora oferujÄcego
    // tylko operacjÄ przesuwania na nastÄpny element.
    return 1;
}

template <typename Iter>
int operacja_impl(Iter i, random_access_iterator_tag)
{
    cout << "Iterator o swobodnym dostepie.\n";
    // A tu jest miejsce na efektywniejszÄ wersjÄ algorytmu.
    return 2;
}

template <typename Iter>
int operacja_impl(Iter i, bidirectional_iterator_tag)
{
    cout << "Iterator o dwukierunkowym dostępie.\n";
    return 3;
};

template <typename Iter>
inline int operacja(Iter i)
{
    return operacja_impl(i,
            typename iterator_traits<Iter>::iterator_category());
}


int main()
{
    list<int> l;
    operacja(l.begin());

    int t[3];
    operacja(t);

    return 0;
}
