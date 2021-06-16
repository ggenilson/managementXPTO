//Fun��o que ordena um vetor
void sort(int vetorN[], int size)
{
	int i, j;
	int aux;
	
	for(i = 0; i < size; i++)
	{
	    for(j = 0; j < size - 1; j++)
	    {
	        if(vetorN[j] > vetorN[j + 1])
	        {
	            aux = vetorN[j];
	            vetorN[j] = vetorN[j + 1];
	            vetorN[j + 1] = aux;
	        }
	    }
	}
}

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

//Fun��o respons�vel por terminar ou n�o a aplica��o
void exitApplication () {
    char answer;
	printf("\nTem certeza que quer sair da aplica��o?\n(s/n)\n");
	scanf(" %c", &answer);

    if (answer == 's' || answer == 'S') {
		exit(1);
	} else {
		system("cls");
	}
}

//Fun��o respons�vel por enviar uma sms para o usu�rio e retornar a resposta
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

//Fun��o respons�vel por validar uma resposta do usu�rio
int getQuestion (int number) {
	printf("\nOp��o inv�lida\n\n");

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

//Func�o respons�vel por colocar tela cheia
void fullScreen () {
	keybd_event ( VK_MENU, 0x36, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
}

//Fun��o Respons�vel por contar uma string, poderia tamb�m se utilizar o strlen.
int sizeOfString (char string[]) {
	int counter = 0;
	
	while (string[counter] != '\0') {
		++counter;
	}
	
	return counter + 1;
}

//Fun��o para pegar substring
char * substring (char str[], int start, int end) {
    int i, j;
    char * sub; 
     
    // Verifica valores incompat�veis e 
    // retorna NULL
    if(start >= end || end > strlen(str)) {
        return NULL;
    }
     
    // Aloca mem�ria para a substring
    sub = (char *) malloc(sizeof(char) * (end - start + 1));
     
    // Copia a substring para a vari�vel
    for(i = start, j = 0; i < end; i++, j++) {
        sub[j] = str[i];
    }
     
    return sub;
}

//Fun��o que retorna o �ltimo ID em um ficheiro
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
	char ans;
	
	if (res) {
		textcolor(BLUE);
		printf("\n%s\n", s1);
	} else {
		textcolor(RED);
		printf("\n%s\n", s2);
	}
	
	textcolor(GREEN);
	
	printf("\nPretende fazer mais uma vez?\n(s/n)\n");
	scanf(" %c", &ans);
	
	return ans;
}

int getEntity (char *fields[], FILE *fileReader, int fieldSize) {
	char * sub;
	int i, cont = 0, k;
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
    
    if (!input) {
    	return 0;
	}
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 1;
	    
	    printf("-----------------------------------------------\n");
	    
	    printf("|%s\t\t%s\n", fields[0], sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		if (k < fieldSize - 1) {
	    			printf("|%s\t\t%s\n", fields[k], sub);
				} else {
					printf("|%s\t\t%s", fields[k], sub);
				}
				
	    		k++;
			}
		}
		
		cont++;
    }
    
    printf("-----------------------------------------------\n");
    
    fclose(input);
    fclose(fileReader);
    
    printf(cont == 0 ? "Tabela n�o possui algum dado ...\n" : "");
    
    system("pause");
	
	return 1;
}

int getEntitySearch (char *fields[], FILE *fileReader, int fieldSize, char *fieldsEntity, int fieldsToSearch[], int sizeFields, char val[]) {
	char * sub;
	int i, cont = 0, k;
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
    
    if (!input) {
    	return 0;
	}
	
	sort(fieldsToSearch, sizeFields);
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    int ver, index;
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 1;
	    
	    index = contains(fieldsToSearch, k, sizeFields);
		
		if (index != -1) {
			ver = strstr(sub, val) - sub;
	    
		    if (ver > -1) {
		    	printf("-----------------------------------------------\n");
		    	printf("|%s\t\t%s\n", fields[0], sub);
			}
		}
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		index = contains(fieldsToSearch, k, sizeFields);
			
				if (index != -1) {
					ver = strstr(sub, val) - sub;
			    
				    if (ver > -1) {
				    	if (k < fieldSize - 1) {
			    			printf("|%s\t\t%s\n", fields[k], sub);
						} else {
							printf("|%s\t\t%s", fields[k], sub);
						}
					}
				}
				
	    		k++;
			}
		}
		
		cont++;
    }
    
    printf("-----------------------------------------------\n");
    
    fclose(input);
    fclose(fileReader);
    
    printf(cont == 0 ? "Tabela n�o possui algum dado ...\n" : "");
    
    system("pause");
	
	return 1;
}

char * getStatus () {
	setbuf(stdin, NULL);
	
	int status;
	
	do {
		printf("\nSelecione o estado:");
		printf("\n0 - Activo\n1 - Inactivo\nOp��o (0 ou 1):\n");
		
		scanf("%d", &status);
		setbuf(stdin, NULL);
	} while(status != 0 && status != 1);

	return status == 1 ? "Activo" : "Inactivo";
}
