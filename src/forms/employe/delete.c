int Epdel () {
	int id;
	
	printf("Especifique o c�digo do Funcion�rio, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathEmploye, id, 4);
}
