int Cdel () {
	int id;
	
	printf("Especifique o código da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathComponent, pathComponent, pathOperation };
	char *error[] = { "Componente", "Componente", "Operação" };
	int pos[] = { 5, 6, 5 };
	
	return removeFieldFK(pathCompany, id, 3, pathsJoin, 2, error, pos);
}
