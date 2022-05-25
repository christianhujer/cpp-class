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

double FahrenheitConvertor :: toKelvin(double fahrenheit)
{
    return (0.55555 * (fahrenheit - 32)) + 273.15;
}


bool KelvinConvertor :: isScale(string inputScale) {
    list<string> celsiusScales{"k","K", "kelvin", "Kelvin"};
    return isInScale(inputScale,celsiusScales); 
}

double KelvinConvertor :: fromKelvin(double kelvin)
{
    return kelvin;
}

double KelvinConvertor :: toKelvin(double kelvin)
{
    return kelvin;
}
TemperatureConvertor* getScale(string inputScale){
    CelsiusConvertor celsius;
    KelvinConvertor kelvin;
    FahrenheitConvertor fahrenheit;
    TemperatureConvertor *temp;

    if (celsius.isScale(inputScale)) {
        temp = &celsius;
    }

    else if (kelvin.isScale(inputScale)) {
        temp = &kelvin;
    }

    else if (fahrenheit.isScale(inputScale)) {
        temp = &fahrenheit;
    }

    else {
        cerr << "error:Unsupported temprature scale." << inputScale << endl;
        abort();
    }
    return temp;
}

/*void runTest(){
    assert(toScale->fromKelvin(0) == -273.15);
    assert(toScale->isScale("C"));
}*/

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cerr << argv[0] << ": error: Not enough arguments.\n"
        "Usage: temp_convert INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...";
    }
    TemperatureConvertor *inputScale, *outputScale;
    CelsiusConvertor celsius;
    inputScale = getScale(argv[1]);
    outputScale = getScale(argv[2]);
    for (int i = 3; i < argc; i++) {
    int inputTemperature = atof(argv[i]);
    int tempInKelvin = inputScale->toKelvin(inputTemperature);
    int outputTemperature =outputScale->fromKelvin(tempInKelvin);
    cout << outputTemperature << endl;
    }
    return EXIT_SUCCESS;
}