/*
*-------------------------------------------------------
* mapping.cpp
*-------------------------------------------------------
*/

#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>

#include "defstatus.h"
#include "deftitles.h"
#include "allocater.h"
#include "loaderf.h"
#include "metricaFile.h"
#include "metricaVector.h"
#include "repVector.h"
#include "rprtMemory.h"
#include "rprtExport.h"
#include "exportDXF.h"
#include "repMetricaFile.h"
#include "dxfcolor.h"

//Funtions END---------------------------------------------
int main(int nArgument, char *DBNameIn_ID[])
{
	
	float *VecX_Nodos = NULL;
	float *VecY_Nodos = NULL;
	int *VecA_Aristas = NULL;
	int	*VecB_Aristas = NULL;
	
	int Nodos_nElements = 0;
	int Aristas_nElements = 0;
	int Config_nElements = 0;
		
	int File_DXF_STATUS 			= NO_CREATED;
	int FileNodos_STATUS 			= NO_LINKED;
	int FileAristas_STATUS 			= NO_LINKED;
	int FileConfig_STATUS 			= NO_LINKED;

	int MemoryNodos_VecX_STATUS 	= NO_ASSIGNED;
	int MemoryNodos_VecY_STATUS 	= NO_ASSIGNED;	
	int MemoryAristas_VecA_STATUS 	= NO_ASSIGNED;
	int MemoryAristas_VecB_STATUS 	= NO_ASSIGNED;
	
	int Layer_STATUS_Layers			= UNSELECT; 
	int Layer_STATUS_NodosLabel		= UNSELECT; 
	int Layer_STATUS_NodosMark 		= UNSELECT;	
	int Layer_STATUS_AristasLabel	= UNSELECT; 
	int Layer_STATUS_AristasLine	= UNSELECT; 
		
	//Metrica de vectores
	float MaxX_nodos=0; 
	float MinX_nodos=0;
	float MaxY_nodos=0; 
	float MinY_nodos=0;
	
	int MaxA_aristas=0;
	int MinA_aristas=0;
	int MaxB_aristas=0; 
	int MinB_aristas=0;
	
	//Metrica de Archivos 
	int aristasFile_LF 			= 0;
	int aristasFile_BLANCSPACE 	= 0;
	int nodosFile_LF 			= 0;
	int nodosFile_BLANCSPACE 	= 0;
	int configFile_LF 			= 0;
	int configFile_BLANCSPACE	= 0;
	
	size_t NodosX_BloqMemSz 	= 0;
	size_t NodosY_BloqMemSz 	= 0;
	size_t AristasA_BloqMemSz 	= 0;
	size_t AristasB_BloqMemSz 	= 0;

	float NodosLabel_offset_X	= 0; 	//01
	float NodosLabel_offset_Y	= 0; 	//02
	float AristasLabel_offset_X = 0; 	//03
	float AristasLabel_offset_Y = 0; 	//04
	float NodosMark_Radio		= 0; 	//05
	float NodosLabel_Height		= 0; 	//06
	float AristasLabel_Height	= 0; 	//07

	int Task_rprt_MetricF_Aristas	= UNSELECT;	
	int Task_rprt_MetricF_Nodos		= UNSELECT;	
	int Task_rprt_MetricF_Config	= UNSELECT;	
	int Task_rprt_Memory_Aristas	= UNSELECT;	
	int Task_rprt_Memory_Nodos		= UNSELECT;	
	int Task_rprt_Nodos_Vec			= UNSELECT;	
	int Task_rprt_Aristas_Vec		= UNSELECT;
	int Task_rprt_ConfigParam 		= UNSELECT;
	int Task_rprt_Export			= UNSELECT;

	char CommandLine_argumento[5]="";
	
	//Manual CUSTOM BEGIN -----------------------------------------
	
	char File_Address_In []   = "./txt/in/";	
	char FileNodosNm_In  [25] = "";
	char FileAristasNm_In[25] = "";
	char FileConfigNm_In [25] = "";

	char File_Address_Out[]   = "./dxf/out/";	
	char FileDXFNm_Out   [25] = "";

	char Layer_NodosLabel_Name[]  = "Nodos_Label";	 //13
	char Layer_NodosMark_Name[]   = "Nodos_Mark";	 //14
	char Layer_AristasLabel_Name[]= "Aristas_Label"; //15
	char Layer_AristasLine_Name[] = "Aristas_Line";	 //16
	
	int NodosLabel_color		= dxfColorGREEN; 	//08
	int NodosMark_color 		= dxfColorYELLOW;	//10
	int AristasLabel_color		= dxfColorCYAN; 	//11
	int AristasLine_color		= dxfColorRED; 		//12
	
	Layer_STATUS_Layers			= UNSELECT;
	Layer_STATUS_NodosMark 		= SELECT;
	Layer_STATUS_NodosLabel		= SELECT; 
	Layer_STATUS_AristasLine	= SELECT;
	Layer_STATUS_AristasLabel	= SELECT;
    
	Task_rprt_MetricF_Aristas	= SELECT;	
	Task_rprt_MetricF_Nodos	= SELECT;	
	Task_rprt_MetricF_Config	= SELECT;	
	//Task_rprt_Memory_Aristas	= SELECT;	
	//Task_rprt_Memory_Nodos	= SELECT;	
	//Task_rprt_Nodos_Vec		= SELECT;	
	//Task_rprt_Aristas_Vec		= SELECT;
	//Task_rprt_ConfigParam 	= SELECT;
	Task_rprt_Export			= SELECT;
	
	//Manual CUSTOM END -----------------------------------------
	
	//OPERATIONS BEGIN ---------------------------- 

	//Presentacion de aplicación
	printf("%s\n", TITLE_APP);

	//Parametros de línea de comandos
	if (DBNameIn_ID[1] == NULL)
	strcpy(CommandLine_argumento,"00");
	else
	strcpy(CommandLine_argumento,DBNameIn_ID[1]);

	//Configuracion de nombres de archivos de entrada
	//conforme a argumento de entrada de linea de comando
	//la omisción del argumento es asignada como "00"

	strcpy(FileNodosNm_In,"nodos");
	strcat(FileNodosNm_In,CommandLine_argumento);
	strcat(FileNodosNm_In,".txt");

	strcpy(FileAristasNm_In,"aristas");
	strcat(FileAristasNm_In,CommandLine_argumento);
	strcat(FileAristasNm_In,".txt");

	strcpy(FileConfigNm_In, "config"); 	
	strcat(FileConfigNm_In,CommandLine_argumento);
	strcat(FileConfigNm_In,".txt");

	strcpy(FileDXFNm_Out,"redmapa");
	strcat(FileDXFNm_Out,CommandLine_argumento);
	strcat(FileDXFNm_Out,".dxf");

	//Revision de archivos de entrada
	FileNodos_STATUS = 
	metricaFile(
		FileNodosNm_In,
		File_Address_In,
		&Nodos_nElements,
		&nodosFile_LF,
		&nodosFile_BLANCSPACE);
				
	FileAristas_STATUS = 
	metricaFile(
		FileAristasNm_In,
		File_Address_In,
		&Aristas_nElements,
		&aristasFile_LF,
		&aristasFile_BLANCSPACE);
	
	FileConfig_STATUS = 
	metricaFile(
		FileConfigNm_In,
		File_Address_In,
		&Config_nElements,
		&configFile_LF,
		&configFile_BLANCSPACE);

	if (Task_rprt_MetricF_Nodos	== SELECT)
	{    
		repMetricFile(	
			FileNodosNm_In,
			File_Address_In,
			FileNodos_STATUS,
			nodosFile_LF,
			nodosFile_BLANCSPACE,
			Nodos_nElements);
	}

	if (Task_rprt_MetricF_Aristas == SELECT)
	{    
		repMetricFile(	
			FileAristasNm_In,
			File_Address_In,
			FileAristas_STATUS,
			aristasFile_LF,
			aristasFile_BLANCSPACE,
			Aristas_nElements);
	}

	if (Task_rprt_MetricF_Config == SELECT)
	{
		repMetricFile(	
			FileConfigNm_In,
			File_Address_In,
			FileConfig_STATUS,
			configFile_LF,
			configFile_BLANCSPACE,
			Config_nElements);
	}

	if ((FileNodos_STATUS 		== AVAILABLE) and
		(FileAristas_STATUS 	== AVAILABLE) and
		(FileConfig_STATUS 		== AVAILABLE))
	{
		
		//Gestion de memoria dinámica
		MemoryNodos_VecX_STATUS =	 	
		getmem_Nodos(&VecX_Nodos,Nodos_nElements,&NodosX_BloqMemSz);
		MemoryNodos_VecY_STATUS =	 	
		getmem_Nodos(&VecY_Nodos,Nodos_nElements,&NodosY_BloqMemSz);
		
		MemoryAristas_VecA_STATUS =	 	
		getmem_Aristas(&VecA_Aristas,Aristas_nElements,&AristasA_BloqMemSz);	
		MemoryAristas_VecB_STATUS =	 	
		getmem_Aristas(&VecB_Aristas,Aristas_nElements,&AristasB_BloqMemSz);
		
		if (Task_rprt_Memory_Nodos == SELECT)
		{
			reptMemory_Nodos(	
				&VecX_Nodos, 
				&VecY_Nodos,
				Nodos_nElements,
				NodosX_BloqMemSz,
				NodosY_BloqMemSz,
				MemoryNodos_VecX_STATUS,
				MemoryNodos_VecY_STATUS);
		}
		if (Task_rprt_Memory_Aristas == SELECT)
		{						
			reptMemory_Aristas(	
				&VecA_Aristas, 
				&VecB_Aristas,
				Aristas_nElements,
				AristasA_BloqMemSz,
				AristasB_BloqMemSz,
				MemoryAristas_VecA_STATUS,
				MemoryAristas_VecB_STATUS);
		}					
			
		if ((MemoryNodos_VecX_STATUS == ASSIGNED) and
			(MemoryNodos_VecY_STATUS == ASSIGNED))
		{
			loader_Nodos(	
				&VecX_Nodos,
				&VecY_Nodos,
				Nodos_nElements,
				FileNodosNm_In,
				File_Address_In);	
			
			loader_Aristas(
				&VecA_Aristas,
				&VecB_Aristas,
				Aristas_nElements,
				FileAristasNm_In,
				File_Address_In);

			loader_Config(	
				&NodosLabel_offset_X,	//01
				&NodosLabel_offset_Y,	//02
				&AristasLabel_offset_X, //03
				&AristasLabel_offset_Y, //04
				&NodosMark_Radio,		//05
				&NodosLabel_Height,	 	//06
				&AristasLabel_Height,	//07
				Config_nElements,		//08
				FileConfigNm_In,		//09
				File_Address_In);		//10
					
			metricaV_Nodos(	
				&VecX_Nodos, 
				Nodos_nElements, 
				&MaxX_nodos, &MinX_nodos);
							
			metricaV_Nodos(	
				&VecY_Nodos, 
				Nodos_nElements, 
				&MaxY_nodos, &MinY_nodos);
			
			metricaV_Arista(
				&VecA_Aristas, 
				Aristas_nElements, 
				&MaxA_aristas, &MinA_aristas);
							
			metricaV_Arista(
				&VecB_Aristas, 
				Aristas_nElements, 
				&MaxB_aristas, &MinB_aristas);

			if (Task_rprt_Nodos_Vec == SELECT)
			{
				repNodosVec(
					&VecX_Nodos,
					&VecY_Nodos,
					Nodos_nElements,
					MaxX_nodos,MinX_nodos,
					MaxY_nodos,MinY_nodos);
			}

			if (Task_rprt_Aristas_Vec == SELECT)
			{
				repAristasVec(	
					&VecA_Aristas,
					&VecB_Aristas,
					Aristas_nElements,
					MaxA_aristas,MinA_aristas,
					MaxB_aristas,MinB_aristas);	
			}

			if (Task_rprt_ConfigParam == SELECT)
			{
				repConfigParam(
					NodosLabel_offset_X,	//01
					NodosLabel_offset_Y,	//02
					AristasLabel_offset_X,	//03
					AristasLabel_offset_Y,	//04
					NodosMark_Radio,		//05
					NodosLabel_Height,	 	//06
					AristasLabel_Height,	//07
					Config_nElements);		//08
			}

			File_DXF_STATUS = 
			exportDXF(	
				&VecX_Nodos,				//01		
				&VecY_Nodos,				//02	
				Nodos_nElements,			//03
				&VecA_Aristas,				//04
				&VecB_Aristas,				//05
				Aristas_nElements,			//06
				FileDXFNm_Out,				//07
				File_Address_Out,			//08	
				Layer_NodosLabel_Name,		//09
				Layer_NodosMark_Name,		//10
				Layer_AristasLabel_Name,	//11
				Layer_AristasLine_Name,		//12		
				NodosLabel_offset_X,		//13
				NodosLabel_offset_Y,		//14
				AristasLabel_offset_X,		//15
				AristasLabel_offset_Y,		//16
				NodosMark_Radio,			//17
				NodosLabel_Height,			//18
				AristasLabel_Height,		//19
				NodosLabel_color,			//20
				NodosMark_color,			//21
				AristasLabel_color,			//22
				AristasLine_color,			//23
				Layer_STATUS_Layers,		//24
				Layer_STATUS_NodosMark, 	//25		
				Layer_STATUS_NodosLabel,	//26
				Layer_STATUS_AristasLine,	//27
				Layer_STATUS_AristasLabel);	//28

				if (Task_rprt_Export == SELECT)
				{
					rprtExport(
						File_DXF_STATUS,			//01
						Nodos_nElements,			//02
						Aristas_nElements,			//03
						FileDXFNm_Out,				//04
						File_Address_Out,			//05	
						Layer_NodosLabel_Name,		//06
						Layer_NodosMark_Name,		//07
						Layer_AristasLabel_Name,	//08
						Layer_AristasLine_Name,		//09		
						NodosLabel_offset_X,		//10
						NodosLabel_offset_Y,		//11
						AristasLabel_offset_X,		//12
						AristasLabel_offset_Y,		//13
						NodosMark_Radio,			//14
						NodosLabel_Height,			//15
						AristasLabel_Height,		//16
						NodosLabel_color,			//17
						NodosMark_color,			//18
						AristasLabel_color,			//19
						AristasLine_color,			//20
						Layer_STATUS_Layers,		//21
						Layer_STATUS_NodosMark, 	//22		
						Layer_STATUS_NodosLabel,	//23
						Layer_STATUS_AristasLine,	//24
						Layer_STATUS_AristasLabel);	//25
			}
		}
	}	
	//Cierre de aplicación
	printf("%s\n", "Fin de aplicacion.");
}
//Main END---------------------------------------------------
