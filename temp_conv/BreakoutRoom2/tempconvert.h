#include <iostream>

using namespace std;

class TemperatureConverter
{
public:
    virtual double fromKelvin(double Kelvin) = 0;
    virtual double toKelvin(double Other) = 0;
    virtual bool isSupportingScale(string inputScale) = 0;
    bool isInTempStrings(string inputScale, list<string> outputScale);
    double getToKelvin(string temperatureScale);
    double getFromKelvin(string temperatureScale);
};

class CelsiusConverter : public TemperatureConverter
{
public:
    double fromKelvin(double Kelvin);
    double toKelvin(double Other);
    bool isSupportingScale(string inputScale);
};

class FahrenheitConverter : public TemperatureConverter
{
public:
    double fromKelvin(double Kelvin);
    double toKelvin(double Other);
    bool isSupportingScale(string inputScale);
};

class KelvinConverter : public TemperatureConverter
{
public:
    double fromKelvin(double Kelvin);
    double toKelvin(double Other);
    bool isSupportingScale(string inputScale);
};
