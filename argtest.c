#include <stdio.h>

int main(int argc, char *argv[]) {
    // argc: 引数の数
    printf("Number of arguments (argc): %d\n", argc);

    // argv: 引数の内容
    printf("Arguments (argv):\n");
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
