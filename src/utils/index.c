//Função que ordena um vetor
void sort(int vetorN[], int size){
	int i, j;
	int aux;
	
	for(i = 0; i < size; i++) {
	    for(j = 0; j < size - 1; j++) {
	        if(vetorN[j] > vetorN[j + 1]) {
	            aux = vetorN[j];
	            vetorN[j] = vetorN[j + 1];
	            vetorN[j + 1] = aux;
	        }
	    }
	}
}

//Função que verifica se um valor contém em um Array
int contains (int vetorN[], int val, int size) {
	int i, pos = -1;
	
	for(i = 0; i < size; i++)
	{
	    if (vetorN[i] == val) {
	    	pos = i;
	    	break;
		}
	}
	
	return pos;
}

//Função responsável por terminar ou não a aplicação
void exitApplication () {
    char answer;
	printf("\nTem certeza que quer sair da aplicação?\n(s/n)\n");
	scanf(" %c", &answer);

    if (answer == 's' || answer == 'S') {
		exit(1);
	} else {
		system("cls");
	}
}

//Função responsável por enviar uma sms para o usuário e retornar a resposta
int getAnswer (char sms[]) {
	char ans;
	
	printf("%s\n(s/n)\n", sms);
	scanf(" %c", &ans);
	
	if (ans == 's' || ans == 'S') {
		return 1;
	} else {
		return 0;
	}
}

//Função responsável por validar uma resposta do usuário
int getQuestion (int number) {
	printf("\nOpção inválida\n\n");

	if (getAnswer(sms)) {
		system("cls");
		
		return 1;
	} else {
		if (number) {
			exit(1);
		} else {
			system("cls");
			
			return 10;
		}
	}
}

