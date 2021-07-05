int Cdel () {
	int id;
	
	printf("Especifique o código da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathCompany, id, 3);
}
