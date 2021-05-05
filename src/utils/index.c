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

//Fun��o que traz o �ltimo ID em um ficheiro
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
	
	printf("\nAinda pretende 'ELIMINAR'?\n(s/n)\n");
	scanf(" %c", &ans);
	
	return ans;
}
