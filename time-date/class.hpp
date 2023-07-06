#ifndef LABA_1_CLASS_HPP
#define LABA_1_CLASS_HPP
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cassert>
class DateTime {
private:
    struct Date {
        int year;
        int month;
        int day;
    };
    struct Time {
        int hour;
        int minute;
        int second;
    };
    Date _date;
    Time _time;
public:
    // Constructors
    
    

    //Конструктор по умолчанию: этот конструктор инициализирует дату и время до нуля.
   DateTime() : _date({ 0, 0, 0 }), _time({ 0, 0, 0 }) {} 

    

    //Конструктор копирования: этот конструктор принимает другой экземпляр DateTime в качестве входных данных и копирует его значения даты и времени
    DateTime(const DateTime& other) : _date(other._date), _time(other._time) {}        


    //Конструктор с указанными значениями: Этот конструктор принимает значения года, месяца, дня, часа, минуты и секунды в качестве входных данных и соответственно устанавливает значения даты и времени.
    DateTime(int year, int month, int day, int hour, int minute, int second) : _date({ year, month, day }), _time({ hour, minute, second }) {}




    //Конструктор с секундами и структурой tm: этот конструктор принимает количество секунд и структуру tm в качестве входных данных и соответственно устанавливает значения даты и времени.
    DateTime(const int seconds, const struct tm& time) {
        time_t t = seconds;
        tm* tm_local = localtime(&t);
        _date.year = tm_local->tm_year + 1900;
        _date.month = tm_local->tm_mon + 1;
        _date.day = tm_local->tm_mday;
        _time.hour = tm_local->tm_hour;
 _time.minute = tm_local->tm_min;
        _time.second = tm_local->tm_sec;
    }  



    //Конструктор перемещения: этот конструктор принимает другой экземпляр DateTime в качестве входных данных и перемещает его значения даты и времени в новый экземпляр. После миграции значения даты и времени старого экземпляра обнуляются.
    DateTime(DateTime&& other) noexcept {
        _date = other._date;
        _time = other._time;
        other._date = { 0, 0, 0 };
        other._time = { 0, 0, 0 };
    }



    // Getters and setters


    //Метод getDate() возвращает дату в виде объекта Date. Метод getTime() также возвращает время в виде объекта Time. Методы setDate() и setTime() устанавливают дату и время соответственно.

    inline Date getDate() const { return _date; }
    inline Time getTime() const { return _time; }
    inline void setDate(int year, int month, int day) { _date = { year, month, day }; }
    inline void setTime(int hour, int minute, int second) { _time = { hour, minute, second }; }

    // Methods
    
    
    
    // Метод toString() возвращает в качестве входных данных строку, содержащую дату и время в соответствии с заданным форматом. Формат может включать специальные символы, начинающиеся с %, которые обозначают определенное поле. Например, %Y — год, %m — месяц, %d — день, %H — час, %M — минута, %S — секунда.
    std::string toString(const std::string& format) const {
        std::stringstream ss;
        for (int i = 0; i < format.size(); i++) {
            if (format[i] == '%') {
                switch (format[i + 1]) {
                case 'Y':
                    ss << std::setw(4) << std::setfill('0') << _date.year;
                    break;
                case 'm':
                    ss << std::setw(2) << std::setfill('0') << _date.month;
                    break;
                case 'd':
                    ss << std::setw(2) << std::setfill('0') << _date.day;
  break;
                case 'H':
                    ss << std::setw(2) << std::setfill('0') << _time.hour;
                    break;
                case 'M':
                    ss << std::setw(2) << std::setfill('0') << _time.minute;
                    break;
                case 'S':
                    ss << std::setw(2) << std::setfill('0') << _time.second;
                    break;
                case '%':
                    ss << '%';
                    break;
                default:
                    throw std::invalid_argument("Invalid format string");
                }
                i++;
            }
            else {
                ss << format[i];
            }
        }
        return ss.str();
    }
  




