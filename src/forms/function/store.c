int FcStore () {	
	setbuf(stdin, NULL);
	
    struct function {
    	int id;
        char function[100];
        char *status;
    } fc;

    printf("Função: ");
    gets(fc.function);
    setbuf(stdin, NULL);
    
    fc.status = getStatus(1);
    
    FILE *file, *fileReader;
    
    file = fopen(pathFunction, "a");
    fileReader = fopen(pathFunction, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	fc.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s\n", fc.id, fc.function, fc.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
