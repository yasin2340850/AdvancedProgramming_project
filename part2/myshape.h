
class Shape
{
public:
    // sazandeye pish farz
    Shape()
        : volume(1), density(1), surface(1)
    {
    }

    // sazandeye parametr dar
    Shape(double volume, double density, double surface)
        : volume(volume), density(density), surface(surface)
    {
    }

    // Getter volume
    double getVolume()
    {
        return volume;
    }

    // Setter volume
    void setVolume(double volume)
    {
        this->volume = volume;
    }

    // Getter density
    double getDensity()
    {
        return density;
    }

    // Setteror density
    void setDensity(double density)
    {
        this->density = density;
    }

    // Getter surface
    double getSurface()
    {
        return surface;
    }

    // Setter surface
    void setSurface(double surface)
    {
        this->surface = surface;
    }

private:
    double volume;
    double density;
    double surface;
};