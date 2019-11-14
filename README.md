### Keys:
+ $./make -I
+ $./make -l
+ $./make -o
+ $./make -v
+ $./make -h

### Short and long form of the sample key
+ "-I" = "--no-index"
+ "-l" = "--language"
+ "-o" = "--output"
+ "-o" = "--verbose"
+ "-h" = "--help"

### Some keys may take different value as an additional key parameters:
1. "-l"/"--language" ***can*** be with an additional key parameters like "-l10"; "-l=10" or can be without value "-l". The same with long key.
    #### Result:
    ```
    $./make -l
    found argument "language = (NULL)"
    $./make -l10
    found argument "language = 10"
    ```
2. "-o"/"--output" ***must*** be with an additional key parameters.
    #### Result:
    ```
    $./make -o
    ./main: invalid option -- 'o'
    $./make -o10
    found argument "output = 10"
    ```    
