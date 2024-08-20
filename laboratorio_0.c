#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s data\n", argv[0]);
        return 1;
    }
    else {
        for ( int i = 0 ; i < argc ; i++ ){
            printf("Los parametros son:%s\n", argv[i]);
        }
        printf("Fin\n");
    }
    printf("You entered: %s\n", argv[1]); // Output



    int num;
    printf("Enter an integer: "); // Output
    scanf("%d", &num); // Input
    printf("You entered: %d\n", num); // Output

    char name[50]; // Assuming the maximum length of the name is 50 characters
    printf("Enter your name: ");
    scanf("%s", name); // Note that there's no '&' before 'name' because arrays decay to pointers
    printf("Hello, %s!\n", name);

    //string.h
    char str1[20] = "Hello";
    char str2[20] = "World";
    char result[40];

    strcpy(result, str1); // Copying str1 to result
    strcat(result, " "); // Concatenating a space
    strcat(result, str2); // Concatenating str2 to result

    printf("Result: %s\n", result);

    int length = strlen(result); // Getting the length of the string
    printf("Length of the result: %d\n", length);

    int option;
    option = 3;
    while ( option > 0) {
        printf("%s\n", result);
        option--;
    }
    for ( int i = 0 ; i < 3 ; i++ ){
        printf("*\n");
    }
    return 0;
}
