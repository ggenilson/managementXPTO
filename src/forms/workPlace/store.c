int WpStore () {	
	setbuf(stdin, NULL);
	
    struct workplace {
    	int id;
        char designation[100];
        char place[100];
        char section[100];
        char desc[100];
        int idEmploye;
        char *status;
    } wp;
    
    int values[] = { 1 };

    printf("Designação: ");
    gets(wp.designation);
    setbuf(stdin, NULL);
    
    printf("Local: ");
    gets(wp.place);
    setbuf(stdin, NULL);
    
    printf("Secção: ");
    gets(wp.section);
    setbuf(stdin, NULL);
    
    printf("Descrição:\n");
    gets(wp.desc);
    setbuf(stdin, NULL);
    
    puts("Selecione o Funcionário:");
    wp.idEmploye = getFK(pathEmploye, values, 1, 4);
    
    wp.status = getStatus(1);
    
    FILE *file, *fileReader;
    
    file = fopen(pathWorkPlace, "a");
    fileReader = fopen(pathWorkPlace, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	wp.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s#%s#%s#%d>#%s\n", wp.id, wp.designation, wp.place, wp.section, wp.desc, wp.idEmploye, wp.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
