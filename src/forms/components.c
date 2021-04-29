void Components () {
    struct component {
        char designation[100];
        int serieNumber;
    } cp;

    printf("Designação: \n");
    scanf("%s", cp.designation);

    printf("\n%s\n", cp.designation);
}
