//игра в кости END

#include <iostream>
#include <iomanip> //для манипуляций 
#include <cstdlib>
#include <locale>
#include <unistd.h> //для задержки во время броска компьютера
using namespace std;

int nTempRes = 0, nUserRes = 0, nCompRes = 0, nUserScore = 0, nCompScore = 0;
    
//выбор очков на одной кости
int stroke(); 

//реализует графику игры
void ShowDice(int a);

//выводит окончания слова
void ShowEndWord(int nTempRes);

//задерживает выполнение программы, затем очищает экран
void waiting();

//ход компьютера
int runComp();

//ход игрока
int runUser();

//сравнивает игровые очки раундов
void ComparePoints(int nUserRes, int nCompRes);

//сравнивает все очки за игру
void ComparePoints(int nUserScore, int nCompScore, int a );

    
int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int SIZE = 4;
    //массивы для выведения очков в виде сводной таблицы
    int UserRes[SIZE] = {}, CompRes[SIZE] = {};
    
    //реализует очередность бросков
    cout << "\tЖЕРЕБЬЕВКА\n Бросте кости (Нажмите Enter)\n";
    cin.get();
    bool bSwitch = true; //не выводит в конце цикла надпись
    for (int i = 0; i < 2; i++) {
        //выбирает в какую переменную сохранить временный результат
        switch (bSwitch) {
            case true:
                nUserRes = stroke();
                break;
            case false:
                nCompRes = stroke();
        }
        ShowDice(nTempRes);
        //условие которое не выводит надпись в конце цикла
        if (bSwitch == true) {
            cout << "Компьютер бросает\n\n";
            bSwitch = false;
            sleep(2);
        }
    }
    //задерживает выполнение программы, затем очищает экран
    waiting();
    if (nUserRes > nCompRes) {
        cout << "Вы набрали больше очков. Вы ходете первым\n\n";
        //цикл для 4 раундов
        for (int i = 0; i < SIZE; i++) {
            cout << "\t" << i + 1 << " РАУНД\n\n";
           //ход игрока
           runUser();
           UserRes[i] = nUserRes;
           //ход компьютера
           runComp();
           CompRes[i] = nCompRes;
           ComparePoints(nUserRes, nCompRes); //выводит результат раунда
           //задержка системы
           waiting();
        }
    } else {
        cout << "Компьютер набрал больше очков. Он ходет первым\n";
        //цикл для 4 раундов
        for (int i = 0; i < SIZE; i++) {
            cout << "\t" << i + 1 << " РАУНД\n\n";
            runComp();
            CompRes[i] = nCompRes;
            
            runUser();
            UserRes[i] = nUserRes;
            ComparePoints(nUserRes, nCompRes);
            waiting();
        }
    }
    cout << "\t  Счет\n"; 
    cout << "      Игрок | Компьютер\n"; 
    //выводит очки игроков в виде сводной таблицы
    for (int i = 0; i < SIZE; i++) {
        cout << "Раунд " << i + 1 << " | " << UserRes[i] << " | " <<  CompRes[i] << endl;
    }
    
    cout << "\nВы набрали: " << nUserScore << endl;
    cout << "Компьютер набрал: " << nCompScore << endl;
    ComparePoints(nUserScore, nCompScore, 0);
    
    return 0;
}


//выбор очков на одной кости
int stroke() {
         nTempRes = 1 + rand() % (6 - 1 + 1);
         return nTempRes;
}

//реализует графику игры
void ShowDice(int a) {
     switch (nTempRes) {
        case 1:
            cout << "****************\n"
                    "*              *\n"
                    "*              *\n"
                    "*              *\n"
                    "*       @      *\n"
                    "*              *\n"
                    "*              *\n"
                    "*              *\n"
                    "****************\n\n";
            break;
        case 2:
            cout << "\t****************\n"
                    "\t*              *\n"
                    "\t*       @      *\n"
                    "\t*              *\n"
                    "\t*              *\n"
                    "\t*              *\n"
                    "\t*       @      *\n"
                    "\t*              *\n"
                    "\t****************\n\n";
            break;
        case 3:
            cout << "\t\t****************\n"
                    "\t\t*              *\n"
                    "\t\t*       @      *\n"
                    "\t\t*              *\n"
                    "\t\t*       @      *\n"
                    "\t\t*              *\n"
                    "\t\t*       @      *\n"
                    "\t\t*              *\n"
                    "\t\t****************\n\n";
            break;
        case 4:
            cout << "\t****************\n"
                    "\t*              *\n"
                    "\t*   @      @   *\n"
                    "\t*              *\n"
                    "\t*              *\n"
                    "\t*              *\n"
                    "\t*   @      @   *\n"
                    "\t*              *\n"
                    "\t****************\n\n";
            break;
        case 5:
            cout << "****************\n"
                    "*              *\n"
                    "*   @      @   *\n"
                    "*              *\n"
                    "*       @      *\n"
                    "*              *\n"
                    "*   @      @   *\n"
                    "*              *\n"
                    "****************\n\n";
            break;
        case 6:
            cout << "\t****************\n"
                    "\t*              *\n"
                    "\t*   @      @   *\n"
                    "\t*              *\n"
                    "\t*   @      @   *\n"
                    "\t*              *\n"
                    "\t*   @      @   *\n"
                    "\t*              *\n"
                    "\t****************\n\n";
    } 
}

//выводит окончания слова
void ShowEndWord(int nTempRes) {
    string szWordEnd_O = "о", szWordEnd_A = "а", szWordEnd_OB = "ов";

    cout << "Это " << nTempRes << " очк";
    if (nTempRes == 1) {
        cout << szWordEnd_O << ".\n\n";
    } else if (nTempRes > 1 && nTempRes < 5) {
        cout << szWordEnd_A << ".\n\n";
    } else if (nTempRes >= 5 && nTempRes <= 20) {
        cout << szWordEnd_OB << ".\n\n";
    } 
}

//задерживает выполнение программы, затем очищает экран
void waiting() {
    sleep(3);
    system("clear");
}

//ход компьютера
int runComp() {
    nCompRes = 0;
    cout << "Компьютер бросает\n\n";
    sleep(3);
    for (int i = 0; i < 2; i++) {
        nCompRes += stroke();
        ShowDice(nTempRes);
    }
        nCompScore += nCompRes;
        ShowEndWord(nCompRes);
        return nCompScore;
}

//ход игрока
int runUser() {
    nUserRes = 0;
    cout << "Бросте кости (Нажмите Enter)\n";
    cin.get();
    for (int i = 0; i < 2; i++) {
        nUserRes += stroke();
        ShowDice(nTempRes);
    }
    nUserScore += nUserRes; //счет игрока
    ShowEndWord(nUserRes);
    return nUserScore;
}

//сравнивает игровые очки раундов
void ComparePoints(int nUserRes, int nCompRes) {
    if (nUserRes > nCompRes) {
        cout << "\nВы победили.\n";
    } else if (nUserRes < nCompRes) {
        cout << "\nКомпьютер победил.\n";
    } else {
        cout << "\nНичья.\n";
    }

}

//сравнивает все очки за игру
void ComparePoints(int nUserScore, int nCompScore, int a) {
    if (nUserScore > nCompScore) {
        cout << "\nВы победили.\n";
    } else if (nUserScore < nCompScore) {
        cout << "\nКомпьютер победил.\n";
    } else {
        cout << "\nНичья.\n";
    }

}