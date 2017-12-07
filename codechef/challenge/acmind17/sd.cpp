#include <iostream>
#include <cmath>
using namespace std;

float calculateSD(float data[]);

float calculateSD(float data[]){
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < 100; ++i){
        sum += data[i];
    }

    mean = sum/100;

    for(i = 0; i < 100; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / 100);
}

int main(){
    int i;
    float data[100];
    for(i = 0; i < 100; ++i)
        cin >> data[i];
    cout << endl << "Standard Deviation = " << calculateSD(data);

    return 0;
}