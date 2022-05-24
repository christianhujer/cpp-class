#include<iostream>
#include <stdlib.h>
#include <cassert>
#include <cmath>
#include <string.h> 

using namespace std;

bool isInList(const char *str, const char *strings[]) {
    for (; *strings != NULL; strings++)
        if (strcmp(str, *strings) == 0)
            return true;
    return false;
}

#if 0
bool isInList(const char *str, const char *strings[] ) {
    return *strings && (!strcmp(str, *strings) || isList(str, strings + 1));
}
#endif


bool celsiusIsScale(const char *str) {
    const char *celsiusStrings[] = { "C", "°C", "c", "Celsius", "celsius", NULL };
    return isInList(str, celsiusStrings);
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double celsiusFromKelvin(double kelvin) {
    return kelvin - 273.15;
}

bool fahrenheitIsScale(const char *str) {
    const char *fahrenheitStrings[] = { "F", "°F", "f", "Fahrenheit", "fahrenheit", NULL };
    return isInList(str, fahrenheitStrings);
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

double fahrenheitFromKelvin(double kelvin) {
    return kelvin * 9/5 - 459.67;
}

bool kelvinIsScale(const char *str) {
    const char *kelvinStrings[] = { "K", "k", "Kelvin", "kelvin", NULL };
    return isInList(str, kelvinStrings);
}

double kelvinToKelvin(double kelvin) {
    return kelvin;
}

double kelvinFromKelvin(double kelvin) {
    return kelvin;
}

struct TemperatureScale {
    bool (*isScale)(const char *str);
    double (*toKelvin)(double);
    double (*fromKelvin)(double);
};

struct TemperatureScale celsius = {
    celsiusIsScale,
    celsiusToKelvin,
    celsiusFromKelvin,
};

struct TemperatureScale fahrenheit = {
    fahrenheitIsScale,
    fahrenheitToKelvin,
    fahrenheitFromKelvin,
};

struct TemperatureScale kelvin = {
    kelvinIsScale,
    kelvinToKelvin,
    kelvinFromKelvin,
};

typedef double (*converter_t)(double);

converter_t toKelvin(char *temperatureScale) {
    struct TemperatureScale temperatureScales[] = {
        celsius, fahrenheit, kelvin
    };
    for (int i = 0; i < sizeof(temperatureScales) / sizeof(temperatureScales[0]); i++) {
        if (temperatureScales[i].isScale(temperatureScale)) {
            return temperatureScales[i].toKelvin;
        }
    }
    cerr << "error: Unsupported temperature scale: " << temperatureScale << endl;
    exit(EXIT_FAILURE);
}

converter_t fromKelvin(char *temperatureScale) {
    struct TemperatureScale temperatureScales[] = {
        celsius, fahrenheit, kelvin
    };
    for (int i = 0; i < sizeof(temperatureScales) / sizeof(temperatureScales[0]); i++) {
        if (temperatureScales[i].isScale(temperatureScale)) {
            return temperatureScales[i].fromKelvin;
        }
    }
    cerr << "error: Unsupported temperature scale: " << temperatureScale << endl;
    exit(EXIT_FAILURE);
}


void runTests() {
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

    assert(fabs(celsius.toKelvin(         0    ) -  273.15 ) < 0.001);
    assert(fabs(celsius.toKelvin(      -273.15 ) -    0    ) < 0.001);
    assert(fabs(fahrenheit.toKelvin(      0    ) -  255.372) < 0.001);
    assert(fabs(fahrenheit.toKelvin(   -459.67 ) -    0    ) < 0.001);

    assert(fabs(celsius.fromKelvin(         0    ) - -273.15 ) < 0.001);
    assert(fabs(celsius.fromKelvin(       273.15 ) -    0    ) < 0.001);
    assert(fabs(fahrenheit.fromKelvin(      0    ) - -459.67 ) < 0.001);
    assert(fabs(fahrenheit.fromKelvin(    255.372) -    0    ) < 0.001);
}

class temperatureConverter
{  
   public :
       double fromKelvin(double kelvin); 
       double toKelvin(double other);   
};

class kelvinConverter : public temperatureConverter
{
    public :
       bool kelvinIsScale(const char *str);
       double kelvinToKelvin(double kelvin);
       double kelvinFromKelvin(double kelvin);

};

class celsiusConverter : public temperatureConverter
{
    public :
        bool celsiusIsScale(const char *str);
        double celsiusToKelvin(double celsius);
        double celsiusFromKelvin(double kelvin)  
};

class fahrenheitConverter : public temperatureConverter
{
    public :
       bool fahrenheitIsScale(const char *str);
       double fahrenheitToKelvin(double fahrenheit);
       double fahrenheitFromKelvin(double kelvin);

};
int main(int argc, char *argv[]) {
    runTests();
    
    if (argc < 3) {
        cerr<< argv[0] << "error: Not enough arguments.\n Usage:" << argv[1] << "INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]..." << endl;
        return EXIT_FAILURE;
    }
    temperatureConverter Temp;
    converter_t toKelvin = Temp.toKelvin(argv[1]);
    converter_t fromKelvin =  Temp.fromKelvin(argv[2]);

    for (int i = 3; i < argc; i++) {
        double inputTemperature = atof(argv[i]);
        double temperature = toKelvin(inputTemperature);
        double outputTemperature = fromKelvin(temperature);

        printf("%f\n", outputTemperature);
    }

    return EXIT_SUCCESS;
}