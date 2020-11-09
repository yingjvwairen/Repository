#include <iostream>

#include <exception>

#include <stdexcept>

using namespace std;

class ConWithException

{

public:
    ConWithException() : _pBuf(NULL)

    {

        _pBuf = new int[100];

        throw std::runtime_error("Exception in Constructor!");
    }

    ~ConWithException()

    {

        cout << "Destructor!" << endl;

        if (_pBuf != NULL)

        {

            cout << "Delete buffer..." << endl;
            ;

            delete[] _pBuf;

            _pBuf = NULL;
        }
    }

private:
    int *_pBuf;
};

int main(int argc, char **argv)

{

    ConWithException *cwe = NULL;

    try

    {

        cwe = new ConWithException;
    }

    catch (std::runtime_error &e)

    {

        cout << e.what() << endl;
    }

    delete cwe;

    return 0;
}