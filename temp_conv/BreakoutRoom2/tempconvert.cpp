#include <assert.h>
#include <iostream>
#include <list>
#include <string>
#include "tempconvert.h"

using namespace std;

bool TemperatureConverter ::isInTempStrings(string inputScale, list<string> outputScale)
{
    list<string>::iterator it;
    for (it = outputScale.begin(); it != outputScale.end(); it++)
    {
        if ((*it).compare(inputScale));
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

bool CelsiusConverter ::isCelsius(string inputScale)
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

bool FahrenheitConverter ::isFarhenheit(string inputScale)
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

bool KelvinConverter ::isKelvin(string inputScale)
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

    TemperatureConverter *temp;
    CelsiusConverter cels;
    temp = &cels;
    if (cels.isCelsius(argv[1]) == true)
    {
        cout << temp->fromKelvin(atof(argv[3])) << endl;
    }

    assert(temp->fromKelvin(0) == -273.15);
    return EXIT_SUCCESS;
}