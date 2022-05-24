#include <iostream>
#include <cassert>

using namespace std;

class TemperatureConverter
{
    public:
    virtual double fromKelvin(double Kelvin) = 0;
    virtual double toKelvin(double Other) = 0;
};

class CelsiusConverter : public TemperatureConverter
{
    public:
    double fromKelvin(double Kelvin)
    {
        return Kelvin - 273.15;
    }
    double toKelvin(double Other)
    {
        return Other + 273.15;
    }
};

class FahrenheitConverter : public TemperatureConverter
{
    double fromKelvin(double Kelvin)
    {
        return Kelvin * 9/5 - 459.67;
    }
    double toKelvin(double Other)
    {
        return (Other + 459.67) * 5/9;
    }
};

class KelvinConverter : public TemperatureConverter
{
    double fromKelvin(double Kelvin)
    {
        return Kelvin;
    }
    double toKelvin(double Other)
    {
        return Other;
    }
};


int main(int argc, char *argv[])
{
   /* if (argc <= 3)
    {
        cout<< argv[0] << "error: Not enough arguments.\nUsage:"<< argv[0] <<"INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]..." << endl;
        return EXIT_FAILURE;
    } */

    CelsiusConverter celsius;

    assert(celsius.fromKelvin(0) == -273.15);

    return EXIT_SUCCESS;

}