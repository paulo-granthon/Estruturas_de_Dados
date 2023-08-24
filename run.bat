@echo off

setlocal

set input_num=%1

set file_to_compile=src\%input_num%_*.c

if exist %file_to_compile% (
    for %%F in (%file_to_compile%) do (
        set "file_name=%%~nF"
    )

    if not exist compiled (
        mkdir compiled
    )

    gcc -g %file_to_compile% -o compiled\%file_name%
    compiled\%file_name%
) else (
    echo Invalid or non-existent numeric input.
    echo Please provide a number that corresponds to the first character of the name of one of the available files.
    echo Example: run.bat 1
    echo Available files:
    for %%F in (src\*_*.c) do (
        echo %%~nxF
    )
)

endlocal

