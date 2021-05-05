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
     
    // Terminador de string
    //sub[j] = '&#092;&#048;';
     
    return sub;
}

//Função que traz o último ID em um ficheiro
int getNewID (char str[], FILE *fileReader) {
	int i, j, counter = 0, id = 0;
	char aux[200];
	
	while (fgets(str, 200, fileReader)) {
		counter = 0;

		char * found = strchr(str, '#');
		int index = found ? found - str : -1;
		
		char * aux1 = substring(str, 0, index);
		id = atoi(aux1);
	}
	
	return id + 1;
}
