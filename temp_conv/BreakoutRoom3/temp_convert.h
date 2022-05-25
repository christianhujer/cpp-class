#include <iostream>

using namespace std;

class TemperatureConvertor
{
public:
    virtual bool isScale(string inputScale) = 0;
    virtual double fromKelvin(double kelvin) = 0;
    virtual double toKelvin(double other) = 0;
    //TemperatureConvertor *getScale(string scale);
};

class CelsiusConvertor : public TemperatureConvertor
{
public:
    bool isScale(string scale);
    double fromKelvin(double kelvin);
    double toKelvin(double celsius);
};

class FahrenheitConvertor : public TemperatureConvertor
{
public:
    bool isScale(string scale);
    double fromKelvin(double kelvin);
    double toKelvin(double other);
};

class KelvinConvertor : public TemperatureConvertor
{
public:
    bool isScale(string scale);
    double fromKelvin(double kelvin);
    double toKelvin(double other);
};