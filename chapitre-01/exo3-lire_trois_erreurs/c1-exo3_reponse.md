    - retirer un point-virgule
c1-exo3_main.cpp:4:30: error: expected ';' after expression
    4 |     printf("Hello world !\n")
      |                              ^
      |                              ;
1 error generated.

    - écrire Printf au lieu de printf
c1-exo3_main.cpp:4:5: error: use of undeclared identifier 'Printf'; did you mean 'printf'?
    4 |     Printf("Hello world !\n");
      |     ^~~~~~
      |     printf
C:/msys64/ucrt64/include/stdio.h:350:5: note: 'printf' declared here
  350 | int printf (const char *__format, ...)
      |     ^
1 error generated.

    - retirer la ligne #include <cstdio>
c1-exo3_main.cpp:3:5: error: use of undeclared identifier 'printf'
    3 |     printf("Hello world !\n");
      |     ^~~~~~
1 error generated.
