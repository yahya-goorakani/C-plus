#include "class.hpp"



//Создается функция testDateTime, в которой мы создаем несколько экземпляров класса DateTime.
//Сначала мы создаем 5 экземпляров класса DateTime с разными значениями.
//Затем, используя операторы assert, мы проверяем значения этих примеров, чтобы убедиться, что они имеют правильные значения.
//Далее мы протестируем различные функции класса DateTime, такие как toString, fromString, isValidDate, isValidTime и т. д.
//Затем мы тестируем функции, которые добавляются к DateTime, такие как addSecs, addMinutes, addDays, addMonths и addYears.
//Наконец, мы тестируем функции daysTo и secsTo, которые вычисляют количество дней и секунд между двумя DateTime.
//Создается основная функция, в которой вызывается функция testDateTime.
//Программа завершается возвратом нуля из основной функции.
void testDateTime() {
    DateTime dt1;
    DateTime dt2(2023, 5, 8, 12, 30, 45);
    DateTime dt3 = dt2;
    DateTime dt4 = DateTime::now();
    DateTime dt5(1672266860, std::tm({ 0, 0, 0, 8, 4, 123, 5, 127, 0 }));
    assert(dt1.getDate().year == 0);
    assert(dt1.getDate().month == 0);
    assert(dt1.getDate().day == 0);
    assert(dt1.getTime().hour == 0);
    assert(dt1.getTime().minute == 0);
    assert(dt1.getTime().second == 0);
    
    assert(dt2.getDate().year == 2023);
    assert(dt2.getDate().month == 5);
    assert(dt2.getDate().day == 8);
    assert(dt2.getTime().hour == 12);
    assert(dt2.getTime().minute == 30);
    assert(dt2.getTime().second == 45);
    
    assert(dt3.getDate().year == 2023);
    assert(dt3.getDate().month == 5);
    assert(dt3.getDate().day == 8);
    assert(dt3.getTime().hour == 12);
    assert(dt3.getTime().minute == 30);
    assert(dt3.getTime().second == 45);
    
    assert(DateTime::now().getDate().year > 0);
    assert(DateTime::now().getDate().month >= 1);
    assert(DateTime::now().getDate().day >= 1);
    assert(DateTime::now().getTime().hour >= 0);
    assert(DateTime::now().getTime().minute >= 0);
    assert(DateTime::now().getTime().second >= 0);
    
    assert(dt4.getDate().year > 0);
    assert(dt4.getDate().month >= 1);
    assert(dt4.getDate().day >= 1);
    assert(dt4.getTime().hour >= 0);
    assert(dt4.getTime().minute >= 0);
 assert(dt4.getTime().second >= 0);
    
    assert(dt5.getDate().year == 2022);
    assert(dt5.getDate().month == 12);
    assert(dt5.getDate().day == 28);
    assert(dt5.getTime().hour == 23);
    assert(dt5.getTime().minute == 1);
    assert(dt5.getTime().second == 0);
    
    assert(dt2.toString("%Y-%m-%d %H:%M:%S") == "2023-05-08 12:30:45");
      assert(DateTime::fromString("2023-05-08 12:30:45", "%Y-%m-%d %H:%M:%S").toSeconds() == dt2.toSeconds());
    
    assert(DateTime::isValidDate(2023, 5, 8) == true);
    assert(DateTime::isValidDate(2023, 2, 29) == false);
    assert(DateTime::isValidDate(2023, 4, 31) == false);
    
    assert(DateTime::isValidTime(24, 0, 0) == false);
    assert(DateTime::isValidTime(12, 60, 0) == false);
    assert(DateTime::isValidTime(12, 30, 60) == false);
    
    dt2.addSecs(30);
    assert(dt2.getTime().hour == 12);
    assert(dt2.getTime().minute == 31);
    assert(dt2.getTime().second == 15);

    dt2.addMinutes(10);
    assert(dt2.getTime().hour == 12);
    assert(dt2.getTime().minute == 41);
    assert(dt2.getTime().second == 15);

    dt2.addDays(1);
    assert(dt2.getDate().year == 2023);
    assert(dt2.getDate().month == 5);
    assert(dt2.getDate().day == 9);
    assert(dt2.getTime().hour == 12);
    assert(dt2.getTime().minute == 41);
    assert(dt2.getTime().second == 15);

    dt2.addMonths(2);
    assert(dt2.getDate().year == 2023);
    assert(dt2.getDate().month == 7);
    assert(dt2.getDate().day == 9);
    assert(dt2.getTime().hour == 12);
    assert(dt2.getTime().minute == 41);
    assert(dt2.getTime().second == 15);

    dt2.addYears(1);
    assert(dt2.getDate().year == 2024);
    assert(dt2.getDate().month == 7);

    assert(dt2.getDate().day == 9);
    assert(dt2.getTime().hour == 12);
    assert(dt2.getTime().minute == 41);
    assert(dt2.getTime().second == 15);

    assert(dt2.daysTo(DateTime(2024, 7, 9, 12, 41, 15)) == 11);
    assert(dt2.secsTo(DateTime(2024, 7, 20, 12, 0, 0)) == 950400);

}