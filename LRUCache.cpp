
#include <iostream>
#include<map>// implementation is based on balanced binary tree (Red Black Tree)
#include<unordered_map>// implementation is based in hash map
#include <list>

using namespace std;

class LRU_Cache;

class LRU_Cache // Least recently used cache 
{
public:
    // Paramentric constructor to initialise with size of cache
    LRU_Cache(int nCacheSize);

    ~LRU_Cache();

    // Functions to search and replace data in cache

    // Put item in cache memory
    void put(int nValToInsert);

    // Get all item from cache memory
    void GetCacheItems();

private:

    // cache size
    int m_CacheSize;

    // Need to store keys of cache..
    // for fast retrieval and replace operation use doubly linked list
    list<int> m_doublylinkedlist;

    // Store the reference address in hashtable, iterator gives the pointer
    unordered_map<int, list<int>::iterator> m_keyRef;

protected:

};

LRU_Cache::LRU_Cache(int nCacheSize):m_CacheSize(nCacheSize)
{

}

LRU_Cache::~LRU_Cache()
{
    
}

void LRU_Cache::put(int nValToInsert)
{
    // Get the iterator for value from cache 
    unordered_map<int, list<int>::iterator>::iterator itrkey = m_keyRef.find(nValToInsert);

    // check if value is present in hash table or not
    // if value is not found in list
    if (itrkey == m_keyRef.end())
    {
        // if cache size id equal to the capacity, i.e cache is full
        if (m_keyRef.size() == m_CacheSize)
        {
            // delete least recently used element
            // get the least recently used element
            int key = m_doublylinkedlist.back();
            // remove element from list
            m_doublylinkedlist.pop_back();
            // erase reference to the address of element from hash table
            m_keyRef.erase(key); 
        }

        // If element is not present in cache paging fault occurs, we can count
        // how many times paging fault happened
    }
    else 
    {
        // if elemet is present in cache, erase from cache list
        m_doublylinkedlist.erase(itrkey->second);
    }

    // updating/Refreshing the cache
    // Adding key in front of double linked list cache
    m_doublylinkedlist.push_front(nValToInsert);
    // Adding the key and reference to the address in hashtable
    m_keyRef[nValToInsert] = m_doublylinkedlist.begin();
}

void LRU_Cache::GetCacheItems()
{
    for(list<int>::iterator itr = m_doublylinkedlist.begin(); itr != m_doublylinkedlist.end(); itr++)
        cout << *itr << " ";
    cout << endl;
}

int main()
{
    LRU_Cache lrucache(3);
    lrucache.put(1);
    lrucache.GetCacheItems();
    lrucache.put(2);
    lrucache.GetCacheItems();
    lrucache.put(3);
    lrucache.GetCacheItems();
    lrucache.put(5);
    lrucache.GetCacheItems();
    lrucache.put(4);
    lrucache.GetCacheItems();
    lrucache.put(2);
    lrucache.GetCacheItems();
    lrucache.put(4);

    lrucache.GetCacheItems();

    return 0;
}

/*
// OUTPUT
1 
2 1 
3 2 1 
5 3 2 
4 5 3 
2 4 5 
4 2 5 
*/
