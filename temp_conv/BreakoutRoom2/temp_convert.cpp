#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include "temp_convert.h"

using namespace std;

CelsiusConverter cels1;
FahrenheitConverter fah1;
KelvinConverter kel1;

TemperatureConverter *getToKelvin(string temperatureScale)
{
    TemperatureConverter *temperatureConvertObj;

    if (cels1.isSupportingScale(temperatureScale))
    {
        temperatureConvertObj = &cels1;
    }
    else if (fah1.isSupportingScale(temperatureScale))
    {
        temperatureConvertObj = &fah1;
    }
    else if (kel1.isSupportingScale(temperatureScale))
    {
        temperatureConvertObj = &kel1;
    }
    else
    {
        cout << "error:Unsupported temprature scale." << temperatureScale << endl;
        abort();
    }
    return temperatureConvertObj;
}

bool TemperatureConverter ::isInTempStrings(string inputScale, list<string> outputScale)
{
    list<string>::iterator it;
    for (it = outputScale.begin(); it != outputScale.end(); it++)
    {
        if (inputScale == *it)
        {
            return true;
        }
    }
    return false;
}

double CelsiusConverter ::fromKelvin(double Kelvin)
{
    return Kelvin - 273.15;
}
double CelsiusConverter ::toKelvin(double Other)
{
    return Other + 273.15;
}

bool CelsiusConverter ::isSupportingScale(string inputScale)
{
    list<string> celsiusstrings = {"°C", "c", "C", "celsius", "Celsius"};
    return isInTempStrings(inputScale, celsiusstrings);
}

double FahrenheitConverter ::fromKelvin(double Kelvin)
{
    return Kelvin * 9 / 5 - 459.67;
}
double FahrenheitConverter ::toKelvin(double Other)
{
    return (Other + 459.67) * 5 / 9;
}

bool FahrenheitConverter ::isSupportingScale(string inputScale)
{
    list<string> fahrenheitStrings = {"F", "°F", "f", "Fahrenheit", "fahrenheit"};
    return isInTempStrings(inputScale, fahrenheitStrings);
}

double KelvinConverter ::fromKelvin(double Kelvin)
{
    return Kelvin;
}
double KelvinConverter ::toKelvin(double Other)
{
    return Other;
}

bool KelvinConverter ::isSupportingScale(string inputScale)
{
    list<string> kelvinStrings = {"k", "K", "kelvin", "Kelvin"};
    return isInTempStrings(inputScale, kelvinStrings);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << argv[0] << "error: Not enough arguments.\nUsage:" << argv[0] << "INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]..." << endl;
        return EXIT_FAILURE;
    }
    TemperatureConverter *temp1, *temp2;

    temp1 = getToKelvin(argv[1]);
    temp2 = getToKelvin(argv[2]);
    for (int i = 3; i <= argc; i++)
    {
        double inputTemperature = atof(argv[i]);
        double temperature = temp1->toKelvin(inputTemperature);
        double outputTemperature = temp2->fromKelvin(temperature);
        cout << outputTemperature << endl;
    }
    return EXIT_SUCCESS;
}