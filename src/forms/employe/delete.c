int Epdel () {
	int id;
	
	printf("Especifique o c�digo do Funcion�rio, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathWorkPlace, pathOperation };
	char *error[] = { "Posto de Trabalho",  "Opera��o" };
	int pos[] = { 5, 10 };
	
	return removeFieldFK(pathEmploye, id, 4, pathsJoin, 2, error, pos);
}
