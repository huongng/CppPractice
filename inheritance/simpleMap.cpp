#include <iostream>
#include <map>
#include <string>
using namespace std;

// obj[key1][key2] = val
// key1 and key2 of type K
// val of type V
template<class K, class V>
class Map
{
public:
    map<K, V>& operator[](const K& key);
private:
    map<K, map<K, V>> mm;
};

template<class K, class V>
map<K, V>& Map<K, V>::operator[](const K& key)
{
    typename map<K, map<K, V>>::iterator it = mm.find(key);
    if (it != mm.end()) {
	mm.insert(make_pair(key, map<K, V>()));
	it--;
    }
    return it->second;
}

int main()
{
    Map<string, string> mm;
    mm["a"]["b"] = "start";
    cout << mm["a"]["b"] << endl;
    return 0;
}
