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
        if (inputScale.compare((*it)) == 0); // 1.need to check documentation (cleared)
        {
            return true;
        }
    }
    return false;
}

double TemperatureConverter ::getToKelvin(string temperatureScale) //  rgv[1] = celsius
{
   // return isSupportingScale(temperatureScale); // celcius 
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

bool FahrenheitConverter ::isSupportingScale(string inputScale)   // need to change function name make a virtual function
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

    TemperatureConverter *temp;
    CelsiusConverter cels;
    FahrenheitConverter temp1;
    assert(temp->fromKelvin(0) == -273.15);
    if (temp->getToKelvin((string)argv[1]) == true)
    {
        for (int i = 3; i < argc; i++)  // C C 0 10 30
        {
            cout << temp->fromKelvin(atof(argv[i])) << endl;
        }
    }
    return EXIT_SUCCESS;
}