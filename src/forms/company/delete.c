int Cdel () {
	int id;
	
	printf("Especifique o c�digo da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathComponent, pathComponent, pathOperation };
	char *error[] = { "Componente", "Componente", "Opera��o" };
	int pos[] = { 5, 6, 5 };
	
	return removeFieldFK(pathCompany, id, 3, pathsJoin, 2, error, pos);
}
