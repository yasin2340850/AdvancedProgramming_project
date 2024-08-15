#include <iostream>
#include "mydevice.h"

int main()
{
    // shape haye sade
    Shape seat(1.0, 2.0, 3.0); // Volume, Density, Surface
    Shape fuelFilter(0.5, 1.0, 1.5);
    Shape wheel(0.4, 2.5, 1.2);
    Shape dashboard(1.2, 1.8, 2.5);
    Shape body(10.0, 2.0, 20.0); // badaneh

    // shape haye pichideh
    Shape engine(5.0, 7.0, 9.0);
    Shape gearbox(3.0, 5.0, 6.0);
    Shape transmission(4.0, 3.0, 5.0); // gear box
    Shape braking(2.0, 4.0, 3.0);      // tormoz

    // mashin
    Device car;

    // ezafe kardane shape haye sade be mashin
    car.AddShape(seat);
    car.AddShape(fuelFilter);
    car.AddShape(wheel);
    car.AddShape(dashboard);
    car.AddShape(body);

    // sakhtane device motor
    Device engineDevice;
    engineDevice.AddShape(engine);

    // sakhatane device jabe dandeh
    Device gearboxDevice;
    gearboxDevice.AddShape(gearbox);

    // sakhtane enteghale ghodrat
    Device transmissionDevice;
    transmissionDevice.AddShape(transmission);

    // sakhatene system tormoz
    Device brakingDevice;
    brakingDevice.AddShape(braking);

    // azafe kardane device haye pichide be mashin
    car.AddDevice(engineDevice);
    car.AddDevice(gearboxDevice);
    car.AddDevice(transmissionDevice);
    car.AddDevice(brakingDevice);

    // mohasebeye total volume, surface va mass
    double totalVolume = car.EvalVolume();
    double totalSurface = car.EvalSurface();
    double totalMass = car.EvalMass();

    // chape khorooji
    std::cout << std::endl
              << "Total Volume: " << totalVolume << std::endl;
    std::cout << "Total Surface: " << totalSurface << std::endl;
    std::cout << "Total Mass: " << totalMass << std::endl;

    return 0;
}
