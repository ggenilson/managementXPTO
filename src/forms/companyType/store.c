int CTStore () {	
	setbuf(stdin, NULL);
	fflush(stdin);
	
    struct company {
    	int id;
        char type[100];
    } cn;

    puts("Tipo da Empresa:");
    gets(cn.type);
    
    FILE *file, *fileReader;
    
    file = fopen(pathCompanyType, "a");
    fileReader = fopen(pathCompanyType, "r");
    
    setbuf(stdin, NULL);
	fflush(stdin);
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	cn.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s\n", cn.id, cn.type);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
