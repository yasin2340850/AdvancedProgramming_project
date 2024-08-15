#include <iostream>
#include <ctime>
#include "myvector.h"
#include "myshape.h"
#include <chrono>

int main()
{
    const int numShapes = 1000;            // tedade shape ha baraye sakhtan da hafeze
    const int dataSize = 10 * 1024 * 1024; // size har shape (10 Mega Byte)
    vector<Shape> shapes;                  // estefade az vectori ke enveshtim

    // sakhtan va insert 100 shapes jadid ba hajme zyad
    for (int i = 0; i < numShapes; ++i)
    {
        shapes.insert(i, Shape(dataSize));
    }

    // mohasebeye zamane insert ha
    std::clock_t startInsert = std::clock();
    shapes.insert(0, Shape(dataSize)); // insert shape dar avale
    std::clock_t endInsert = std::clock();

    // mhasebeye zamane insert ha
    double insertTime = endInsert - startInsert;

    // mohasebeye zamane remove ha
    std::clock_t startRemove = std::clock();
    shapes.remove(shapes.size() - 1); // remove az akhar
    std::clock_t endRemove = std::clock();

    // mohasebeye zamane remove ha
    double removeTime = endRemove - startRemove;

    std::cout << "\nInsert time: " << insertTime << "\n";
    std::cout << "Remove time: " << removeTime << "\n";

    return 0;
}
