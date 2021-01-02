/*
*------------------------------------------------
* repVector.h
*------------------------------------------------
*
*	01 repAristasVec
*	02 repNodosVec
*
*/

//Function 01-------------------------------------
void repAristasVec(	int **ptr_A, 
					int **ptr_B,
					int n,
					int MaxA, int MinA,
					int MaxB, int MinB)
{ 
	int i;
	printf("%s\n",TITLE_DIVLINEXTR);
	printf("%s\n",TITLE_TBL_02 ); 
	printf("%s\n",TITLE_DIVLINEXTR);
	printf("%s\n",TITLE_TABLE_1);
	printf("%s\n",TITLE_TABLE_2);
	printf("%s\n",TITLE_DIVLINEXTR);
	for (i=0;i<n;i++)
	{
		printf("%3i   %p    %3i   %p   %3i\n",
		i,
		(void *)((*ptr_A)+i),
		 int  (*((*ptr_A)+i)),
		(void *)((*ptr_B)+i),
		 int  (*((*ptr_B)+i))
		);
	}	
	printf("%s\n",TITLE_DIVLINEXTR);
	printf("Max:                    %5i",MaxA);
	printf("                    %5i\n",MaxB);
	printf("Min:                    %5i",MinA);
	printf("                    %5i\n",MinB);
	printf("%s\n",TITLE_DIVLINEXTR);
}
//Function 02-------------------------------------
void repNodosVec(	float **ptr_X, 
					float **ptr_Y,
					int n,
					float MaxX, float MinX,
					float MaxY, float MinY)
{
	int i;
	printf("%s\n",TITLE_DIVLINEXTR);
	printf("%s\n",TITLE_TBL_01);
	printf("%s\n",TITLE_DIVLINEXTR);
	printf("%s\n",TITLE_TABLE_1);
	printf("%s\n",TITLE_TABLE_3);
	printf("%s\n",TITLE_DIVLINEXTR);
	for (i=0;i<n;i++)
	{
		printf("%3i   %p    %12f   %p   %12f\n",
		i,
		(void *)((*ptr_X)+i),
		float (*((*ptr_X)+i)),
		(void *)((*ptr_Y)+i),
		float (*((*ptr_Y)+i))
		);
	}
	printf("%s\n",TITLE_DIVLINEXTR);
	printf("                  MaxX:    %12f",  MaxX);
	printf("              MaxY: %12f\n",MaxY);
	printf("                  MinX:    %12f",  MinX);
	printf("              MinY: %12f\n",MinY);
	printf("%s\n",TITLE_DIVLINEXTR);
}

//Function 02-------------------------------------
repConfigParam(	float NodosLabel_offset_X,	//01
				float NodosLabel_offset_Y,	//02
				float AristasLabel_offset_X,//03
				float AristasLabel_offset_Y,//04
				float NodosMark_Radio,		//05
				float NodosLabel_Height,	//06
				float AristasLabel_Height,	//07
				int Config_nElements)		//08
{
	printf("%s\n",TITLE_DIVLINESRT);
	printf("%s\n",TITLE_TBL_08);
	printf("%s\n",TITLE_DIVLINESRT);

	printf("Parametros de configuracion:%2i\n",Config_nElements);	//08
	printf("1. Nodos Label offset X:   %12.5f\n",NodosLabel_offset_X);	//01
	printf("2. Nodos Label offset Y:   %12.5f\n",NodosLabel_offset_Y);	//02
	printf("3. Aristas Label offset X: %12.5f\n",AristasLabel_offset_X);//03
	printf("4. Aristas Label offset Y: %12.5f\n",AristasLabel_offset_Y);//04
	printf("5. Nodos Mark Radio:       %12.5f\n",NodosMark_Radio);		//05
	printf("6. Nodos Label Height:     %12.5f\n",NodosLabel_Height);	//06
	printf("7. Aristas Label Height:   %12.5f\n",AristasLabel_Height);	//07

	printf("%s\n",TITLE_DIVLINESRT);
}
//Function END--------------------------------------
