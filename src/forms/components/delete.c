int Cpdel () {
	int id;
	
	printf("Especifique o c�digo do Componente, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathOperation };
	char *error[] = { "Opera��o" };
	int pos[] = { 4 };
	
	return removeFieldFK(pathComponent, id, 11, pathsJoin, 1, error, pos);
}
