#include <iostream>
#include "temp_convert.h"
#include <assert.h>

using namespace std;

double CelsiusConvertor ::fromKelvin(double kelvin)
{
    return kelvin - 273.15;
}

double CelsiusConvertor ::toKelvin(double celsius)
{
    return celsius + 273.15;
}

double FahrenheitConvertor ::fromKelvin(double kelvin)
{
    return 1.8 * (kelvin - 273) + 32;
}

double FahrenheitConvertor ::toKelvin(double fahrenheit)
{
    return (0.55555 * (fahrenheit - 32)) + 273.15;
}

double KelvinConvertor ::fromKelvin(double kelvin)
{
    return kelvin;
}

double KelvinConvertor ::toKelvin(double kelvin)
{
    return kelvin;
}

int main()
{
    TemperatureConvertor *temp;
    CelsiusConvertor cels;
    temp = &cels;
    assert(temp->fromKelvin(0) == -273.15);
    cout << temp->fromKelvin(0) << endl;
    return EXIT_SUCCESS;
}