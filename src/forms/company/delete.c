int Cdel () {
	int id;
	
	printf("Especifique o c�digo da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathCompany, id, 3);
}
