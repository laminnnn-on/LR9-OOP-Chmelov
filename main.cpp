#include <iostream>
#include <string>
using namespace std;

// Клас квитка в кінотеатр
class Ticket
{
private:
    string date;   // дата сеансу
    int hour;      // година сеансу (10–22)
    int row;       // номер ряду (1–15)

public:
    // Конструктор за замовчуванням
    Ticket()
    {
        date = "";
        hour = 0;
        row = 0;
    }

    // Конструктор ініціалізації
    Ticket(string d, int h, int r)
    {
        date = d;
        hour = h;
        row = r;
    }

    // Деструктор
    ~Ticket()
    {
        // Тут можна додати звільнення ресурсів, якщо потрібно
    }

    // set-методи
    void setTicket(string d, int h, int r)
    {
        date = d;
        hour = h;
        row = r;
    }

    // get-методи
    string getDate() { return date; }
    int getHour()    { return hour; }
    int getRow()     { return row; }

    // Обчислення вартості квитка
    // Ранок (10–17): 15 + 1.5 * ряд
    // Вечір (18–22): 25 + 2 * ряд
    double calculatePrice()
    {
        if (hour >= 10 && hour <= 17)
        {
            return 15 + 1.5 * row;
        }
        else if (hour >= 18 && hour <= 22)
        {
            return 25 + 2.0 * row;
        }
        else
        {
            return -1;   // недопустимий час
        }
    }

    // Виведення інформації про квиток
    void showTicket()
    {
        cout << "\nІнформація про квиток:" << endl;
        cout << "Дата сеансу: " << date << endl;
        cout << "Час сеансу:  " << hour << ":00" << endl;
        cout << "Ряд:         " << row << endl;

        double price = calculatePrice();
        if (price != -1)
        {
            cout << "Вартість квитка: " << price << " грн" << endl;
        }
        else
        {
            cout << "Для цього часу сеансу ціна не визначена." << endl;
        }
    }
};

int main()
{
    string date;
    int hour, row;

    cout << "Введіть дату сеансу (ДД.ММ.РРРР): ";
    cin >> date;

    cout << "Введіть годину сеансу (10-22): ";
    cin >> hour;

    cout << "Введіть номер ряду (1-15): ";
    cin >> row;

    // Перевірка коректності введених даних
    if (hour < 10 || hour > 22 || row < 1 || row > 15)
    {
        cout << "Помилка введення даних!" << endl;
        return 1;
    }

    // Створення об'єкта за допомогою конструктора ініціалізації
    Ticket ticket(date, hour, row);

    // Виведення інформації
    ticket.showTicket();

    return 0;
}
