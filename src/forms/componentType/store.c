int CpTStore () {	
	setbuf(stdin, NULL);
	
    struct company {
    	int id;
        char type[100];
        char *status;
    } cn;

    puts("Tipo do Componente:");
    gets(cn.type);
    setbuf(stdin, NULL);
    
    cn.status = getStatus(1);
    
    FILE *file, *fileReader;
    
    file = fopen(pathComponentType, "a");
    fileReader = fopen(pathComponentType, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	cn.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s\n", cn.id, cn.type, cn.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
