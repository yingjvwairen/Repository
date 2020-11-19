// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL

#include <iostream>
#include <string>

using namespace std;

template <class K>
class Hash;

template <>
class Hash<string>
{
public:
    size_t operator()(const string theKey) const
    { // Convert theKey to a nonnegative integer.
        unsigned long HashValue = 0;
        int length = (int)theKey.length();
        for (int i = 0; i < length; i++)
            HashValue = 5 * HashValue + theKey.at(i);

        return size_t(HashValue);
    }
};

template <>
class Hash<int>
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};

template <>
class Hash<long>
{
public:
    size_t operator()(const long theKey) const
    {
        return size_t(theKey);
    }
};

// Hash table using linear open addressing and division

// mapping functions from K to nonnegative integer

template <class K, class E>
class HashTable
{
public:
    HashTable(int theDivisor = 11);
    ~HashTable() { delete[] table; }

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E> *find(const K &) const;
    void insert(const pair<const K, E> &);
    void erase(const K &);
    void output(ostream &out) const;

protected:
    int search(const K &) const;
    pair<const K, E> **table; // Hash table
    Hash<K> HashMap;          // maps type K to nonnegative integer
    int dSize;                // number of pairs in dictionary
    int divisor;              // Hash function divisor
};

template <class K, class E>
HashTable<K, E>::HashTable(int theDivisor)
{
    divisor = theDivisor;
    dSize = 0;

    // allocate and initialize Hash table array
    table = new pair<const K, E> *[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = NULL;
}

template <class K, class E>
int HashTable<K, E>::search(const K &theKey) const
{ // Search an open addressed Hash table for a pair with key theKey.
    // Return location of matching pair if found, otherwise return
    // location where a pair with key theKey may be inserted
    // provided the Hash table is not full.

    int i = (int)HashMap(theKey) % divisor; // home bucket
    int j = i;                              // start at home bucket
    do
    {
        if (table[j] == NULL || table[j]->first == theKey)
            return j;
        j = (j + 1) % divisor; // next bucket
    } while (j != i);          // returned to home bucket?

    return j; // table full
}

template <class K, class E>
pair<const K, E> *HashTable<K, E>::find(const K &theKey) const
{ // Return pointer to matching pair.
    // Return NULL if no matching pair.
    // search the table
    int b = search(theKey);

    // see if a match was found at table[b]
    if (table[b] == NULL || table[b]->first != theKey)
    {
        cout << -1 << endl;
        return NULL;
    } // no match
    cout << b << endl;
    return table[b]; // matching pair
}

template <class K, class E>
void HashTable<K, E>::insert(const pair<const K, E> &thePair)
{ // Insert thePair into the dictionary. Overwrite existing
    // pair, if any, with same key.
    // Throw HashTableFull exception in case table is full.
    // search the table for a matching pair
    int b = search(thePair.first);

    // check if matching pair found
    if (table[b] == NULL)
    {
        // no matching pair and table not full
        table[b] = new pair<const K, E>(thePair);
        dSize++;
        cout << b << endl;
    }
    else
    { // check if duplicate or table full
        if (table[b]->first == thePair.first)
        { // duplicate, change table[b]->second
            cout << "Existed" << endl;
        }
        else // table is full
            cout << "HashTableFull" << endl;
    }
}

template <class K, class E>
void HashTable<K, E>::erase(const K &theKey)
{
    int b = search(theKey);

    if (table[b] == NULL)
    {
        cout << "Not Found" << endl;
        return;
    }

    delete table[b]; //table[b]->~pair();
    table[b] = NULL;
    int gap = b;
    b++;
    b = b % divisor;

    int count = 0;
    while (table[b] != NULL)
        if ((gap < b && gap < ((int)HashMap(table[b]->first) % divisor) && ((int)HashMap(table[b]->first) % divisor) <= b) || (gap > b && gap < ((int)HashMap(table[b]->first) % divisor) && ((int)HashMap(table[b]->first) % divisor) <= divisor - 1) || (gap > b && 0 <= ((int)HashMap(table[b]->first) % divisor) && ((int)HashMap(table[b]->first) % divisor) <= b))
        {
            b++;
            b = b % divisor;
        }
        else
        {
            table[gap] = table[b];
            table[b] = NULL;
            gap = b;
            b++;
            b = b % divisor;

            count++;
        }

    cout << count << endl;

    dSize--;
}

template <class K, class E>
void HashTable<K, E>::output(ostream &out) const
{ // Insert the Hash table into the stream out.
    for (int i = 0; i < divisor; i++)
        if (table[i] == NULL)
            cout << "NULL" << endl;
        else
            cout << table[i]->first << " "
                 << table[i]->second << endl;
}

// overload <<
template <class K, class E>
ostream &operator<<(ostream &out, const HashTable<K, E> &x)
{
    x.output(out);
    return out;
}

int main()
{
    int D, n, opt, K;
    cin >> D >> n;
    HashTable<int, int> h(D);
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        cin >> opt >> K;
        switch (opt)
        {
        case 0:
            p.first = K;
            h.insert(p);
            break;
        case 1:
            p.first = K;
            h.find(K);
            break;
        case 2:
            p.first = K;
            h.erase(K);
            break;
        default:
            break;
        }
    }
}