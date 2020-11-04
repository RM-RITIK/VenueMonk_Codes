#include <iostream>
using namespace std;

const unsigned int Sunday = 1;
unsigned int getWeekday(unsigned long long year, unsigned int month, unsigned int day)
{
  if (month <= 2)
  {
    month += 12;
    year--;
  }

  return (day +
          13 * (month + 1) / 5 +
          year + year / 4 - year / 100 + year / 400)
         % 7;
}

int main()
{
    unsigned long long year1, year2;
    unsigned int month1, month2, day1, day2;
    year1 = 1901;
    year2 = 2000;
    month1 = 1;
    month2 = 12;
    day1 = 1;
    day2 = 31;
    if (year2 < year1 || (year2 == year1 && month2 < month1))
    {
      swap(year1,  year2);
      swap(month1, month2);
    }

    unsigned long long currentYear  = year1;
    unsigned int       currentMonth = month1;
    if (day1 > 1)
    {
      currentMonth++;
      if (currentMonth > 12)
      {
        currentMonth -= 12;
        currentYear++;
      }
    }

    unsigned int sum = 0;

    while (currentYear + 2800 < year2)
    {
      currentYear += 2800;
      sum += 4816;         
    }
    while (currentMonth < month2 || currentYear < year2)
    {
      if (getWeekday(currentYear, currentMonth, 1) == Sunday)
        sum++;

      currentMonth++;

      if (currentMonth > 12)
      {
        currentMonth -= 12;
        currentYear++;
      }
    }
    if (getWeekday(currentYear, currentMonth, 1) == Sunday)
      sum++;

    cout << sum << endl;
  return 0;
}

