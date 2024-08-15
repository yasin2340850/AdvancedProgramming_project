
class Shape
{
public:
    Shape(int size = 1) : size(size)
    {
        // takhsis hafeze be arraye
        data = new char[size];
    }

    // ~Shape()
    // {
    //     delete[] data; // Free the memory block
    // }

private:
    char *data;
    int size;
};