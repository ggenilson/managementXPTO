int Fcdel () {
	int id;
	
	printf("Especifique o c�digo da Fun��o, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathEmploye };
	char *error[] = { "Funcion�rio" };
	int pos[] = { 2 };
	
	return removeFieldFK(pathFunction, id, 2, pathsJoin, 1, error, pos);
}
