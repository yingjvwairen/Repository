// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL

#include <iostream>
#include <string>
#include <limits.h>

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

// Hash table using sorted chains and division
// implements all dictionary methods

// mapping functions from K to nonnegative integer
// abstract class dictionary
// abstract data type specification for dictionary data structure
// all methods are pure virtual functions
// K is key type and E is value type

// sorted chain, implements dictionary

// node with a next and element field; element is a pair<const K,E>

template <class K, class E>
struct pairNode
{
   typedef pair<const K, E> pairType;
   pairType element;
   pairNode<K, E> *next;

   pairNode(const pairType &thePair) : element(thePair) {}
   pairNode(const pairType &thePair, pairNode<K, E> *theNext)
       : element(thePair) { next = theNext; }
};

template <class K, class E>
class sortedChain
{
public:
   sortedChain()
   {
      firstNode = tailNode;
      dSize = 0;
      count++;
   }
   ~sortedChain();

   bool empty() const { return dSize == 0; }
   int size() const { return dSize; }
   pair<const K, E> *find(const K &) const;
   void erase(const K &);
   void insert(const pair<const K, E> &);
   void output(ostream &out) const;

protected:
   pairNode<K, E> *firstNode;       // pointer to first node in chain
   static pairNode<K, E> *tailNode; // shared pointer to last node in chain
   int dSize;                       // number of elements in dictionary
   static int count;
};

template <class K, class E>
int sortedChain<K, E>::count = 0;

template <class K, class E>
pairNode<K, E> *sortedChain<K, E>::tailNode = new pairNode<K, E>(pair<const K, E>(INT_MAX, NULL), NULL);

template <class K, class E>
sortedChain<K, E>::~sortedChain()
{ // Destructor.  Delete all nodes.
   while (firstNode != tailNode)
   { // delete firstNode
      pairNode<K, E> *nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
   count--;
   if (count == 0)
      delete tailNode;
}

template <class K, class E>
pair<const K, E> *sortedChain<K, E>::find(const K &theKey) const
{ // Return pointer to matching pair.
   // Return NULL if no matching pair.
   pairNode<K, E> *currentNode = firstNode;

   // search for match with theKey
   while (currentNode != tailNode &&
          currentNode->element.first != theKey) //currentNode->element.first < theKey
      currentNode = currentNode->next;

   // verify match
   if (currentNode->element.first == theKey)
   // yes, found match
   {
      cout << dSize << endl;
      return &currentNode->element;
   }

   // no match
   cout << "Not Found" << endl;
   return NULL;
}

template <class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E> &thePair)
{ // Insert thePair into the dictionary. Overwrite existing
   // pair, if any, with same key.
   pairNode<K, E> *p = firstNode,
                  *tp = NULL; // tp trails p

   // move tp so that thePair can be inserted after tp
   while (p->element.first < thePair.first)
   {
      tp = p;
      p = p->next;
   }

   // check if there is a matching pair
   if (p->element.first == thePair.first)
   { // replace old value
      cout << "Existed" << endl;
      return;
   }

   // no match, set up node for thePair
   pairNode<K, E> *newNode = new pairNode<K, E>(thePair, p);

   // insert newNode just after tp
   if (tp == NULL)
      firstNode = newNode;
   else
      tp->next = newNode;

   dSize++;
   return;
}

template <class K, class E>
void sortedChain<K, E>::erase(const K &theKey)
{ // Delete the pair, if any, whose key equals theKey.
   pairNode<K, E> *p = firstNode,
                  *tp = NULL; // tp trails p

   // search for match with theKey
   while (p->element.first < theKey)
   {
      tp = p;
      p = p->next;
   }

   // verify match
   if (p->element.first == theKey)
   { // found a match
      // remove p from the chain
      if (tp == NULL)
         firstNode = p->next; // p is first node
      else
         tp->next = p->next;

      delete p;
      dSize--;

      cout << dSize << endl;
   }
   else
      cout << "Delete Failed" << endl;
}

template <class K, class E>
void sortedChain<K, E>::output(ostream &out) const
{ // Insert the chain elements into the stream out.
   for (pairNode<K, E> *currentNode = firstNode;
        currentNode != tailNode;
        currentNode = currentNode->next)
      out << currentNode->element.first << " "
          << currentNode->element.second << "  ";
}

template <class K, class E>
class HashChains
{
public:
   HashChains(int theDivisor = 11)
   {
      divisor = theDivisor;
      dSize = 0;

      // allocate and initialize Hash table array
      table = new sortedChain<K, E>[divisor];
   }

   ~HashChains() { delete[] table; }

   bool empty() const { return dSize == 0; } // return true iff dictionary is empty
   int size() const { return dSize; }        // return number of pairs in dictionary

   pair<const K, E> *find(const K &theKey) const
   { // return pointer to matching pair
      return table[HashMap(theKey) % divisor].find(theKey);
   }

   void insert(const pair<const K, E> &thePair)
   { // insert a (key, value) pair into the dictionary
      int homeBucket = (int)HashMap(thePair.first) % divisor;
      int homeSize = table[homeBucket].size();
      table[homeBucket].insert(thePair);
      if (table[homeBucket].size() > homeSize)
         dSize++;
   }

   void erase(const K &theKey)
   { // remove matching pair
      table[HashMap(theKey) % divisor].erase(theKey);
   }

   void output(ostream &out) const
   {
      for (int i = 0; i < divisor; i++)
         if (table[i].size() == 0)
            cout << "NULL" << endl;
         else
            cout << table[i] << endl;
   }

protected:
   sortedChain<K, E> *table; // Hash table
   Hash<K> HashMap;          // maps type K to nonnegative integer
   int dSize;                // number of elements in list
   int divisor;              // Hash function divisor
};

// overload <<
template <class K, class E>
ostream &operator<<(ostream &out, const HashChains<K, E> &x)
{
   x.output(out);
   return out;
}

int main()
{
   int D, n, i = 0, opt, K;

   cin >> D >> n;

   HashChains<int, int> h(D);
   pair<int, int> p;

   while (i != n)
   {
      cin >> opt >> K;
      switch (opt)
      {
      case 0:
         p.first = K;
         h.insert(p);
         i++;
         break;
      case 1:
         h.find(K);
         i++;
         break;
      case 2:
         h.erase(K);
         i++;
         break;
      default:
         break;
      }
   }
}