//Funcão responsável por colocar tela cheia
void fullScreen () {
	keybd_event ( VK_MENU, 0x36, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
}

//Função Responsável por contar uma string, poderia também se utilizar o strlen.
int sizeOfString (char string[]) {
	int counter = 0;
	
	while (string[counter] != '\0') {
		++counter;
	}
	
	return counter + 1;
}

//Função para pegar substring
char * substring (char str[], int start, int end) {
    int i, j;
    char * sub; 
     
    // Verifica valores incompatíveis e 
    // retorna NULL
    if(start >= end || end > strlen(str)) {
        return NULL;
    }
     
    // Aloca memória para a substring
    sub = (char *) malloc(sizeof(char) * (end - start + 1));
     
    // Copia a substring para a variável
    for(i = start, j = 0; i < end; i++, j++) {
        sub[j] = str[i];
    }
     
    return sub;
}

//Função que retorna o último ID em um ficheiro
int getNewID (char str[], FILE *fileReader) {
	int id = 0, index;
	char * aux, * found;
	
	while (fgets(str, 200, fileReader)) {
		found = strchr(str, '#');
		index = found ? found - str : -1;
		
		aux = substring(str, 0, index);
		id = atoi(aux);
	}
	
	return id + 1;
}

char getAnswerColor(int res, char * s1, char * s2) {
	setbuf(stdin, NULL);
	char ans;
	
	if (res) {
		textcolor(BLUE);
		printf("\n%s\n", s1);
	} else {
		textcolor(RED);
		printf("\n%s\n", s2);
	}
	
	textcolor(GREEN);
	
	printf("\nPretende executar a acção mais uma vez?\n(s/n)\n");
	scanf(" %c", &ans);
	setbuf(stdin, NULL);
	
	return ans;
}

char getNormalAnswer () {
	setbuf(stdin, NULL);
	char ans;
	
	printf("\nPretende executar acção mais uma vez?\n(s/n)\n");
	scanf(" %c", &ans);
	setbuf(stdin, NULL);
	
	return ans;
}

void auxGetEntityFK (FILE *fr, char title[], int aux, int otherField, int fieldSize) {
	char lFK[1001] = "", copy[1001] = ""; 
	char *subFK;
	int k1, helper;
	
	while(fgets(lFK, 1001, fr)) {
		strcpy(copy, lFK);
		subFK = strtok(lFK, "#");
		
		if (aux == atoi(subFK)) {
			k1 = 1;
			helper = 0;
		
			while(subFK) {
				subFK = strtok(NULL, "#");
				if (k1 == fieldSize) {
					if (strcmp(subFK, "Inactivo\n") == 0) {
						helper = 1;
					}
					
					break;
				}
				
				k1++;
			}
			
			k1 = 1;
			subFK = strtok(copy, "#");
			
			while(subFK) {
				subFK = strtok(NULL, "#");
				
				if (k1 == otherField) {
					if (subFK) {
						if (helper) textcolor(RED);
						printf("|%s\t\t%s\n", title, subFK);
						textcolor(GREEN);
					}
					
					break;
				}
			}
		}
		
		memset(lFK, 0, sizeof(char) * 1001);
	}
}

int getEntityFK (char *fields[], char *fileReader, int fieldSize, char *fks[], int fksFieldsShow[], int endLineFK[]) {
	char *sub;
	int i, cont = 0, k;
	
	//Arquivo de entrada
	FILE *input = fopen(fileReader, "r");
	FILE *inp;
    
    if (!input) {
    	return 0;
	}
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    char *found, *aux;
    int index, startFK, ver1;
    
    while(fgets(lineText, 1001, input)) {
    	ver1 = strstr(lineText, "Activo\n") - lineText;
    	
    	if (ver1 > -1) {
    		sub = strtok(lineText, "#");
		    k = 1;
		    startFK = 0;
		    
		    printf("-----------------------------------------------\n");
	    
		    printf("|%s\t\t%s\n", fields[0], sub);
		    
		    while (sub) {
		    	sub = strtok(NULL, "#");
		    	
		    	if (sub) {
		    		//Verificando se existe chave secundária
		    		if (strchr(sub, '>') - sub > -1) {
		    			found = strchr(sub, '>');
						index = found ? found - sub : -1;
		    			aux = substring(sub, 0, index);
		    			inp = fopen(fks[startFK], "r");
		    			
		    			auxGetEntityFK(inp, fields[k], atoi(aux), fksFieldsShow[startFK], endLineFK[startFK]);
		    			startFK++;
					} else {
						if (k < fieldSize - 1) {
		    				printf("|%s\t\t%s\n", fields[k], sub);
						} else {
							printf("|%s\t\t%s", fields[k], sub);
						}
					}
					
		    		k++;
				}
			}
			
			fclose(inp);
			cont++;	
		}
		
		memset(lineText, 0, sizeof(char) * 1001);
    }
    
    fclose(input);
    
    printf(cont == 0 ? "Tabela não possui algum dado ...\n" : "-----------------------------------------------\n");
    
    system("pause");
	
	return 1;
}

int getEntity (char *fields[], char *fileReader, int fieldSize) {
	char * sub;
	int i, cont = 0, k, helper;
	
	//Arquivo de entrada
	FILE *input = fopen(fileReader, "r");
    
    if (!input) {
    	return 0;
	}
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "", copy[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
    	strcpy(copy, lineText);
	    sub = strtok(lineText, "#");
	    k = 1;
	    helper = 0;
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
				
				if (k == fieldSize) {
					if (strcmp(sub, "Activo\n") == 0) {
						helper = 1;
					}
				}
			}
		}
		
		if (helper) {
			k = 0;
			sub = strtok(copy, "#");
			
			printf("-----------------------------------------------\n");
	    
		    printf("|%s\t\t%s\n", fields[0], sub);
		    
		    while (sub) {
		    	sub = strtok(NULL, "#");
		    	
		    	if (sub) {
		    		k++;
		    		
		    		if (k < fieldSize - 1) {
		    			printf("|%s\t\t%s\n", fields[k], sub);
					} else {
						printf("|%s\t\t%s", fields[k], sub);
					}
				}
			}
			
			cont++;
		}
    }
    
    fclose(input);
    
    if (cont > 0) {
    	 printf("-----------------------------------------------\n");
	} else {
		textcolor(RED);
		printf("Tabela não possui algum dado ...\n");
		textcolor(GREEN);
	}
    
    system("pause");
	
	return 1;
}

