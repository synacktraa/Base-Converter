# Base Converter

>A CLI based program to convert number from one base to another. 

Compile:

```powershell
gcc baseconv.c utils.c -o baseconv
```
---
Ask For Help:
```powershell
baseconv -h 'or' baseconv --help
```
Output:
```

Usage: baseconv --to.<Base> <value>
|CLI options|:-
        Base:
                Bin = Converts the given value into binary value.
                Int = Converts the given value into integer value.
                Hex = Converts the given value into hexadecimal value.
                Oct = Converts the given value into octal value.
```
---
## Few Examples:

>Bin to Hex &#x21B4;
```powershell
baseconv --to.Hex 0b1111
```
<br>

>Hex to Int &#x21B4;
```powershell
baseconv --to.Int 0x2F
```
<br>

>Int to Oct &#x21B4;
```powershell
baseconv --to.Oct 47
```
<br>

>Oct to Bin &#x21B4;
```powershell
baseconv --to.Bin 0o17
```
___
