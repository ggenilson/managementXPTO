void CompanyTypeOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = CTStore();
			
			ans = getAnswerColor(res, storeCompanyType, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = CTupdate();
			
			ans = getAnswerColor(res, updateCompanyType, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = CTdel();
			
			ans = getAnswerColor(res, deleteCompanyType, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		getAll(option, crudOption, 1);
			
		res = CTgetCompanyTypes();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = CTsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
	
		
		getAll(option, crudOption, 1);
	}
}

//

void CompanyOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = CStore();
			
			ans = getAnswerColor(res, storeCompany, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = Cupdate();
			
			ans = getAnswerColor(res, updateCompany, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Cdel();
			
			ans = getAnswerColor(res, deleteCompany, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		getAll(option, crudOption, 1);
			
		res = CgetCompany();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = Csearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
	
		
		getAll(option, crudOption, 1);
	}
}

//

void ComponentTypeOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpTStore();
			
			ans = getAnswerColor(res, storeComponent, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpTupdate();
			
			ans = getAnswerColor(res, updateComponent, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpTdel();
			
			ans = getAnswerColor(res, deleteComponent, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		
		getAll(option, crudOption, 1);
		res = CpTgetComponentTypes();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpTsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}

//

void ComponentsOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpStore();
			
			ans = getAnswerColor(res, storeComponents, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpUpdate();
			
			ans = getAnswerColor(res, updateComponents, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Cpdel();
			
			ans = getAnswerColor(res, deleteComponents, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		
		getAll(option, crudOption, 1);
		res = CpgetComponents();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = CpTsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}

//

void FunctionOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = FcStore();
			
			ans = getAnswerColor(res, storeFunction, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = FcUpdate();
			
			ans = getAnswerColor(res, updateFunction, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Fcdel();
			
			ans = getAnswerColor(res, deleteFunction, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		
		getAll(option, crudOption, 1);
		res = FcgetFunction();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = Fcsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}

//

void EmployeOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = EpStore();
			
			ans = getAnswerColor(res, storeEmploye, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = Epupdate();
			
			ans = getAnswerColor(res, updateEmploye, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Epdel();
			
			ans = getAnswerColor(res, deleteEmploye, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		
		getAll(option, crudOption, 1);
		res = getEmployes();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = Fcsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}

//

void WorkPlaceOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = WpStore();
			
			ans = getAnswerColor(res, storeWorkPlace, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = Wpupdate();
			//system("pause");
			
			ans = getAnswerColor(res, updateWorkPlace, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Wpdel();
			
			ans = getAnswerColor(res, deleteWorkPlace, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		
		getAll(option, crudOption, 1);
		res = getWorkPlace();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = Fcsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}

//

void OperationTypeOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = OpStore();
			
			ans = getAnswerColor(res, storeOperationType, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = OpUpdate();
			//system("pause");
			
			ans = getAnswerColor(res, updateOperationType, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Opdel();
			
			ans = getAnswerColor(res, deleteOperationType, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		getAll(option, crudOption, 1);
		
		res = getOperationTypes();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = Opsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}

//

void OperationOptions (int option, int crudOption) {
	int res;
	char ans;
	
	if (crudOption == 1) {
		do {
			getAll(option, crudOption, 1);
			
			res = OptStore();
			
			ans = getAnswerColor(res, storeOperation, errStore);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 2) {
		do {
			getAll(option, crudOption, 1);
			
			res = OptUpdate();
			//system("pause");
			
			ans = getAnswerColor(res, updateOperation, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 3) {
		do {
			getAll(option, crudOption, 1);
			
			res = Optdel();
			
			ans = getAnswerColor(res, deleteOperation, globalNotFound);
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 4) {
		getAll(option, crudOption, 1);
		
		res = OpgetComponents();
		
		getAll(option, crudOption, 1);
	} else if (crudOption == 5) {
		do {
			getAll(option, crudOption, 1);
			
			res = Opsearch();
			
			ans = getNormalAnswer();
		} while(ans == 's' || ans == 'S');
		
		getAll(option, crudOption, 1);
	}
}
