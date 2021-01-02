//crtr_AristaLine.h
//Funciones 02-----------------------------------------------------------------
void crtr_AristasLine(	FILE 	**Driver_ArchivoDXF,		//01
						int 	***VecA_Aristas,			//02
						int 	***VecB_Aristas,			//03
						int 	Aristas_nElements,			//04
						float 	***VecX_Nodos,				//05
	   					float 	***VecY_Nodos,				//06
	   					int 	Nodos_nElements,			//07
	   					char 	Layer_AristasLine_Name[],	//08
						int 	AristasLine_color)			//09
{
	int i;
	int A, B;
	float x1, y1, x2, y2;
	

	for (i=0;i<Aristas_nElements;i++)
	{
		//Referenciación
    	A = int (*(*(*VecA_Aristas)+i));
		B = int (*(*(*VecB_Aristas)+i));
		
		x1 =  float (*(*(*VecX_Nodos)+A));
		y1 =  float (*(*(*VecY_Nodos)+A));
		x2 =  float (*(*(*VecX_Nodos)+B));
		y2 =  float (*(*(*VecY_Nodos)+B));
		
		fprintf(*Driver_ArchivoDXF,"0\n");
		fprintf(*Driver_ArchivoDXF,"LINE\n");
		fprintf(*Driver_ArchivoDXF,"8\n");
		fprintf(*Driver_ArchivoDXF,"%s\n",Layer_AristasLine_Name);
		fprintf(*Driver_ArchivoDXF,"62\n");
		fprintf(*Driver_ArchivoDXF,"%i\n",AristasLine_color);
	
		fprintf(*Driver_ArchivoDXF,"10\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",x1);
		fprintf(*Driver_ArchivoDXF,"20\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",y1);
		
		fprintf(*Driver_ArchivoDXF,"11\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",x2);
		fprintf(*Driver_ArchivoDXF,"21\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",y2);
	}	
};
// Functions END--------------------------------------------
