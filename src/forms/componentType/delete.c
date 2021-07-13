int CpTdel () {
	int id;
	
	printf("Especifique o código do Tipo do Componente, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathComponent };
	char *error[] = { "Componente" };
	int pos[] = { 7 };
	
	return removeFieldFK(pathComponentType, id, 2, pathsJoin, 1, error, pos);
}
