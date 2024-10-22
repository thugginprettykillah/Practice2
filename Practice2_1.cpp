#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <chrono>
using namespace std;
using namespace chrono;
// идз
void bubble_sort(int* P) {
    for (int i = 0, count = 0; i < 100; ++i, count = 0) {
        for (int j = 0; j < 100 - 1 - i; ++j) {
            if (P[j] > P[j + 1]) {
                swap(P[j], P[j + 1]);
                ++count;
            }
        }
        if (count == 0) {
            break;
        }
    }
}
void shaker_sort(int* P) {
    bool swapped = true;
    int start = 0, end = 99;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (P[i] > P[i + 1]) {
                swap(P[i], P[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (P[i] > P[i + 1]) {
                swap(P[i], P[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}
void comb_sort(int* P) {
    int s = 99;
    float k = 1.247;
    while (s >= 1) {
        for (int i = 0; i + s < 100; i++) {
            if (P[i] > P[int(i + s)]) {
                swap(P[i], P[int(i + s)]);
            }
            s /= k;
        }
    }
    bubble_sort(P);
}
void insert_sort(int* P) {
    int key, j;
    for (int i = 1; i < 100; ++i) {
        key = P[i];
        j = i - 1;
        while (j >= 0 && P[j] > key) {
            P[j + 1] = P[j];
            --j;
        }
        P[j + 1] = key;
    }
}
void quick_sort(int* P, int begin, int end) {
    int mid;
    int f = begin;
    int l = end;
    mid = P[(f + l) / 2];
    while (f < l) {
        while (P[f] < mid) f++;
        while (P[l] > mid) l--;
        if (f <= l) {
            swap(P[f], P[l]);
            f++;
            l--;
        }
    }
    if (begin < l)
        quick_sort(P, begin, l);
    if (f < end)
        quick_sort(P, f, end);
}
void write_interface() {
    cout << "Выберите действие: " << endl << "1.Создать массив из 100 элементов" << endl << "2.Отсортировать массив" << endl
        << "3.Найти max и min" << endl << "4.Вывести среднее значение, индексы элементов, равных ему, и их количество" << endl << "5.Вывести количество элементов, меньших a"
        << endl << "6.Вывести количество элементов, больших b" << endl << "7.Найти число с" << endl << "8.Поменять местами элементы"
        << endl << "9.Вывести массив" << endl << "Введите 0, чтобы выйти" << endl;
}
void write_arr(int P[]) {
    cout << "Сейчас массив выглядит так:\n";
    for (int i = 0; i < 100; ++i) {
        cout << P[i] << " ";
    }
    cout << "\n\n";
}
void task1(int* P, int* C) {
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        P[i] = rand() % 199 - 99;
        C[i] = P[i];
    }
}
void task2(int* P) {
    system("cls");
    int ans;
    cout << "Выберите сортировку:" << endl << "1.Bubble sort" << endl << "2.Shaker sort" << endl << "3.Comb sort" << endl << "4.Insert sort" << endl << "5.Quick sort" << endl;
    cin >> ans;
    time_point<steady_clock, duration<_int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    switch (ans) {
    case 1: {
        bubble_sort(P);
        break;
    }
    case 2: {
        shaker_sort(P);
        break;
    }
    case 3: {
        comb_sort(P);
        break;
    }
    case 4: {
        insert_sort(P);
        break;
    }
    case 5: {
        quick_sort(P, 0, 99);
        break;
    }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\n\nВыполнено за " << result.count() << " наносекунд";
}
void task3(int* P, int* mn, int* mx) {
    for (int i = 0; i < 100; ++i) {
        if (P[i] <= *mn) {
            *mn = P[i];
        }
        if (P[i] >= *mx) {
            *mx = P[i];
        }
    }
}
void task4_unsort(int* P, int* mn, int* mx) {
    task3(P, &*mn, &*mx);
    int s = round((*mn + *mx) / 2), cnt = 0;
    time_point<steady_clock, duration<_int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    cout << "Индексы элементов, равных среднему значению s = " << s << endl;
    start = steady_clock::now();
    for (int i = 0; i < 100; ++i) {
        if (P[i] == s) {
            cout << i << " ";
            ++cnt;
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\nИх количество = " << cnt << "\nЭлементы найдены за " << result.count() << " наносекунд";
}
void task4_sort(int* P, int* mn, int* mx) {
    task3(P, &*mn, &*mx);
    int s = round((*mn + *mx) / 2), cnt = 0;
    cout << "Индексы элементов, равных среднему значению s = " << s << endl;
    time_point<steady_clock, duration<_int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    for (int i = 0; i < 100; ++i) {
        if (P[i] == s) {
            cout << i << " ";
            ++cnt;
        }
        if (P[i] > s) break;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "\nИх количество = " << cnt << "\nЭлементы найдены за " << result.count() << " наносекунд";
}
void task5(int P[]) {
    int a, cnt = 0;
    cout << "Введите число a: ";
    cin >> a;
    cout << "\nКоличество элементов, которые меньше этого числа: ";
    while (P[cnt] < a) {
        ++cnt;
    }
    cout << cnt;
}
void task6(int P[]) {
    int b, cnt = 99;
    cout << "Введите число b: ";
    cin >> b;
    cout << "\nКоличество элементов, которые больше этого числа: ";
    while (P[cnt] > b) {
        --cnt;
    }
    cout << 99 - cnt;
}
int task7_binary(int P[], int c, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (P[mid] == c) {
            return mid;
        }
        if (P[mid] > c) {
            return task7_binary(P, c, start, mid - 1);
        }
        return task7_binary(P, c, mid + 1, end);
    }
    return -1;
}
int task7_perebor(int P[], int c) {
    for (int i = 0; i < 100; ++i) {
        if (P[i] == c) {
            return i;
        }
    }
    return -1;
}
int main() {
    setlocale(LC_ALL, "RU");
    time_point<steady_clock, duration<_int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    time_point<steady_clock, duration<_int64, ratio<1, 1000000000>>> start1, end1;
    nanoseconds result1;
    int const N = 100;
    int Arr[N], UnsortArr[N], ans, mn, mx, j, c, v, sw1, sw2;
    bool initialize = false, sorted = false;
    system("cls");
    do {
        write_interface();
        cin >> ans;
        switch (ans) {
        case 0: {
            system("cls");
            break;
        }
        case 1: {
            task1(Arr, UnsortArr);
            initialize = true;
            sorted = false;
            cout << "Выполнено!";
            Sleep(1000);
            system("cls");
            break;
        }
        case 2: {
            if (initialize) {
                task2(Arr);
                sorted = true;
                Sleep(5000);
                system("cls");
                break;
            }
            else {
                cout << "Ошибка! Массив не инициализирован...";
                Sleep(3000);
                system("cls");
                break;
            }
        }
        case 3: {
            mn = 100; mx = -100;
            system("cls");
            cout << "С каким массивом работать?" << endl << "1.С отсортированным" << endl << "2.С неотсортированным" << endl;
            cin >> j;
            switch (j) {
            case 1: {
                if (initialize && sorted) {
                    start = steady_clock::now();
                    mx = Arr[99];
                    mn = Arr[0];
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "max = " << mx << "   " << "min = " << mn << "\nЭлементы найдены за " << result.count() << " наносекунд";
                    Sleep(2000);
                    system("cls");
                    break;
                }
                else {
                    cout << "Ошибка! Массив не инициализирвоан или неотсортирован...";
                    Sleep(3000);
                    system("cls");
                    break;
                }
            }
            case 2: {
                if (initialize) {
                    start = steady_clock::now();
                    task3(UnsortArr, &mn, &mx);
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "max = " << mx << "   " << "min = " << mn << "\nЭлементы найдены за " << result.count() << " наносекунд";
                    Sleep(2000);
                    system("cls");
                    break;
                }
                else {
                    cout << "Ошибка! Массив не инициализирован...";
                    Sleep(3000);
                    system("cls");
                    break;
                }
            }
            }
            break;
        }
        case 4: {
            mn = 100; mx = -100;
            system("cls");
            cout << "С каким массивом работать?" << endl << "1.С отсортированным" << endl << "2.С неотсортированным" << endl;
            cin >> j;
            switch (j) {
            case 1: {
                if (initialize && sorted) {
                    task4_sort(Arr, &mn, &mx);
                    Sleep(8000);
                    system("cls");
                    break;
                }
                else {
                    cout << "Ошибка! Массив не инициализирован или не отсортирован...";
                    Sleep(3000);
                    system("cls");
                    break;
                }
            }
            case 2: {
                if (initialize) {
                    task4_unsort(UnsortArr, &mn, &mx);
                    Sleep(8000);
                    system("cls");
                    break;
                }
                else {
                    cout << "Ошибка! Массив не инициализирован...";
                    Sleep(3000);
                    system("cls");
                    break;
                }
            }
            }
            break;
        }
        case 5: {
            if (initialize && sorted) {
                system("cls");
                task5(Arr);
                Sleep(4000);
                system("cls");
                break;
            }
            else {
                cout << "Ошибка! Массив не инициализирован или не отсортирован...";
                Sleep(3000);
                system("cls");
                break;
            }
        }
        case 6: {
            if (initialize && sorted) {
                system("cls");
                task6(Arr);
                Sleep(4000);
                system("cls");
                break;
            }
            else {
                cout << "Ошибка! Массив не инициализирован или не отсортирован...";
                Sleep(3000);
                system("cls");
                break;
            }
            break;
        }
        case 7: {
            system("cls");
            cout << "Введите число, которое хотите найти: ";
            cin >> c;
            start = steady_clock::now();
            v = task7_perebor(Arr, c);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            start1 = steady_clock::now();
            v = task7_binary(Arr, c, 0, 99);
            end1 = steady_clock::now();
            result1 = duration_cast<nanoseconds>(end1 - start1);
            if (v != -1) {
                cout << "\nЭлемент находится в массиве!\n" << "Время, затраченное на бинарный поиск: " << result1.count() << "     Время, затраченное на обычный поиск: " << result.count();
                if (result1 < result) cout << "\nБинарный поиск победил!";
                else cout << "\nОбычный поиск победил!";
                Sleep(10000);
            }
            else {
                cout << "\nТакого элемента нет...";
                Sleep(3000);
            }
            system("cls");
            break;
        }
        case 8: {
            system("cls");
            cout << "Введите индексы элементов, которые хотите поменять местами: ";
            cin >> sw1 >> sw2;
            start = steady_clock::now();
            swap(Arr[sw1], Arr[sw2]);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Выполнено! Время, затраченное на операцию: " << result.count() << " наносекунд";
            sorted = false;
            Sleep(3000);
            system("cls");
            break;
        }
        case 9: {
            if (initialize) {
                system("cls");
                write_arr(Arr);
                break;
            }
            else {
                cout << "Ошибка! Массив не инициализирован...";
                Sleep(3000);
                system("cls");
                break;
            }
        }
        default: {
            cout << "Введено неверное значение, попробуйте еще раз... ";
            Sleep(1000);
            system("cls");
            ans = 1;
        }
        }
    } while (ans);
}