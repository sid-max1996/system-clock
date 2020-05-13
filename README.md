# System Clock
Set system clock time and date in os Windows. System time sets in utc.
By default, you can change the time only as administrator, so configuration via gpedit.msc is required.

## Usage

```javascript
  const systemClock = require('system-clock');
  // setDateAndTime(day, month, year, hour, minute, sec)
  const isSucc = systemClock.setDateAndTime(12, 5, 2020, 17, 0, 0);
```
