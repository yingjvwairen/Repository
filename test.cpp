// linked binary tree using nodes of type binaryTreeNode
// derives from the abstract class binaryTree

#include <iostream>
// abstract class binary tree
// abstract data type specification for binary trees
// all methods are pure virtual functions
// T is node type

using namespace std;

#include <functional>

// circular array implementation of a queue
// derives from the ADT queue

#include <sstream>

template <class T>
class arrayQueue
{
public:
   arrayQueue(int initialCapacity = 10);
   ~arrayQueue() { delete[] queue; }
   bool empty() const { return theFront == theBack; }
   int size() const
   {
      return (theBack - theFront + arrayLength) % arrayLength;
   }
   T &front()
   { // return front element
      if (theFront == theBack)
         throw -1;
      return queue[(theFront + 1) % arrayLength];
   }
   T &back()
   { // return theBack element
      if (theFront == theBack)
         throw -1;
      return queue[theBack];
   }
   void pop()
   { // remove theFront element
      if (theFront == theBack)
         throw -1;
      theFront = (theFront + 1) % arrayLength;
      queue[theFront].~T(); // destructor for T
   }
   void push(const T &theElement);

private:
   int theFront;    // 1 counterclockwise from theFront element
   int theBack;     // position of theBack element
   int arrayLength; // queue capacity
   T *queue;        // element array
};

template <class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{ // Constructor.
   if (initialCapacity < 1)
   {
      ostringstream s;
      s << "Initial capacity = " << initialCapacity << " Must be > 0";
      throw -1;
   }
   arrayLength = initialCapacity;
   queue = new T[arrayLength];
   theFront = 0;
   theBack = 0;
}

template <class T>
void arrayQueue<T>::push(const T &theElement)
{ // Add theElement to queue.

   // increase array length if necessary
   if ((theBack + 1) % arrayLength == theFront)
   { // double array length
      // allocate a new array
      T *newQueue = new T[2 * arrayLength];

      // copy elements into new array
      int start = (theFront + 1) % arrayLength;
      if (start < 2)
         // no wrap around
         copy(queue + start, queue + start + arrayLength - 1, newQueue);
      else
      { // queue wraps around
         copy(queue + start, queue + arrayLength, newQueue);
         copy(queue, queue + theBack + 1, newQueue + arrayLength - start);
      }

      // switch to newQueue and set theFront and theBack
      theFront = 2 * arrayLength - 1;
      theBack = arrayLength - 2; // queue size arrayLength - 1
      arrayLength *= 2;
      queue = newQueue;
   }

   // put theElement at the theBack of the queue
   theBack = (theBack + 1) % arrayLength;
   queue[theBack] = theElement;
}

template <class T>
struct binaryTreeNode
{
   T element;
   binaryTreeNode<T> *leftChild, // left subtree
       *rightChild;              // right subtree

   binaryTreeNode() { leftChild = rightChild = NULL; }
   binaryTreeNode(const T &theElement) : element(theElement)
   {
      leftChild = rightChild = NULL;
   }
   binaryTreeNode(const T &theElement,
                  binaryTreeNode *theLeftChild,
                  binaryTreeNode *theRightChild)
       : element(theElement)
   {
      leftChild = theLeftChild;
      rightChild = theRightChild;
   }
};

struct booster
{
   int degradeToLeaf,     // degradation to leaf
       degradeFromParent; // degradation from parent
   bool boosterHere;      // true iff booster here

   void output(ostream &out) const
   {
      out << boosterHere << ' ' << degradeToLeaf << ' '
          << degradeFromParent << ' ';
   }
};

// overload <<
ostream &operator<<(ostream &out, booster x)
{
   x.output(out);
   return out;
}

