int CTdel () {
	int id;
	
	printf("Especifique o c�digo do Tipo da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathCompanyType, id, 2);
}
