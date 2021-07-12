int OpStore () {	
	setbuf(stdin, NULL);
	
    struct operation {
    	int id;
        char type[100];
        char *status;
    } op;

    puts("Tipo da Operação:");
    gets(op.type);
    setbuf(stdin, NULL);
    
    op.status = getStatus(1);
    
    FILE *file, *fileReader;
    
    file = fopen(pathOperationType, "a");
    fileReader = fopen(pathOperationType, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	op.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s\n", op.id, op.type, op.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
