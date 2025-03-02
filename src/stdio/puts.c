#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

// Pentru implementare gasesc lungimea sirului dat pentru ca apoi sa
//ma folosesc de functia write implementata ce are ca parametrii flag-ul
//1, string-ul si lungimea acestuia. Apelez aceasta functie de 2 ori pentru
//a pune si caracterul "\n".
int puts(const char *buf){
    int len = 0;
    while (buf[len] != '\0'){
        len++;
    }
    write(1, buf, len);
    write(1, "\n", 1);
    return 1;
}
