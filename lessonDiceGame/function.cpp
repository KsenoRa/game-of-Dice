// функуции для работы игры


#include <iostream>
#include <iomanip> //для манипуляций 
#include <cstdlib>
#include <locale>
#include <unistd.h> //для задержки во время броска компьютера
using namespace std;

int const SIZE = 2;
int nTempRes = 0, nUserRes = 0, nCompRes = 0;
int nChoice = 0;


void stroke(int array[],int const SIZE) {
    for (int i = 0; i < SIZE; i++) {
         array[i] = 1 + rand() % (6 - 1 + 1);
         nTempRes += array[i]; //сумма очков за один бросок
         nChoice = array[i];
    }
}

void ShowDice(int array[],int const SIZE) {
    string szWordEnd_O = "о", szWordEnd_A = "а", szWordEnd_OB = "ов";

    cout << "  _ " << "_ " << setw(5) << "  _ " << "_ " << endl << endl;
    for (int i = 0; i < SIZE; i++) {
         cout << " | " << array[i] << " | ";
    }
    cout << "\n  _ " << "_ " << setw(5) << "  _ " << "_ " << endl;

    cout << "Это " << nTempRes << " очк";
    if (nTempRes == 1) {
        cout << szWordEnd_O << ".\n";
    } else if (nTempRes > 1 && nTempRes < 5) {
        cout << szWordEnd_A << ".\n";
    } else if (nTempRes >= 5 && nTempRes <= 20) {
        cout << szWordEnd_OB << ".\n";
    } 
}


//сравнивает игровые очки
void ComparePoints() {
    if (nUserRes > nCompRes) {
        cout << "\nВы победили.\n";
    } else if (nUserRes == nCompRes) {
        cout << "\nНичья.\n";
    } else {
        cout << "\nКомпьютер победил.\n";
    }

}