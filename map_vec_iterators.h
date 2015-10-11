#ifndef MAP_VEC_ITERATORS_H
#define MAP_VEC_ITERATORS_H

#include <map>
#include <iterator>

using namespace std;

template<class T, class U>
void print_map(map<T, U> m)
//prints the keys and values in a map.
//Since I only use cout, this template will display any map<T, U>
// as long as the types T and U support streaming.
{
    //typename map<T, U>::iterator next_to_last = m.end();

    for (typename map<T, U>::iterator it = m.begin(); it != m.end(); ++it)
        cout << it->first << "=" << it->second << " ";
    //cout << m.end()->first << " = " << m.end()->second << endl;
    cout << endl;
}

template<class T>
void print_linear(T l, int start, int end)
//prints the contents of a vector or array.
//arguments: the iterable(array or vector), the start index (default 0) and the end index.
//Why do we need indices? A vector would support .size(); but an array would not.
{
    cout << "[";
    for(int i = start; i <= end - 1; i++)
        cout << l[i] << ", ";
    cout << l[end] << "]" << endl;
}

#endif
