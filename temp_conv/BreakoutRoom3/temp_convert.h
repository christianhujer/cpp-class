#include <iostream>

using namespace std;

class TemperatureConvertor
{
public:
    virtual double fromKelvin(double kelvin) = 0;
    virtual double toKelvin(double other) = 0;
};

class CelsiusConvertor : public TemperatureConvertor
{
public:
    double fromKelvin(double kelvin);
    double toKelvin(double celsius);
};

class FahrenheitConvertor : public TemperatureConvertor
{
public:
    double fromKelvin(double kelvin);
    double toKelvin(double other);
};

class KelvinConvertor : public TemperatureConvertor
{
public:
    double fromKelvin(double kelvin);
    double toKelvin(double other);
};