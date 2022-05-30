#include <iostream>
#include <string>
#include <fstream>

typedef unsigned int uint;

std::ifstream DatabaseHandler;

// Оценка расходов студента, руб./ месяц на основе "статистических данных"

bool initDatabase() {
    // Инициализация базы данных
}

uint getOtherMontlyCosts(uint month, const std::string& city,
    uint age)
{
    /* Получаем из базы данных средние по региону затраты в данном месяце 
     для людей данного возраста
    (по остальным статьям кроме еды, транспорта и развлечений) */
}

uint getHomeFoodCost(const std::string& city) {
    // Получаем из базы данных средние по региону затраты на еду
}

uint getCinemaCost(const std::string& city, const std::string& cinema) {
    // Получаем из базы данных стоимость билета на вечерний сеанс в данном кинотетре
}

uint getCoffeeCost(const std::string& city, const std::string& coffee) {
    // Получаем из базы данных средний чек в данном баре
}

uint getWeekandCost(const std::string& city, const std::string& cinema,
                    const std::string& coffee) {
    /* По выходным дням расходы складываются из стоимости:
     - похода в кино (пешком)
     - похода  в кафе (пешком)
     - завтрака и обеда дома */

    return static_cast<uint>(0.66 * getHomeFoodCost(city) + 
        getCinemaCost(city, cinema) + getCoffeeCost(city, coffee) + 0.5);
}

uint getInstituteDinnerCost(const std::string& city, const std::string& institute) {
    // Получаем из базы данных среднюю стоимость обеда в столовой данного института
}

uint getTransportCost(const std::string& city, const std::string& homeAddress,
                      const std::string& institute) {
    // Получаем из базы данных стоимость кратчайшей дороги до инстиутта
}

uint getWorkdayCost(const std::string& city, const std::string& homeAddress,
                    const std::string& institute) {
   /* По рабочим дням расходы складываются из стоимости:
    - дороги до института и обратно 
    - обеда в институтской столовой
    - завтрака и обеда дома */

    return static_cast<uint>(2 * getTransportCost(city, homeAddress, institute) +
        getInstituteDinnerCost(city, institute) + 0.66 * getHomeFoodCost(city) + 0.5);
}

uint getWorkdays(uint month) {
   // Получаем из базы данных число рабочих дней данном в месяце
}

uint getDaysCount(uint month) {
    // Вычисляем количество дней в месяце
}

uint getCosts(uint month, const std::string& city, const std::string& homeAddress, 
              const std::string& institute, const std::string& cinema,
              const std::string& coffee, uint age) {
    /* Расходы:
     - по рабочим дням
     - по выходным дням
     - прочие расходы */

    const uint daysCount = getDaysCount(month);
    const uint workDays = getWorkdays(month);
    const uint weekends = daysCount - workDays;

    return workDays * getWorkdayCost(city, homeAddress, institute) +
           weekends * getWeekandCost(city, cinema, coffee) + 
           getOtherMontlyCosts(month, city, age);
}

std::string getCinema(const std::string& city) {
    // Аналогично getInstitute
}

std::string getCoffee(const std::string& city) {
    // Аналогично getInstitute
}

bool isInstitute(const std::string& city) {
    // Проверка: есть ли такой институт в этом городе?
}

std::string getInstitute(const std::string& city) {
    // Ввод названия института и проверка на корректность
}

bool isAddress(const std::string& city, const std::string& address) {
    // Проверка: есть ли такой адрес в этом городе?
}

std::string getAddress(const std::string& city) {
    // Запрашиваем ввод адреса
}

uint getAge() {
    // Запрашиваем ввод возраста
}

bool isCity(const std::string& city) {
    // Проверка: есть ли такой город в нашей базе данных?
}

std::string getCity() {
    // Запрашиваем ввод города
}

bool isMonth(int month) {
    // Проверка: может ли введенное число интерпретироваться как месяц?
}

uint getMonth() {
    // Запрашиваем ввод месяца для расчёта расходов 

    uint month = 0;
    while (!isMonth(month))
    {
        std::cout << "What month is it?" << std::endl;
        std::cin >> month;
    }

    return month;
}

int main() { 
    const uint month = getMonth();
    const uint age = getAge();
    const std::string city = getCity();
    const std::string homeAddress = getAddress(city);
    const std::string institute = getInstitute(city);
    const std::string coffee = getCoffee(city);
    const std::string cinema = getCinema(city);

    const uint montlyCosts = getCosts(month, city, homeAddress, institute, 
        cinema, coffee, age);

    std::cout << "Расходы в данном месяце: " << montlyCosts << std::endl;

    return 0;
}
