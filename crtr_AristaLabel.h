//Funciones 04-----------------------------------------------------------------
void crtr_AristaLabel(	FILE 	**Driver_ArchivoDXF,		//01
						int 	***VecA_Aristas,			//02
						int 	***VecB_Aristas,			//03
						int 	Aristas_nElements,			//04
						float 	***VecX_Nodos,				//05
	   					float 	***VecY_Nodos,				//06
	   					int 	Nodos_nElements,			//07
	   					float 	AristasLabel_offset_X,		//08
						float 	AristasLabel_offset_Y,		//09
	   					char 	Layer_AristasLabel_Name[],	//10
						float 	AristasLabel_Height,		//11
						int		AristasLabel_color)			//12
{
	int i;
	int A, B;
	float x1, y1, x2, y2, x3, y3;
	
	for (i=0;i<Aristas_nElements;i++)
	{
		//Referenciación
    	A = int (*(*(*VecA_Aristas)+i));
		B = int (*(*(*VecB_Aristas)+i));
		
		x1 =  float (*(*(*VecX_Nodos)+A));
		y1 =  float (*(*(*VecY_Nodos)+A));
		x2 =  float (*(*(*VecX_Nodos)+B));
		y2 =  float (*(*(*VecY_Nodos)+B));
		
		//Posición intemedia del texto
		//respecto de los puntos extremos		
		x3 = (x1+x2)/2; 
		y3 = (y1+y2)/2; 
		
		fprintf(*Driver_ArchivoDXF,"0\n");
		fprintf(*Driver_ArchivoDXF,"TEXT\n");
		fprintf(*Driver_ArchivoDXF,"8\n");
		
		fprintf(*Driver_ArchivoDXF,"%s\n",Layer_AristasLabel_Name);
		fprintf(*Driver_ArchivoDXF,"62\n");
		fprintf(*Driver_ArchivoDXF,"%i\n",AristasLabel_color);
	
		fprintf(*Driver_ArchivoDXF,"10\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",x3);
		fprintf(*Driver_ArchivoDXF,"20\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",y3);
		
		fprintf(*Driver_ArchivoDXF,"40\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",AristasLabel_Height);
		fprintf(*Driver_ArchivoDXF,"1\n");
		fprintf(*Driver_ArchivoDXF,"%i\n",i);
	}
}
//Funciones 04-----------------------------------------------------------------
