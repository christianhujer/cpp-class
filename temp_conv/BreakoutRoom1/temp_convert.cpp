#include<iostream>
#include <cmath>
#include<cassert>
#include <string.h> 

using namespace std;

class temperatureConverter
{  
   public :
       virtual double fromKelvin(double kelvin) = 0;
       virtual double toKelvin(double other) = 0;
};

class celsiusConverter : public temperatureConverter
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
};

class fahrenheitConverter : public temperatureConverter
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
};

class kelvinConverter : public temperatureConverter
{
    public :
        double fromKelvin(double kelvin)
        {
            return kelvin;
        }
        double toKelvin(double other)
        {
            return other;
        }
};

int main() {
    temperatureConverter* Temp;
    celsiusConverter celsius;
    fahrenheitConverter farhenheit;
    Temp = &celsius;
    assert(Temp->fromKelvin(0) == -273.15);
    cout << Temp->fromKelvin(0) << endl;
    Temp = &farhenheit;
    assert(Temp->fromKelvin(0) == -459.67);
    cout << Temp->fromKelvin(0) << endl;
   
    return EXIT_SUCCESS;
}
