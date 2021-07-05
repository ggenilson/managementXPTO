int Epdel () {
	int id;
	
	printf("Especifique o código do Funcionário, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathEmploye, id, 4);
}
