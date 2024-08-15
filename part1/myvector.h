#include <iostream>
#include <ctime>

template <typename T>
class vector
{
public:
    vector();
    vector(int _N, T _Val);
    ~vector();

    T operator[](int i);

    // tabe baraye ezafe kardan yek element dar index moshakhas
    void insert(int i, const T &value);

    // tabe baraye hazf kardan yek element dar index moshakhas
    void remove(int i);

    void pushBack(const T &value);

    void resize(int newSize);
    int size() const { return N; }

protected:
    T **data;
    int N;
};

template <typename T>
vector<T>::vector() : N(0), data(nullptr) {}

template <typename T>
vector<T>::vector(int _N, T _Val) : N(_N)
{
    data = new T *[N];
    for (int i{0}; i < N; i++)
    {
        data[i] = new T(_Val);
    }
}

template <typename T>
vector<T>::~vector()
{
    for (int i{0}; i < N; i++)
    {
        delete data[i];
    }
    delete[] data;
}

template <typename T>
T vector<T>::operator[](int i)
{
    try
    {
        if (i >= 0 && i < N)
        {
            return *data[i];
        }
        else
        {
            throw(i);
        }
    }
    catch (int i)
    {
        std::cout << "out of range, try to access " << i << " out of " << N << "\n";
        exit(-1);
    }
}

template <typename T>
void vector<T>::resize(int newSize)
{
    T **temp = new T *[newSize];

    int minSize = (newSize < N) ? newSize : N;

    for (int i{0}; i < minSize; i++)
    {
        temp[i] = data[i];
    }

    // tameme eleman haye jadid ra meghrad avaliye bede
    for (int i = minSize; i < newSize; i++)
    {
        temp[i] = new T(); // takhsis hafeze jadid
    }

    delete[] data;
    data = temp;
    N = newSize;
}

// tabe baraye ezafe kardan yek element dar index moshakhas
template <typename T>
void vector<T>::insert(int i, const T &value)
{
    // check mikonim ke index dorost bashad
    if (i < 0 || i > N)
    {
        // chap error
        std::cout << "Index out of range, cannot insert at " << i << "\n";
        return;
    }

    // resize kardan array baraye jaye element jadid
    resize(N + 1);

    // hame element ha ra yek khane be jelo mibariam ta jaye khali beshe
    for (int j = N - 1; j > i; --j)
    {
        *data[j] = *data[j - 1];
    }

    // meghdar jadid ra be index moshakhas midahim
    data[i] = new T(value);
}

template <typename T>
void vector<T>::remove(int i) // tabe baraye hazf kardan yek element dar index moshakhas
{
    if (i < 0 || i >= N) // check mikonim ke index dorost bashad
    {
        std::cout << "Index out of range, cannot remove at " << i << "\n"; // Chap error
        return;
    }

    delete data[i]; // pak kardan element moshakhas az hafeze

    for (int j = i; j < N - 1; ++j) // hame element ha ra yek khane be aghab mibariam
    {
        data[j] = data[j + 1];
    }

    resize(N - 1); // resize kardan array ba andaze jadid
}

template <typename T>
void vector<T>::pushBack(const T &value)
{
    insert(N - 1, value);
}
