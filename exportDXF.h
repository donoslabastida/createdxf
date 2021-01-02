/*
*-------------------------------------------------------------------
*	exportDXF.h
*-------------------------------------------------------------------
*/

#include "crtr_Header.h"
#include "crtr_Layers.h"
#include "crtr_Nodos.h"
#include "crtr_AristasLine.h"
#include "crtr_NodosLabel.h"
#include "crtr_AristaLabel.h"
#include "crtr_End.h"

#define NO_CREATED 	    -1
#define CREATED 	     1

int exportDXF (	float	**VecX_Nodos,				//01
				float 	**VecY_Nodos,				//02
				int 	Nodos_nElements,			//03
				int 	**VecA_Aristas,				//04
				int 	**VecB_Aristas,				//05
				int 	Aristas_nElements,			//06
				char	FileDXFNm_Out[],			//07
				char	FileAddress_Out[],			//08	
				char	Layer_NodosLabel_Name[],	//09
				char	Layer_NodosMark_Name[],		//10
				char	Layer_AristasLabel_Name[],	//11
				char	Layer_AristasLine_Name[],	//12		
				float 	NodosLabel_offset_X,		//13
				float 	NodosLabel_offset_Y,		//14
				float 	AristasLabel_offset_X,		//15
				float 	AristasLabel_offset_Y,		//16
				float 	NodosMark_radio,			//17
				float 	NodosLabel_Height,			//18
				float 	AristasLabel_Height,		//19
				int 	NodosLabel_color,			//20
				int 	NodosMark_color,			//21
				int 	AristasLabel_color,			//22
				int 	AristasLine_color,			//23
				int 	Layer_STATUS_Layers,		//24
				int 	Layer_STATUS_NodosMark, 	//25		
				int 	Layer_STATUS_NodosLabel,	//26
				int 	Layer_STATUS_AristasLine,	//27
				int 	Layer_STATUS_AristasLabel)	//28
{
	FILE *Driver_ArchivoDXF;
	int File_DXF_STATUS = NO_CREATED;
 	char FilePath [200] = "";
    
	strcat(FilePath,FileAddress_Out);
    strcat(FilePath,FileDXFNm_Out);
    
    Driver_ArchivoDXF = fopen(FilePath,"w"); 
	 
    if (Driver_ArchivoDXF != NULL) 
	File_DXF_STATUS = CREATED;

	if (File_DXF_STATUS == CREATED)
    {	  
    	crtr_Header		(	&Driver_ArchivoDXF); 
    	
		if (Layer_STATUS_Layers == SELECT)
		{
    		crtr_Layers	(	
				&Driver_ArchivoDXF,			//01
				Layer_NodosLabel_Name,		//02
				Layer_NodosMark_Name,		//03
				Layer_AristasLabel_Name,	//04
				Layer_AristasLine_Name,		//05
				NodosLabel_color,			//06
				NodosMark_color,			//07
				AristasLabel_color,			//08
				AristasLine_color);			//09
		}

		if (Layer_STATUS_NodosMark == SELECT)
		{	
   			crtr_Nodos	(	
			&Driver_ArchivoDXF,			//01
			&VecX_Nodos,				//02
			&VecY_Nodos,				//03
			Nodos_nElements,			//04
			Layer_NodosMark_Name,		//05
			NodosMark_radio,			//06
			NodosMark_color);			//07
   		}
		if (Layer_STATUS_AristasLine ==	SELECT)	
		{
			crtr_AristasLine(
				&Driver_ArchivoDXF,	//01
				&VecA_Aristas,			//02
				&VecB_Aristas,			//03
				Aristas_nElements,		//04
				&VecX_Nodos,			//05
				&VecY_Nodos,			//06
				Nodos_nElements,		//07
				Layer_AristasLine_Name, //08
				AristasLine_color);		//09
   		}
		if (Layer_STATUS_NodosLabel	== SELECT)
		{
			crtr_NodosLabel	(	
				&Driver_ArchivoDXF,			//01
				&VecX_Nodos,				//02
				&VecY_Nodos,				//03
				Nodos_nElements,			//04
				NodosLabel_offset_X,		//13
				NodosLabel_offset_Y,		//14
				Layer_NodosLabel_Name,		//05
				NodosLabel_Height,			//06
				NodosLabel_color);			//07
		}
		if (Layer_STATUS_AristasLabel == SELECT)
		{																										
			crtr_AristaLabel(	
				&Driver_ArchivoDXF,			//01
				&VecA_Aristas,				//02
				&VecB_Aristas,				//03
				Aristas_nElements,			//04
				&VecX_Nodos,				//05
				&VecY_Nodos,				//06
				Nodos_nElements,			//07
				AristasLabel_offset_X,		//08
				AristasLabel_offset_Y,		//09
				Layer_AristasLabel_Name,	//10
				AristasLabel_Height,		//11
				AristasLabel_color);		//12
   		}
   		crtr_END (&Driver_ArchivoDXF);
	    fclose(Driver_ArchivoDXF);
	}
	else
	printf("Status: NO CREADO\n");
	return File_DXF_STATUS;
}
// Functions END----------------------
