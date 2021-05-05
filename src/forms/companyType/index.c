int getCompanyTypes () {
	char * fields[] = { "ID", "TIPO" };
	char * sub;
	int i, cont = 0;
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
    
    if (!input) {
    	return 0;
	}
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    
    for (i = 0; i < 2; i++) {
    	printf("%s\t\t", fields[i]);
	}
    
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    
	    while (sub) {
	    	printf("%s\t\t", sub);
	    	sub = strtok(NULL, "#");
		}
		
		printf("\n");
		
		cont++;
    }
    
    fclose(input);
    
    printf(cont > 0 ? "Tabela não possui algum dado ...\n" : "");
    
    system("pause");
	
	return 1;
}
