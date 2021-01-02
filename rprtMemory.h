/*
*------------------------------------------------
* rprtMemory.h
*------------------------------------------------
*
*	01 printer_i
*	02 printer_f
*
*/

//Function 01-------------------------------------
void reptMemory_Aristas(int **ptr_A, 
						int **ptr_B,
						int nElementos,
						size_t bloqmemA_sz,
						size_t bloqmemB_sz,
						int statusA,
						int statusB)
{ 
	char statusA_label [20] = Label_NO_ASSIGNED;
	char statusB_label [20] = Label_NO_ASSIGNED;
		
	printf("%s\n",TITLE_DIVLINESRT);
	printf("%s\n",TITLE_TBL_06 ); 
	if (statusA == int(AVAILABLE))
	{
		strcpy(statusA_label,Label_ASSIGNED);
		printf("1. Status: %s\n",statusA_label);
		printf("2. Buffer (bytes): %d\n",bloqmemA_sz);	
		printf("3. Elements: %d\n",nElementos);	
		printf("4. Integer size: %d\n", sizeof(int));	
		printf("%s\n",TITLE_DIVLINESRT);
		printf("    Pointer   Address\n");	
		printf("%s\n",TITLE_DIVLINESRT);
		printf("5.  ptr_A  %p\n",(void *)  ptr_A);
		printf("6. *ptr_A: %p\n",(void *) *ptr_A);
		printf("7. &ptr_A: %p\n",(void *) &ptr_A);
	}
	else
	printf("1. Status: %s\n",statusA_label);
	printf("%s\n",TITLE_DIVLINESRT);

	
	printf("%s\n",TITLE_TBL_07 ); 
	if (statusB == int(AVAILABLE))
	{
		strcpy(statusB_label,Label_ASSIGNED);
		printf("11. Status: %s\n",statusB_label);
		printf("12. Buffer (bytes): %d\n",bloqmemB_sz);
		printf("13. Elements: %d\n",nElementos);	
		printf("14. Integer size: %d\n", sizeof(int));		
		printf("%s\n",TITLE_DIVLINESRT);
		printf("   Pointer   Address\n");	
		printf("%s\n",TITLE_DIVLINESRT);
		printf("15.  ptr_B  %p\n",(void *)  ptr_B);
		printf("16. *ptr_B: %p\n",(void *) *ptr_B);
		printf("17. &ptr_B: %p\n",(void *) &ptr_B);
	}
	else
	printf("11. Status: %s\n",statusB_label);
	printf("%s\n",TITLE_DIVLINESRT);	
}
//Function 02-------------------------------------
void reptMemory_Nodos(	float **ptr_X, 
						float **ptr_Y,
						int nElementos,
						size_t bloqmemX_sz,
						size_t bloqmemY_sz,
						int statusX,
						int statusY)
{
	char statusX_label [20] = Label_NO_ASSIGNED;
	char statusY_label [20] = Label_NO_ASSIGNED;
		
	printf("%s\n",TITLE_DIVLINESRT);
	printf("%s\n",TITLE_TBL_04);
	if (statusX == int(AVAILABLE))
	{
		strcpy(statusX_label,Label_ASSIGNED);
		printf("1. Status: %s\n",statusX_label);
		printf("2. Buffer (bytes): %d\n",bloqmemX_sz);
		printf("3. Elements: %d\n",nElementos);	
		printf("4. Float size: %d\n", sizeof(float));	
		printf("%s\n",TITLE_DIVLINESRT);
		printf("   Ponit   Address\n");	 
		printf("%s\n",TITLE_DIVLINESRT);
		printf("5.  ptr_X  %p\n",(void *)  ptr_X);
		printf("6. *ptr_X: %p\n",(void *) *ptr_X);
		printf("7. &ptr_X: %p\n",(void *) &ptr_X);
	}
	else
	printf("1. Status: %s\n",statusX_label);
	printf("%s\n",TITLE_DIVLINESRT);
	
	printf("%s\n",TITLE_DIVLINESRT);
	printf("%s\n",TITLE_TBL_05);
	if (statusY == int(AVAILABLE))
	{
		strcpy(statusY_label,Label_ASSIGNED);
		printf("11. Status: %s\n",statusY_label);
		printf("12 Buffer (bytes): %d\n",bloqmemY_sz);
		printf("13. Elements: %d\n",nElementos);	
		printf("14. Float size: %d\n", sizeof(float));	
		printf("%s\n",TITLE_DIVLINESRT);
		printf("   Ponit   Address\n");		
		printf("%s\n",TITLE_DIVLINESRT);
		printf("15  ptr_Y  %p\n",(void *)  ptr_Y);
		printf("16 *ptr_Y: %p\n",(void *) *ptr_Y);
		printf("17 &ptr_Y: %p\n",(void *) &ptr_Y);
	}
	else
	printf("1. Status: %s\n",statusY_label);
	printf("%s\n",TITLE_DIVLINESRT);
}
//Function END--------------------------------------
