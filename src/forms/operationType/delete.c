int Opdel () {
	int id;
	
	printf("Especifique o c�digo do Tipo da Opera��o, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathOperation };
	char *error[] = { "Opera��o" };
	int pos[] = { 6 };
	
	return removeFieldFK(pathOperationType, id, 2, pathsJoin, 1, error, pos);
}
