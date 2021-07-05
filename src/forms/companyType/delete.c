int CTdel () {
	int id;
	
	printf("Especifique o código do Tipo da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathCompanyType, id, 2);
}