int getEntitySearch (char *fields[], char *fileReader, int fieldSize, int fieldsToSearch[], int sizeFields, char val[]) {
	char *sub, copy[1001];
	int i, cont = 0, k, helper;
	
	//Arquivo de entrada
	FILE *input = fopen(fileReader, "r");
    
    if (!input) {
    	return 0;
	}
	
	sort(fieldsToSearch, sizeFields);
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    int index, ver,ver1, all;
    
    strlwr(val);
    
    while(fgets(lineText, 1001, input)) {
    	ver1 = strstr(lineText, "Activo\n") - lineText;
	    
    	if (ver1 > -1) {
    		strcpy(copy, lineText);
	    	strlwr(lineText);
		    sub = strtok(lineText, "#");
		    k = 0;
		    all = 0;
		    helper = 0;
		    
		    index = contains(fieldsToSearch, k, sizeFields);
			all = contains(fieldsToSearch, fieldSize, sizeFields);
			
			if (index != -1 || all != -1) {
				ver = strstr(sub, val) - sub;
		    
			    if (ver > -1) {
			    	helper = 1;
			    }
			}
		
			k++;
	    
		    while (sub) {
		    	sub = strtok(NULL, "#");
		    	
		    	if (sub && k != 0) {
		    		index = contains(fieldsToSearch, k, sizeFields);
		    		
		    		if (index != -1 || all != -1) {
		    			ver = strstr(sub, val) - sub;
		    
					    if (ver > -1) {
					    	helper = 1;
					    }
					}
					
		    		k++;
				}
			}
		
			if (helper) {
				k = 0;
				sub = strtok(copy, "#");
				cont++;
				
				printf("-----------------------------------------------\n");
		    	printf("|%s\t\t%s\n", fields[k], sub);
		    	
		    	k++;
		    	
		    	while (sub) {
		    		sub = strtok(NULL, "#");
		    		
		    		if (sub && k != 0) {
		    			if (k < fieldSize - 1) {
		    				printf("|%s\t\t%s\n", fields[k], sub);
						} else {
							printf("|%s\t\t%s", fields[k], sub);
						}
						
						k++;
					}
				}
			}
		}
    }
    
    printf(cont > 0 ? "-----------------------------------------------\n" : "");
    
    fclose(input);
    
    textcolor(RED);
    printf(cont == 0 ? "Tabela não possui algum dado ...\n\n" : "\n");
    textcolor(GREEN);
	
	return 1;
}

int removeField (char *path, int id, int length) {
	//Arquivo de entrada
	FILE *input = fopen(path, "r");
	
	//Arquivo de saída
    FILE *output = fopen("helpful.txt", "w+");
    
    if (!input || !output) {
    	return 5;
	}
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "", copy[1001] = "", copy1[1001] = "";
    
    int index, idCompare, ret = 0, helper;
	char * aux, * found, *sub, k;
	
    while(fgets(lineText, 1001, input)) {
    	strcpy(copy, lineText);
    	strcpy(copy1, lineText);
    	sub = strtok(lineText, "#");
    	
    	helper = 0;
    	k = 0;
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
				
				if (k == length) {
					if (strcmp(sub, "Activo\n") == 0) {
						helper = 1;
					} else {
						fputs(copy, output);
					}
				}
			}
		}
		
		if (helper) {
			sub = strtok(copy1, "#");
			
			if (id == atoi(sub)) {
				fprintf(output, "%d#", id);
				k = 0;
				
				while(sub) {
					sub = strtok(NULL, "#");
					if (sub) {
						k++;
				
						if (k == length) {
							fprintf(output, "Inactivo\n");
						} else {
							fprintf(output, "%s#", sub);
						}
					}
				}
				
				ret = 1;
			} else {
				fputs(copy, output);
			}
		}
        
        memset(lineText, 0, sizeof(char) * 1001);
    }
    
    fclose(input);
    fclose(output);
    
    remove(path);
    rename("helpful.txt", path);
    
    return ret;
}

char * getStatus (int type) {
	setbuf(stdin, NULL);
	
	int status;
	
	do {
		printf("\nSelecione o estado:");
		printf("\n0 - Inactivo\n1 - Activo\nOpção (0 ou 1):\n");
		
		scanf("%d", &status);
		setbuf(stdin, NULL);
	} while(status != 0 && status != 1);
	
	if (!type) {
		return status == 1 ? "Activo\n" : "Inactivo\n";
	} else {
		return status == 1 ? "Activo" : "Inactivo";
	}
}

