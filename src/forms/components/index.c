int CpgetComponents () {
	char * fields[] = { 
		"ID", 
		"DESIGN",
		"NSÉRIE",
		"AQUIS.", 
		"GARANT", 
		"FORNEC", 
		"FABRIC", 
		"TCOMPO", 
		"CONDIC", 
		"POSTO", 
		"OBSERV", 
		"ESTADO" 
	};
	
	char *fks[] = { 
		pathCompany, 
		pathCompany, 
		pathComponentType, 
		pathWorkPlace 
	};
	
	int fksFieldsShow[] = { 1, 1, 1, 1 };
	int endLineFK[] = { 3, 3, 2, 6 };
	
	return getEntityFK(fields, pathComponent, 11, fks, fksFieldsShow, endLineFK);
}
