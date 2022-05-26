#include <iostream>
#include "temp_convert.h"
#include <assert.h>
#include <string.h>
#include <cstring>
#include <list>
#include <iterator>

using namespace std;

bool isInScale(string inputScale, list<string> scaleList) {
    for (list<string>:: iterator scale = scaleList.begin(); scale != scaleList.end(); scale++) {
        if(inputScale == *scale)
            return true;
    }
    return false;
}


bool CelsiusConvertor :: isScale(string inputScale) {
    list <string> celsiusScales {"c", "C", "°C", "celsius", "Celsius"};
    return isInScale(inputScale, celsiusScales); 
}

double CelsiusConvertor :: fromKelvin(double kelvin) {
    return kelvin - 273.15;
}

double CelsiusConvertor :: toKelvin(double celsius) {
    return celsius + 273.15;
}


bool FahrenheitConvertor :: isScale(string inputScale) {
    list <string> celsiusScales {"f", "F", "°F", "fahrenheit", "Fahrenheit"};
    return isInScale(inputScale, celsiusScales); 
}

double FahrenheitConvertor :: fromKelvin(double kelvin) {
    return 1.8 * (kelvin - 273) + 32;
}

double FahrenheitConvertor :: toKelvin(double fahrenheit) {
    return (0.55555 * (fahrenheit - 32)) + 273.15;
}


bool KelvinConvertor :: isScale(string inputScale) {
    list <string> celsiusScales {"k", "K", "kelvin", "Kelvin"};
    return isInScale(inputScale, celsiusScales); 
}

double KelvinConvertor :: fromKelvin(double kelvin) {
    return kelvin;
}

double KelvinConvertor :: toKelvin(double kelvin) {
    return kelvin;
}


CelsiusConvertor celsius; KelvinConvertor kelvin; FahrenheitConvertor fahrenheit;
list <TemperatureConvertor*> scales {&celsius, &kelvin, &fahrenheit};

TemperatureConvertor* getScale(string inputScale) {
    list <TemperatureConvertor*> :: iterator scale;
    for (scale = scales.begin(); scale != scales.end(); scale++) {
        if ((*scale) -> isScale(inputScale))
            return *scale;
    }
    cerr << "error:Unsupported temprature scale." << inputScale << endl;
    exit(EXIT_FAILURE);
}

void runTest() {
    assert(celsius.isScale("C"));
    assert(celsius.isScale("°C"));
    assert(celsius.isScale("c"));
    assert(celsius.isScale("Celsius"));
    assert(celsius.isScale("celsius"));

    assert(fahrenheit.isScale("F"));
    assert(fahrenheit.isScale("°F"));
    assert(fahrenheit.isScale("f"));
    assert(fahrenheit.isScale("Fahrenheit"));
    assert(fahrenheit.isScale("fahrenheit"));

    assert(kelvin.isScale("K"));
    assert(kelvin.isScale("k"));
    assert(kelvin.isScale("Kelvin"));
    assert(kelvin.isScale("kelvin"));
}


int main(int argc, char* argv[]) {
    runTest();

    if (argc < 3) {
        cerr << argv[0] << ": error: Not enough arguments.\n"
        "Usage: temp_convert INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...";
        return EXIT_FAILURE;
    }
    
    TemperatureConvertor *inputScale, *outputScale;

    inputScale = getScale(argv[1]);
    outputScale = getScale(argv[2]);

    for (int i = 3; i < argc; i++) {
        double inputTemperature = atof(argv[i]);
        double temperatureInKelvin = inputScale -> toKelvin(inputTemperature);
        double outputTemperature = outputScale -> fromKelvin(temperatureInKelvin);
        cout << outputTemperature << endl;
    }

    return EXIT_SUCCESS;
}