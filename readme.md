# Runtimer

A simple Windows command line utility for the accurate measurement of program execution time.

## Example

```
C:\>runtimer ver

Microsoft Windows [Version 6.1.7601]

Time: 3.5380 ms

C:\>
```

## Features

* Uses the high-frequency clock (QueryPerformanceCounter).
* Automatically chooses the units of time (hours/mins/s/ms/us/ns) such that the output value is greater than 1 unit.

## Notes

The method used to launch the specified program allows for pass-through standard input/ouput. There appears to be an overhead of ~3 ms associated with this approach. Runtimer does not attempt to compensate for this overhead.

