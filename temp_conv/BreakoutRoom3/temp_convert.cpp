#include <iostream>
#include "temp_convert.h"
#include <assert.h>
#include <string.h>
#include <cstring>
#include <list>
#include <iterator>

using namespace std;

bool isInScale(string inputScale,list<string> scaleList) {
    for (list<string>:: iterator scale = scaleList.begin(); scale != scaleList.end(); scale++) {
        if(inputScale == *scale)
            return true;
    }
    return false;
}


bool CelsiusConvertor ::isScale(string inputScale) {
    list<string> celsiusScales{"c","C", "°C", "celsius", "Celsius"};
    return isInScale(inputScale,celsiusScales); 
}
double CelsiusConvertor ::fromKelvin(double kelvin)
{
    return kelvin - 273.15;
}

double CelsiusConvertor ::toKelvin(double celsius)
{
    return celsius + 273.15;
}


bool FahrenheitConvertor ::isScale(string inputScale) {
    list<string> celsiusScales{"f","F", "°F", "fahrenheit", "Fahrenheit"};
    return isInScale(inputScale,celsiusScales); 
}

double FahrenheitConvertor ::fromKelvin(double kelvin)
{
    return 1.8 * (kelvin - 273) + 32;
}

double FahrenheitConvertor ::toKelvin(double fahrenheit)
{
    return (0.55555 * (fahrenheit - 32)) + 273.15;
}


bool KelvinConvertor ::isScale(string inputScale) {
    list<string> celsiusScales{"k","K", "kelvin", "Kelvin"};
    return isInScale(inputScale,celsiusScales); 
}

double KelvinConvertor ::fromKelvin(double kelvin)
{
    return kelvin;
}

double KelvinConvertor ::toKelvin(double kelvin)
{
    return kelvin;
}
/*TemperatureConvertor TemperatureConvertor::getToScale(string inputScale){
    
}*/

int main()
{
    TemperatureConvertor *fromScale, *toScale;
    CelsiusConvertor celsius;
    toScale = &celsius;
    //toScale = getToScale("C");    
    assert(toScale->fromKelvin(0) == -273.15);
    assert(toScale->isScale("C") == true);
    return EXIT_SUCCESS;
}