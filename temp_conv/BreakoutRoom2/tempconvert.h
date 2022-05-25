#include <iostream>

using namespace std;

class TemperatureConverter
{
public:
    virtual double fromKelvin(double Kelvin) = 0;
    virtual double toKelvin(double Other) = 0;
    bool isInTempStrings(string inputScale, list<string> outputScale);
};

class CelsiusConverter : public TemperatureConverter
{
public:
    double fromKelvin(double Kelvin);
    double toKelvin(double Other);
    bool isCelsius(string inputScale);
};

class FahrenheitConverter : public TemperatureConverter
{
public:
    double fromKelvin(double Kelvin);
    double toKelvin(double Other);
    bool isFarhenheit(string inputScale);
};

class KelvinConverter : public TemperatureConverter
{
public:
    double fromKelvin(double Kelvin);
    double toKelvin(double Other);
    bool isKelvin(string inputScale);
};
