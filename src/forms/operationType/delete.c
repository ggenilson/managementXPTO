int Opdel () {
	int id;
	
	printf("Especifique o código do Tipo da Operação, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathOperation };
	char *error[] = { "Operação" };
	int pos[] = { 6 };
	
	return removeFieldFK(pathOperationType, id, 2, pathsJoin, 1, error, pos);
}
