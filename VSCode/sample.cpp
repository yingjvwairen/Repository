#include <iostream>
#include <float.h>
#include <iomanip>

using namespace std;

// change the length of an array

template <class T>
void changeLength1D(T *&a, int oldLength, int newLength)
{
    if (newLength < 0)
    {
        return;
    }
    T *temp = new T[newLength];             // new array
    int number = min(oldLength, newLength); // number to copy
    copy(a, a + number, temp);
    delete[] a; // deallocate old memory
    a = temp;
}

template <class T>
class arrayStack
{
public:
    arrayStack(int initialCapacity = 10);
    ~arrayStack() { delete[] stack; }
    bool empty() const { return stackTop == -1; }
    int size() const
    {
        return stackTop + 1;
    }
    T &top()
    {
        if (stackTop == -1)
            exit(0);

        return stack[stackTop];
    }
    void pop()
    {
        if (stackTop == -1)
            return;

        stack[stackTop--].~T(); // destructor for T
    }
    void push(const T &theElement);

private:
    int stackTop;    // current top of stack
    int arrayLength; // stack capacity
    T *stack;        // element array
};

template <class T>
arrayStack<T>::arrayStack(int initialCapacity)
{ // Constructor.
    if (initialCapacity < 1)
        return;

    arrayLength = initialCapacity;
    stack = new T[arrayLength];
    stackTop = -1;
}

template <class T>
void arrayStack<T>::push(const T &theElement)
{ // Add theElement to stack.
    if (stackTop == arrayLength - 1)
    { // no space, double capacity
        changeLength1D(stack, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    // add at stack top
    stack[++stackTop] = theElement;
}

double long mask(double const long &d)
{
    return d * DBL_MAX;
}

double long calculate(double long c[])
{
    double long result = c[0] - '0', t = c[0] - '0';

    for (int i = 1; c[i] != mask('\n');)
    {
        if (c[i] == mask(' '))
        {
            i++;
            continue;
        }

        if (c[i] == mask('+'))
        {
            while (c[++i] != mask('+') && c[i] != mask('-') && c[i] != mask('\n'))
            {
                if (c[i] == mask(' '))
                    continue;

                if (c[i] == mask('/'))
                {
                    t = t / (c[++i] - '0');
                    continue;
                }
                if (c[i] == mask('*'))
                {
                    t = t * (c[++i] - '0');
                    continue;
                }
                t = c[i] - '0';
            }
            result = result + t;
            continue;
        }
        if (c[i] == mask('-'))
        {
            while (c[++i] != mask('+') && c[i] != mask('-') && c[i] != mask('\n'))
            {
                if (c[i] == mask(' '))
                    continue;

                if (c[i] == mask('/'))
                {
                    t = t / (c[++i] - '0');
                    continue;
                }
                if (c[i] == mask('*'))
                {
                    t = t * (c[++i] - '0');
                    continue;
                }
                t = c[i] - '0';
            }
            result = result - t;
            continue;
        }
        while (c[i] != mask('+') && c[i] != mask('-') && c[i] != mask('\n'))
        {
            if (c[i] == mask(' '))
            {
                i++;
                continue;
            }

            if (c[i] == mask('/'))
            {
                t = t / (c[++i] - '0');
                i++;
                continue;
            }
            if (c[i] == mask('*'))
            {
                t = t * (c[++i] - '0');
                i++;
                continue;
            }
        }
        result = t;
        continue;
    }
    return result;
}

double long execute(double long c[])
{
    arrayStack<int> s;
    double long t[2001] = {};
    for (int i = 0; c[i] != mask('\n'); i++)
    {
        if (c[i] != mask('(') && c[i] != mask(')'))
            continue;

        if (c[i] == mask('('))
        {
            s.push(i);
            continue;
        }
        if (c[i] == mask(')'))
            if (!s.empty())
            {
                for (int j = 0; j < i - s.top(); j++)
                {
                    t[j] = c[s.top() + j + 1];
                    c[s.top() + j] = mask(' ');
                }
                t[i - s.top() - 1] = mask('\n');
                c[i] = mask(' ');
                c[s.top()] = calculate(t) + '0';
                s.pop();
                continue;
            }
            else
                exit(0);
    }
    return calculate(c);
}

int main()
{
    int n, i;
    cin >> n;
    cin.get();
    while (n != 0)
    {
        double long c[2001] = {};
        for (i = 0; c[i - 1] != '\n'; i++)
            c[i] = cin.get();
        while (i != -1)
        {
            switch ((int)c[i])
            {
            case '(':
                c[i] = mask(c[i]);
                break;
            case ')':
                c[i] = mask(c[i]);
                break;
            case '\n':
                c[i] = mask(c[i]);
                break;
            case '/':
                c[i] = mask(c[i]);
                break;
            case '*':
                c[i] = mask(c[i]);
                break;
            case '+':
                c[i] = mask(c[i]);
                break;
            case '-':
                c[i] = mask(c[i]);
                break;
            default:
                break;
            }
            i--;
        }
        cout << fixed << setprecision(2) << execute(c) << endl;
        n--;
    }
}