void Components () {
    struct component {
        char designation[100];
        int serieNumber;
    } cp;

    printf("Designa��o: \n");
    scanf("%s", cp.designation);

    printf("\n%s\n", cp.designation);
}
