#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void start_message()
{
    printf("Welcome!\n\tCLI Calculator\n\
====================================\n\
usage: [number] [operation] [number]\n\
Commands:\n\
\n\
+\tsummation\n\
-\tsubtraction\n\
*\tmultiplication\n\
/\tdivision\n\
%\tdivision with remainder\n\
^\tsquaring\n\
<\tsquare root\n\
log\tlogarithm\n\
log\tlogarithm\n\
hexto\thexadecimal to bin or dec\n\
decto\tdecimal to bin or hex\n\
====================================\n\
exit\texiting from the program\n\
clear\tclear the screen\n\
help\tprint usage\n\
====================================\n\
Hit enter to start!\n\
====================================\n");
}
