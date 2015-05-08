# Runtimer

A simple Windows command line utility for accurate measurement of program execution time.

## Example

```
C:\>runtimer ver

Microsoft Windows [Version 6.1.7601]
Milliseconds: 3.4914

C:\>
```

## Features

* Uses the high-frequency clock (QueryPerformanceCounter).
* Automatically chooses the units of time (hours/minutes/seconds/milliseconds/microseconds) such that the output value is greater than 1 unit.

