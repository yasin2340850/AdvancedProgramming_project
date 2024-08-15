#include "myvector.h"
#include "myshape.h"

class Device
{
public:
    Device()
    {
    }

    double EvalVolume();
    double EvalSurface();
    double EvalDensity();
    double EvalMass();

    void AddDevice(Device device);
    void AddShape(Shape shape);

private:
    vector<Device> devices;
    vector<Shape> shapes;
};

double Device::EvalVolume()
{
    double totalVolume = 0;
    for (const auto &shape : shapes)
    {
        totalVolume += shape->getVolume();
    }
    return totalVolume;
}

double Device::EvalSurface()
{
    double totalSurface = 0;
    for (const auto &shape : shapes)
    {
        totalSurface += shape->getSurface();
    }
    return totalSurface;
}

double Device::EvalDensity()
{
    double totalDensity = 0;
    for (const auto &shape : shapes)
    {
        totalDensity += shape->getDensity();
    }
    return totalDensity;
}

double Device::EvalMass()
{
    double totalMass = 0;
    for (const auto &shape : shapes)
    {
        // jerm yani chegali dar hajm
        totalMass += (shape->getDensity() * shape->getVolume());
    }
    return totalMass;
}

void Device::AddDevice(Device device)
{
    devices.pushBack(device);
}

void Device::AddShape(Shape shape)
{
    shapes.pushBack(shape);
}
