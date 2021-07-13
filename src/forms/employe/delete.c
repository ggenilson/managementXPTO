int Epdel () {
	int id;
	
	printf("Especifique o código do Funcionário, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathWorkPlace, pathOperation };
	char *error[] = { "Posto de Trabalho",  "Operação" };
	int pos[] = { 5, 10 };
	
	return removeFieldFK(pathEmploye, id, 4, pathsJoin, 2, error, pos);
}
