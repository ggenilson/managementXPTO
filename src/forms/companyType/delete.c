int CTdel () {
	int id;
	
	printf("Especifique o código do Tipo da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	char *pathsJoin[] = { pathCompany };
	char *error[] = { "Empresa" };
	
	return removeFieldFK(pathCompanyType, id, 2, pathsJoin, 1, error);
}
