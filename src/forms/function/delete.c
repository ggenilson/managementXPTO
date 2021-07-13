int Fcdel () {
	int id;
	
	printf("Especifique o código da Função, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathEmploye };
	char *error[] = { "Funcionário" };
	int pos[] = { 2 };
	
	return removeFieldFK(pathFunction, id, 2, pathsJoin, 1, error, pos);
}
