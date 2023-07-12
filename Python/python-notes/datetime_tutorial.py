import time
from datetime import datetime, date, timedelta , time as dtime
from calendar import monthrange

if __name__ == "__main__":
    start_date = date(2017, 3, 1)
    end_date = date(2017, 3, 2)
    print(type(start_date))
    print('start_date: {}'.format(start_date))
    # total_seconds()
    total_time = (end_date - start_date).total_seconds()
    print('total_time: {}'.format(total_time))

    # timedelta
    print('timedelta : {}'.format(timedelta(hours=28)))

    now = datetime.now()
    print('now: {}'.format(now))
    yestoday = now - timedelta(days=1)
    print('yestoday: {}'.format(yestoday))

    # datetime.combine
    combine_time = datetime.combine(date(2017, 3, 1), dtime(18, 23, 50))
    print('combine_time: {}'.format(combine_time))
    combine_time_2 = datetime.combine(date(2017, 3, 1), dtime.max)
    print('combine_time_2: {}'.format(combine_time_2))

    # strftime ref. http://strftime.org/
    DATETIME_FORMAT = '%m/%d/%Y %I:%M %p'
    format_time = combine_time.strftime(DATETIME_FORMAT)
    print('type: {}'.format(type(format_time)))
    print('method 1 :format_time: {}'.format(format_time))
    print('method 2 :format_time: {:%m/%d/%Y %I:%M %p}'.format(combine_time))
    print('method 3 :format_time: {:{}}'.format(combine_time, DATETIME_FORMAT))

    # monthrange(year, month)
    # Returns weekday of first day of the month and number of days in month, for the specified year and month.
    first_day, num_days = monthrange(2017, 4)
    # 0-6 ~ Mon-Sun
    print('first_day: {}'.format(first_day))
    # number of days in month
    print('num_days: {}'.format(num_days))

    # isocalendar
    today = date.today()
    print('today:', today)
    print(today.isocalendar())
    print(today.isocalendar()[1]) # 第幾周

    # datetime -> timestamp(10-digit)
    # time.mktime(t)
    # Its argument is the struct_time or full 9-tuple and it returns a floating point number,
    # for compatibility with time().
    timestamp = time.mktime(now.timetuple())
    print('timestamp : {}'.format(timestamp))

    # timestamp(10-digit) -> datetime
    datetime_date = datetime.fromtimestamp(timestamp)
    print('datetime : {}'.format(datetime_date))

    # millisecond-precise timestamp(13-digit) -> datetime
    timestamp = 1671094228814 # 13-digit
    datetime_date = datetime.fromtimestamp(int(timestamp)/1000)
    print('datetime : {}'.format(datetime_date))