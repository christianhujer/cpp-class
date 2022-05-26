#include <iostream>
#include <cassert>
#include <list>
#include <iterator>
#include <string.h>

using namespace std;

class TemperatureConverter
{
public:
    virtual double fromKelvin(double kelvin) = 0;
    virtual double toKelvin(double other) = 0;
    virtual bool isScale(string str) = 0;
};

bool isInList(string str, const string strings[])
{
    for (; *strings != string(""); strings++)
        if (str == *strings)
            return true;
    return false;
}

class CelsiusConverter : public TemperatureConverter
{
public:
    double fromKelvin(double kelvin)
    {
        return kelvin - 273.15;
    }
    double toKelvin(double other)
    {
        return other + 273.15;
    }
    bool isScale(string str)
    {
        const string celsiusStrings[] = {"C", "°C", "c", "Celsius", "celsius", ""};
        return isInList(str, celsiusStrings);
    }
};

class FahrenheitConverter : public TemperatureConverter
{
public:
    double fromKelvin(double kelvin)
    {
        return kelvin * 9 / 5 - 459.67;
    }

    double toKelvin(double other)
    {
        return (other + 459.67) * 5 / 9;
    }

    bool isScale(string str)
    {
        const string fahrenheitStrings[] = {"F", "°F", "f", "Fahrenheit", "fahrenheit", ""};
        return isInList(str, fahrenheitStrings);
    }
};

class KelvinConverter : public TemperatureConverter
{
public:
    double fromKelvin(double kelvin)
    {
        return kelvin;
    }
    double toKelvin(double other)
    {
        return other;
    }
    bool isScale(string str)
    {
        const string kelvinStrings[] = {"K", "k", "Kelvin", "kelvin", ""};
        return isInList(str, kelvinStrings);
    }
};

void runtest(void)
{
    TemperatureConverter *Temp;
    CelsiusConverter celsius;
    FahrenheitConverter farhenheit;
    KelvinConverter kelvin;
    Temp = &celsius;
    assert(Temp->fromKelvin(0) == -273.15);
    assert(Temp->toKelvin(0) == 273.15);
    Temp = &farhenheit;
    assert(Temp->fromKelvin(0) == -459.67);
    assert((Temp->toKelvin(0)) - 255.372 < 0.001);
    Temp = &kelvin;
    assert(Temp->fromKelvin(0) == 0);
    assert(Temp->toKelvin(0) == 0);
}

/*converter_t getToKelvinFunction(char* temperatureScale) {
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
}*/

/*void printReport(list <Converter> converters )
{
    for (list<Converter>::iterator converter = converters.begin(); converter != converters.end(); ++converter) {
        if (converter->celsius == BREAKFAST || expense->type == DINNER) {
            mealExpenses += expense->amount;
        }
}*/

enum Convert
{
    celsius,
    fahrenheit,
    kelvin

};
int main(int argc, char *argv[])
{
    if (argc <= 3)
    {
        cout << argv[0] << "error: Not enough arguments.\nUsage:" << argv[0] << "INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]..." << endl;
    }

    TemperatureConverter *Temp;
    TemperatureConverter *Temp1;
    CelsiusConverter celsius;
    FahrenheitConverter fahrenheit;
    KelvinConverter kelvin;
    std::list<TemperatureConverter *> Tlist = {&celsius, &fahrenheit, &kelvin};

    for (list<TemperatureConverter *>::iterator itr = Tlist.begin(); itr != Tlist.end(); ++itr)
    {
        if ((*itr)->isScale(argv[1]))
        {
            Temp = *itr;
        }
        else if ((*itr)->isScale(argv[2]))
        {
            Temp1 = *itr;
        }
        else
        {
            fprintf(stderr, "error: Unsupported temperature scale: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }
        /* if (celsiusIsScale(argv[1]))
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
        } */
        for (int i = 3; i < argc; i++)
        {
            double kValue = Temp->toKelvin(atof(argv[i]));
            double output = Temp1->fromKelvin(kValue);
            printf("%lf\n", output);
        }
        runtest();
        return EXIT_SUCCESS;
}
