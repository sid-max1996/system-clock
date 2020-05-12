# System Clock
Set system time, date and zone in os Windows.
By default, you can change the time only as administrator, so configuration via gpedit.msc is required.

## Usage

```javascript
  const displayRotate = require('display-rotate');
  // setDateAndTime(day, month, year, hour, minute, sec)
  const isSucc = systemClock.setDateAndTime(12, 5, 2020, 17, 0, 0); // set system date and time in utc
  // setDateAndTime(bias)
  isSucc = systemClock.setTimeZone(-120); // set timezone bias - utc offset in minutes
```
