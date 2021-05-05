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

//Fun��o que traz o �ltimo ID em um ficheiro
int getNewID (char str[], FILE *fileReader) {
	int i, j, counter = 0, id = 0;
	char aux[200];
	
	printf("-------------------------------------------------\n");
	
	while (fgets(str, 200, fileReader)) {
		printf("%s\n", str);
		counter = 0;
		
		
		//Percorrendo cada linha do arquivo
		for (i = 0; i < sizeOfString(str); i++) {
			aux[counter] = str[i];
			counter++;
			
			char aux1[counter - 1];
			
			if (str[i] == '#') {
				printf("Texto a percorrer: %s\n", aux);
				for (j = 0; j < counter; j++) {
					if (aux[j] == '#') {
						break;
					}
					
					printf("%c - ", aux[j]);
					aux1[j] = aux[j];
				}
				
				printf("\nString: %s\n", aux1);
				
				id = (int)aux1;
				
				printf("\nNumero: %d\n", id);
				
				break;
			}
		}
	}
	
	printf("\n ---  %d --- \n", &counter);
	
	printf("-------------------------------------------------\n");
	
	return id + 1;
}
