# Base Converter

>A CLI based program to convert number from one base to another. 
---
Help:
```powershell
basecon -h
```
Output:
```

Usage: basecon --to.<Base> <value>
|CLI options|:-
        d - Converts the given value into integer value.
        b - Converts the given value into binary value.
        o - Converts the given value into octal value.
        x - Converts the given value into hexadecimal value.
```
---
### Examples:

>Bin to Hex &#x21B4;
```powershell
basecon -x 0b1111
```
<br>

>Hex to Int &#x21B4;
```powershell
basecon -d 0x2F
```
<br>

>Int to Oct &#x21B4;
```powershell
basecon -o 47
```
<br>

>Oct to Bin &#x21B4;
```powershell
basecon -b 0o17
```
___

>Note: only works till UINT_MAX value (will be buffing it soon.)