int Cpdel () {
	int id;
	
	printf("Especifique o código do Componente, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathOperation };
	char *error[] = { "Operação" };
	int pos[] = { 4 };
	
	return removeFieldFK(pathComponent, id, 11, pathsJoin, 1, error, pos);
}