template <class E>
class linkedBinaryTree
{
public:
   linkedBinaryTree()
   {
      root = NULL;
      treeSize = 0;
   }
   ~linkedBinaryTree() { erase(); };
   bool empty() const { return treeSize == 0; }
   int size() const { return treeSize; }
   E *rootElement() const;
   void makeTree(const E &element,
                 linkedBinaryTree<E> &, linkedBinaryTree<E> &);
   linkedBinaryTree<E> &removeLeftSubtree();
   linkedBinaryTree<E> &removeRightSubtree();
   void preOrder(void (*theVisit)(binaryTreeNode<E> *))
   // parameter is a pointer to a function whose return
   // type is void and has a single argument of type T*
   {
      visit = theVisit;
      preOrder(root);
   }
   void inOrder(void (*theVisit)(binaryTreeNode<E> *))
   {
      visit = theVisit;
      inOrder(root);
   }
   void postOrder(void (*theVisit)(binaryTreeNode<E> *))
   {
      visit = theVisit;
      postOrder(root);
   }
   void levelOrder(void (*)(binaryTreeNode<E> *));
   void preOrderOutput()
   {
      preOrder(output);
      cout << endl;
   }
   void inOrderOutput()
   {
      inOrder(output);
      cout << endl;
   }
   void postOrderOutput()
   {
      postOrder(output);
      cout << endl;
   }
   void levelOrderOutput()
   {
      levelOrder(output);
      cout << endl;
   }
   void erase()
   {
      postOrder(dispose);
      root = NULL;
      treeSize = 0;
   }
   int height() const { return height(root); }

protected:
   binaryTreeNode<E> *root;                   // pointer to root
   int treeSize;                              // number of nodes in tree
   static void (*visit)(binaryTreeNode<E> *); // visit function
   static int count;                          // used to count nodes in a subtree
   static void preOrder(binaryTreeNode<E> *t);
   static void inOrder(binaryTreeNode<E> *t);
   static void postOrder(binaryTreeNode<E> *t);
   static void countNodes(binaryTreeNode<E> *t)
   {
      visit = addToCount;
      count = 0;
      preOrder(t);
   }
   static void dispose(binaryTreeNode<E> *t) { delete t; }
   static void output(binaryTreeNode<E> *t)
   {
      cout << t->element << ' ';
   }
   static void addToCount(binaryTreeNode<E> *t)
   {
      count++;
   }
   static int height(binaryTreeNode<E> *t);
};
// the following should work but gives an internal compiler error
// template <class E> void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E>*);
// so the explicit declarations that follow are used for our purpose instead
template <>
void (*linkedBinaryTree<int>::visit)(binaryTreeNode<int> *);
template <>
void (*linkedBinaryTree<booster>::visit)(binaryTreeNode<booster> *);
template <>
void (*linkedBinaryTree<pair<int, int>>::visit)(binaryTreeNode<pair<int, int>> *);
template <>
void (*linkedBinaryTree<pair<const int, char>>::visit)(binaryTreeNode<pair<const int, char>> *);
template <>
void (*linkedBinaryTree<pair<const int, int>>::visit)(binaryTreeNode<pair<const int, int>> *);

template <class E>
E *linkedBinaryTree<E>::rootElement() const
{ // Return NULL if no root. Otherwise, return pointer to root element.
   if (treeSize == 0)
      return NULL; // no root
   else
      return &root->element;
}

template <class E>
void linkedBinaryTree<E>::makeTree(const E &element,
                                   linkedBinaryTree<E> &left, linkedBinaryTree<E> &right)
{ // Combine left, right, and element to make new tree.
   // left, right, and this must be different trees.
   // create combined tree
   root = new binaryTreeNode<E>(element, left.root, right.root);
   treeSize = left.treeSize + right.treeSize + 1;

   // deny access from trees left and right
   left.root = right.root = NULL;
   left.treeSize = right.treeSize = 0;
}

template <class E>
linkedBinaryTree<E> &linkedBinaryTree<E>::removeLeftSubtree()
{ // Remove and return the left subtree.
   // check if empty
   if (treeSize == 0)
      throw -1;

   // detach left subtree and save in leftSubtree
   linkedBinaryTree<E> leftSubtree;
   leftSubtree.root = root->leftChild;
   count = 0;
   leftSubtree.treeSize = countNodes(leftSubtree.root);
   root->leftChild = NULL;
   treeSize -= leftSubtree.treeSize;

   return leftSubtree;
}

template <class E>
linkedBinaryTree<E> &linkedBinaryTree<E>::removeRightSubtree()
{ // Remove and return the right subtree.
   // check if empty
   if (treeSize == 0)
      throw -1;

   // detach right subtree and save in rightSubtree
   linkedBinaryTree<E> rightSubtree;
   rightSubtree.root = root->rightChild;
   count = 0;
   rightSubtree.treeSize = countNodes(rightSubtree.root);
   root->rightChild = NULL;
   treeSize -= rightSubtree.treeSize;

   return rightSubtree;
}

template <class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{ // Preorder traversal.
   if (t != NULL)
   {
      linkedBinaryTree<E>::visit(t);
      preOrder(t->leftChild);
      preOrder(t->rightChild);
   }
}

template <class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t)
{ // Inorder traversal.
   if (t != NULL)
   {
      inOrder(t->leftChild);
      linkedBinaryTree<E>::visit(t);
      inOrder(t->rightChild);
   }
}

template <class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t)
{ // Postorder traversal.
   if (t != NULL)
   {
      postOrder(t->leftChild);
      postOrder(t->rightChild);
      linkedBinaryTree<E>::visit(t);
   }
}

template <class E>
void linkedBinaryTree<E>::levelOrder(void (*theVisit)(binaryTreeNode<E> *))
{ // Level-order traversal.
   arrayQueue<binaryTreeNode<E> *> q;
   binaryTreeNode<E> *t = root;
   while (t != NULL)
   {
      theVisit(t); // visit t

      // put t's children on queue
      if (t->leftChild != NULL)
         q.push(t->leftChild);
      if (t->rightChild != NULL)
         q.push(t->rightChild);

      // get next node to visit
      try
      {
         t = q.front();
      }
      catch (int)
      {
         return;
      }
      q.pop();
   }
}

template <class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t)
{ // Return height of tree rooted at *t.
   if (t == NULL)
      return 0;                    // empty tree
   int hl = height(t->leftChild);  // height of left
   int hr = height(t->rightChild); // height of right
   if (hl > hr)
      return ++hl;
   else
      return ++hr;
}
int main()
{
}