int getFK (char *path, int valuesToGet[], int sizeValuesToGet, int endLine) {
	setbuf(stdin, NULL);
	char * sub, copy[1001];
	int ver, cont = 0, k, helper, vetId[1001], contVetId = 0;
	int contH = 0, val;
	
	//Arquivo de entrada
	FILE *input = fopen(path, "r");
	
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
    	strcpy(copy, lineText);
	    sub = strtok(lineText, "#");
	    k = 0;
	    helper = 0;
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
				
				if (k == endLine) {
					if (strcmp(sub, "Activo\n") == 0) {
						helper = 1;
					}
				}
			}
		}
		
		if (helper) {
			k = 0;
			sub = strtok(copy, "#");
			printf("%s - ", sub);
			
			vetId[contVetId] = atoi(sub);
			contVetId++;
			contH++;
			
			while (sub) {
		    	sub = strtok(NULL, "#");
		    	
		    	if (sub) {
		    		k++;
		    		ver = contains(valuesToGet, k, sizeValuesToGet);
		    		
		    		if (ver > -1) {
		    			printf("%s\n", sub);
					}
				}
			}
		}
		
		cont++;
    }
    
    fclose(input);
    
    if (contH > 0) {
    	int h;
    	
    	do {
    		scanf("%d", &val);
    		setbuf(stdin, NULL);
    		h = contains(vetId, val, contVetId);
    		
    		if (h == -1) {
    			textcolor(RED);
    			printf("Erro: Escolha uma opção válida: ");
    			textcolor(GREEN);
			}
		} while(h == -1);
	}
    
    printf(cont == 0 ? "Tabela não possui algum dado ...\n" : "");
    
    return val;
}

int getFK1 (char *path, int valuesToGet[], int sizeValuesToGet, int idSearch, int PosId) {
	setbuf(stdin, NULL);
	char * sub, copy[1001];
	int ver, cont = 0, k, helper, vetId[1001], contVetId = 0;
	int contH = 0, val, ver1;
	
	//Arquivo de entrada
	FILE *input = fopen(path, "r");
	
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
    	ver1 = strstr(lineText, "Activo\n") - lineText;
	    
    	if (ver1 > -1) {
    		strcpy(copy, lineText);
		    sub = strtok(lineText, "#");
		    k = 0;
		    helper = 0;
	    
		    while (sub) {
		    	sub = strtok(NULL, "#");
		    	
		    	if (sub) {
		    		k++;
					
					if (k == PosId) {
						char *ch = strtok(sub, ">");
						
						if (atoi(ch) == idSearch) {
							helper = 1;
						}
					}
				}
			}
		
			if (helper) {
				k = 0;
				sub = strtok(copy, "#");
				printf("%s - ", sub);
				
				if (idSearch == atoi(sub)) {
					vetId[contVetId] = atoi(sub);
					contVetId++;
					contH++;
					
					while (sub) {
				    	sub = strtok(NULL, "#");
				    	
				    	if (sub) {
				    		k++;
				    		ver = contains(valuesToGet, k, sizeValuesToGet);
				    		
				    		if (ver > -1) {
				    			printf("%s\n", sub);
							}
						}
					}
				}
			}
			
			cont++;
    	}
    }
    
    fclose(input);
    
    if (contH > 0) {
    	int h;
    	
    	do {
    		scanf("%d", &val);
    		setbuf(stdin, NULL);
    		h = contains(vetId, val, contVetId);
    		
    		if (h == -1) {
    			textcolor(RED);
    			printf("Erro: Escolha uma opção válida: ");
    			textcolor(GREEN);
			}
		} while(h == -1);
	}
    
    printf(cont == 0 ? "Tabela não possui algum dado ...\n" : "");
    
    return val;
}

char *getDate (char *sms) {
	char day[4] = "", month[4] = "", year[10] = "", r[20] = "";
	char *newVal[20];
	
	do {
		printf("%s\n", sms);
		printf("\tDia: ");
		scanf("%s", day);
		setbuf(stdin, NULL);
		
		printf("\tMês: ");
		scanf("%s", month);
		setbuf(stdin, NULL);
		
		printf("\tAno: ");
		scanf("%s", year);
		setbuf(stdin, NULL);
		
		if (atoi(day) < 1 || atoi(day) > 31 || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1) {
			textcolor(RED);
			printf("Problema com os dados de entrada, verifique a data digitada!\n\n");
			textcolor(GREEN);
		}
	} while(atoi(day) < 1 || atoi(day) > 31 || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1);
	
	strcat(r, day);
	strcat(r, "-");
	strcat(r, month);
	strcat(r, "-");
	strcat(r, year);
	strcpy(newVal, r);
	
	printf("New = %s\n", r);
	printf("New Val = %s\n", newVal);
	
	return newVal;
}


