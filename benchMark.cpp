#include <iostream>
#include <time.h>
using namespace std;

double functionFx(int n) {
    if (n >= 2)
        return (functionFx(n-1)+functionFx(n-2))/(functionFx(n-1)-functionFx(n-2));
    else if(n == 1)
        return 1./3.;
    else
        return 3.1415;
}

double sec() {
    return double(clock()) / double(CLOCKS_PER_SEC);
}

void reSetArray(int arr[]) {
    for (int i = 9999; i >= 0; i--) {
        arr[9999 - i] = i;
    }
}

void linearSort( int arr[]) {
    int size = 10000;
    int index = 0;
    int min = 0;
    int temp = 0;
    for (int i = 0; i < size; i++) {
        min = arr[i];
        for (int j = i; j < size; j++) {
            if (arr[j] < min) {
                index = j;
                min = arr[j];
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
}

int main() {
    clock_t clock;
    int counter = 0, counter1 = 0;
    double vFloat = 0;
    double vInteger = 0;
    int array[10000];
    double periodFloat, periodInteger;
    
    //    Floating part, operation time is 10 seconds.
    double t = sec();
    while (sec() - t < 10) {
        double temp = functionFx(18);
        counter++;
    }
    periodFloat = sec() - t;
    vFloat = 60 * counter / periodFloat;
    cout << "the number of operation of float: " << counter << endl;
    cout << "speed of floating is " << vFloat << endl;
    cout << "period1: " << periodFloat << endl;
    //    Integer part, operation time is 10 seconds.
    
    t = sec();
    while (sec() - t < 10) {
        reSetArray(array);
        linearSort(array);
        counter1++;
    }
    periodInteger = sec() - t;
    vInteger = 60 * counter1 / (sec() - t);
    cout << "the number of operation of integer: " << counter1 << endl;
    cout << "speed of integer is " << vInteger << endl;
    cout << "period2: " << periodInteger << endl;
    cout << "the speed of this computer is: " << (vFloat*periodFloat + vInteger*periodInteger) / (periodFloat + periodInteger) << endl;
    
    return 0;
}
