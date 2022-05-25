#include<iostream>
#include<cassert>
#include <string.h> 

using namespace std;

class TemperatureConverter
{  
   public :
       virtual double fromKelvin(double kelvin) = 0;
       virtual double toKelvin(double other) = 0;
};

class CelsiusConverter : public TemperatureConverter {
public:
    double fromKelvin(double kelvin)
    {
        return kelvin - 273.15;
    }
    double toKelvin(double other)
    {
        return other + 273.15;
    }
};

class FahrenheitConverter : public TemperatureConverter {
public:
    double fromKelvin(double kelvin)
    {
        return kelvin * 9 / 5 - 459.67;
    }
    double toKelvin(double other)
    {
        return (other + 459.67) * 5 / 9;
    }
};

class KelvinConverter : public TemperatureConverter {
public:
    double fromKelvin(double kelvin)
    {
        return kelvin;
    }
    double toKelvin(double other)
    {
        return other;
    }
};

void runtest(void)
{
    TemperatureConverter* Temp;
    CelsiusConverter celsius;
    FahrenheitConverter farhenheit;
    KelvinConverter kelvin;
    Temp = &celsius;
    assert(Temp->fromKelvin(0) == -273.15);
    assert(Temp->toKelvin(0) == 273.15);
    Temp = &farhenheit;
    assert(Temp->fromKelvin(0) == -459.67);
    assert((Temp->toKelvin(0)) - 255.372<0.001);
    Temp = &kelvin;
    assert(Temp->fromKelvin(0) == 0);
    assert(Temp->toKelvin(0) == 0);
}

bool isInList(const char* str, const char* strings[]) {
    for (; *strings != NULL; strings++)
        if (strcmp(str, *strings) == 0)
            return true;
    return false;
}

bool celsiusIsScale(const char* str) {
    const char* celsiusStrings[] = { "C", "°C", "c", "Celsius", "celsius", NULL };
    return isInList(str, celsiusStrings);
}

bool fahrenheitIsScale(const char* str) {
    const char* fahrenheitStrings[] = { "F", "°F", "f", "Fahrenheit", "fahrenheit", NULL };
    return isInList(str, fahrenheitStrings);
}

bool kelvinIsScale(const char* str) {
    const char* kelvinStrings[] = { "K", "k", "Kelvin", "kelvin", NULL };
    return isInList(str, kelvinStrings);
}

converter_t getToKelvinFunction(char* temperatureScale) {
    struct TemperatureScale temperatureScales[] = {
        celsius, fahrenheit, kelvin, rankine, delisle, newton
    };
    for (int i = 0; i < sizeof(temperatureScales) / sizeof(temperatureScales[0]); i++) {
        if (temperatureScales[i].isScale(temperatureScale)) {
            return temperatureScales[i].toKelvin;
        }
    }
    fprintf(stderr, "error: Unsupported temperature scale: %s\n", temperatureScale);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc <= 3)
    {
        cout << argv[0] << "error: Not enough arguments.\nUsage:" << argv[0] << "INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]..." << endl;
    }
    TemperatureConverter* Temp;
    CelsiusConverter celsius;
    FahrenheitConverter fahrenheit;
    KelvinConverter kelvin;
    if (celsiusIsScale(argv[1]))
    {
         Temp = &celsius;
        
    }
    else if (fahrenheitIsScale(argv[1]))
    {
        Temp = &fahrenheit;
    }
    else if (kelvinIsScale(argv[1]))
    {
        Temp = &kelvin;
    }
    else
    {
        fprintf(stderr, "error: Unsupported temperature scale: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    TemperatureConverter* Temp1;
    if (celsiusIsScale(argv[2]))
    {
        Temp1 = &celsius;

    }
    else if (fahrenheitIsScale(argv[2]))
    {
        Temp1 = &fahrenheit;
    }
    else if (kelvinIsScale(argv[2]))
    {
        Temp1 = &kelvin;
    }
    else
    {
        fprintf(stderr, "error: Unsupported temperature scale: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    for (int i = 3; i < argc; i++)
    {
       double kValue = Temp->toKelvin(atof(argv[i]));
        double output = Temp1->fromKelvin(kValue);
        printf("%lf\n", output);
    }
    runtest();
    return EXIT_SUCCESS;
}
