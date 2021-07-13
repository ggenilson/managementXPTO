int Wpdel () {
	int id;
	
	printf("Especifique o código do Posto de Trabalho, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathComponent, pathOperation };
	char *error[] = { "Componente",  "Operação" };
	int pos[] = { 9, 3 };
	
	return removeFieldFK(pathWorkPlace, id, 6, pathsJoin, 2, error, pos);
}