    //Методы isValidDate() и isValidTime() проверяют правильность даты и времени. Эти методы используются для проверки входных данных.
    static bool isValidDate(int year, int month, int day) {
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }
        if (month == 2) {
            if (day > 29) {
                return false;
            }
            if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
                return false;
            }
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
            return false;
        }
 return true;
    }



    //Методы isValidDate() и isValidTime() проверяют правильность даты и времени. Эти методы используются для проверки входных данных.
    static bool isValidTime(int hour, int minute, int second) {
        return hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59;
    }
 

    //Эта функция возвращает текущее время.
    static DateTime now() {
        time_t t = std::time(nullptr);
        struct tm tm_local = *std::localtime(&t);
        return DateTime((int)t, tm_local);
    }
  
    //Эта функция возвращает структуру std::tm на основе текущих значений даты и времени.
    std::tm toTm() const {
        std::tm tm_local = {};
        tm_local.tm_year = _date.year - 1900;
        tm_local.tm_mon = _date.month - 1;
        tm_local.tm_mday = _date.day;
        tm_local.tm_hour = _time.hour;
        tm_local.tm_min = _time.minute;
        tm_local.tm_sec = _time.second;
        tm_local.tm_isdst = -1;
        return tm_local;
    }


    //Эта функция получает строку даты и времени вместе с ее форматом и возвращает объект DateTime.
    static DateTime fromString(const std::string& dateString, const std::string& format) {
        std::tm tm_local = {};
        std::istringstream ss(dateString);
        ss >> std::get_time(&tm_local, format.c_str());
        if (ss.fail()) {
            throw std::invalid_argument("Invalid date string or format");
        }
        return DateTime((int)std::mktime(&tm_local), tm_local);
    }


    // Эта функция добавляет указанное количество секунд к текущему значению времени.
    void addSecs(int seconds) {
        time_t t = (time_t)toSeconds() + seconds;
        struct tm tm_local = *std::localtime(&t);
        _date.year = tm_local.tm_year + 1900;
        _date.month = tm_local.tm_mon + 1;
 _date.day = tm_local.tm_mday;
        _time.hour = tm_local.tm_hour;
        _time.minute = tm_local.tm_min;
        _time.second = tm_local.tm_sec;
    }
   

    //Эта функция добавляет указанное количество минут к текущему значению времени.
    void addMinutes(int minutes) {
        addSecs(minutes * 60);
    }


    //Эта функция добавляет указанное количество дней к текущему значению даты.
    void addDays(int days) {
        addSecs(days * 86400);
    }


    //Эта функция добавляет указанное количество месяцев к текущему значению даты.
    void addMonths(int months) {
        int year = _date.year + (months / 12);
        int month = _date.month + (months % 12);
        if (month > 12) {
            year++;
            month -= 12;
        }
        else if (month < 1) {
            year--;
            month += 12;
        }
        int day = _date.day;
        while (!isValidDate(year, month, day)) {
            day--;
        }
        _date.year = year;
        _date.month = month;
        _date.day = day;
    }


    //Эта функция добавляет указанное количество лет к текущему значению даты.
    void addYears(int years) {
        _date.year += years;
        if (!isValidDate(_date.year, _date.month, _date.day)) {
            _date.day--;
        }
    }
//Эта функция возвращает количество дней между двумя датами.
    int daysTo(const DateTime& other) const {
        time_t t1 = toSeconds();
        time_t t2 = other.toSeconds();
        return (int)std::difftime(t2, t1);
                                  }


    //Эта функция возвращает количество секунд между двумя повторениями.
  int secsTo(const DateTime& other) const {
      time_t t1 = toSeconds();
      time_t t2 = other.toSeconds();
      return (int)std::difftime(t2, t1);
  }


  //Эта функция возвращает текущее значение времени в секундах.
  time_t toSeconds() const {
      std::tm tm_local = toTm();
      return std::mktime(&tm_local);
  }



  //: эта функция используется для печати объекта DateTime на выходе.
  friend std::ostream& operator<<(std::ostream& os, const DateTime& dt) {
      os << dt.toString("%Y-%m-%d %H:%M:%S");
      return os;
  }
  };


class DateTime {
public:
    struct Date {
        int day;
        int month;
        int year;
    };

    struct Time {
        int hour;
        int minute;
        int second;
    };

    DateTime() {
        std::time_t now = std::time(nullptr);
        std::tm* local_time = std::localtime(&now);
        setDate(local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
        setTime(local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
    }

    DateTime(const DateTime& other) {
        setDate(other.date().day, other.date().month, other.date().year);
        setTime(other.time().hour, other.time().minute, other.time().second);
    }

    DateTime(int day, int month, int year, int hour, int minute, int second) {
        setDate(day, month, year);
        setTime(hour, minute, second);
    }

    DateTime(DateTime&& other) noexcept {
        setDate(other.date().day, other.date().month, other.date().year);
        setTime(other.time().hour, other.time().minute, other.time().second);
    }

    inline int day() const { return _date.day; }
    inline int month() const { return _date.month; }
    inline int year() const { return _date.year; }
    inline int hour() const { return _time.hour; }
    inline int minute() const { return _time.minute; }
    inline int second() const { return _time.second; }

    inline void setDay(int day) { _date.day = day; }
    inline void setMonth(int month) { _date.month = month; }
    inline void setYear(int year) { _date.year = year; }
    inline void setHour(int hour) { _time.hour = hour; }
    inline void setMinute(int minute) { _time.minute = minute; }
    inline void setSecond(int second) { _time.second = second; }

    void setDate(int day, int month, int year) {
        _date.day = day;
        _date.month = month;
        _date.year = year;
    }

    void setTime(int hour, int minute, int second) {
        _time.hour = hour;
        _time.minute = minute;
        _time.second = second;
    }

    Date date() const { return _date; }
    Time time() const { return _time; }

    static bool isValidDate(int day, int month, int year) {
        // Здесь можно добавить проверку на корректность даты
    }

    static bool isValidTime(int hour, int minute, int second) {
        // Здесь можно добавить проверку на корректность времени
    }

    static DateTime currentDateTime() {
        return DateTime();
    }

    std::string toString(const std::string& format) const {
        std::stringstream ss;
        ss << std::put_time(toTm(), format.c_str());
        return ss.str();
    }

    static DateTime fromString(const std::string& datetime, const std::string& format) {
        std::tm tm = {};
        std::stringstream ss(datetime);
        ss >> std::get_time(&tm, format.c_str());
        return DateTime(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }

    // Здесь можно добавить методы addSecs(), addMinutes(), addDays(), addMonths(), addYears()
    // и методы daysTo() и secsTo()

private:
    Date _date;
    Time _time;

    std::tm* toTm() const {
        static std::tm tm = {};
        tm.tm_mday = _date.day;
        tm.tm_mon = _date.month - 1;
        tm.tm_year = _date.year - 1900;
        tm.tm_hour = _time.hour;
        tm.tm_min = _time.minute;
        tm.tm_sec = _time.second;
        return &tm;
    }
};

#endif