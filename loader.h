/*
*--------------------------------------------
* loader.h
*--------------------------------------------
*
*	01	loader_Aristas
*	02	losder_nodos
*/

# define CONFIG_NELEMENTS 7

// Functions 01--------------------------------------------
int loader_Aristas(	int **VectorA_i,
					int **VectorB_i,
					int nElements,
					char File_Name[],
			   		char File_Address[]	)
{
	FILE *File_Driver;
    char File_Path [200] = "";
	int i;   
	int A_integer;
	int B_integer;
	int Status = UNCOMPLETE;
	
    strcat(File_Path,File_Address);
    strcat(File_Path,File_Name);
    if (nElements > 0)
	{   
	    File_Driver = fopen(File_Path,"r");
	    if (File_Driver != NULL)
	    {
	    	Status = ONLINE;
			for(i=0;i<nElements;i++)
    		{		
    			fscanf(File_Driver,"%i %i",&A_integer,&B_integer);
    			(*((*VectorA_i)+i)) = A_integer;
    			(*((*VectorB_i)+i)) = B_integer;	
    		}
		}		    	
		fclose(File_Driver);	    	
	}
	return Status;
}
// Functions 02--------------------------------------------
int loader_Nodos (	float **VectorX_f,
					float **VectorY_f,
					int nElements,
					char File_Name[],
					char File_Address[])
{
	FILE *File_Driver;
    char File_Path [200] = "";
	int i;   
	float x_float;
	float y_float;
	int Status = ERROR;	
	
    strcat(File_Path,File_Address);
    strcat(File_Path,File_Name);
    if (nElements > 0)
	{   
	    File_Driver = fopen(File_Path,"r");
	    if (File_Driver != NULL)
	    {
	    	Status = ONLINE;
			for(i=0;i<nElements;i++)
    		{		
    			fscanf(File_Driver,"%f %f",&x_float,&y_float);    		
    			(*((*VectorX_f)+i)) = x_float;
    			(*((*VectorY_f)+i)) = y_float;
			}
			fclose(File_Driver);
		}		    		    
	}
	return Status;
}
// Functions 03--------------------------------------------
int loader_Config(	float *NodosLabel_offset_X,	 	//01
					float *NodosLabel_offset_Y,	 	//02
					float *AristasLabel_offset_X, 	//03
					float *AristasLabel_offset_Y, 	//04
					float *NodosMark_Radio,		 	//05
					float *NodosLabel_Height,	 	//06
					float *AristasLabel_Height, 	//07
					int	Config_nElements,			//08
					char FileConfigNm_In[],			//09
	   				char File_Address_In[])			//10
{
	FILE *File_Driver;
    char File_Path [200] = "";
	int i;   
	float Row_float;
	int Status = UNCOMPLETE;	
	
    strcat(File_Path,File_Address_In);
    strcat(File_Path,FileConfigNm_In);
    if (Config_nElements == CONFIG_NELEMENTS)
	{   
	    File_Driver = fopen(File_Path,"r");
	    if (File_Driver != NULL)
	    {
			fscanf(File_Driver,"%f",&Row_float);    		
			*NodosLabel_offset_X = Row_float; 	//01

			fscanf(File_Driver,"%f",&Row_float);    		
			*NodosLabel_offset_Y = Row_float; 	//02

			fscanf(File_Driver,"%f",&Row_float);    		
			*AristasLabel_offset_X = Row_float; //03

			fscanf(File_Driver,"%f",&Row_float);    		
			*AristasLabel_offset_Y = Row_float; //04

			fscanf(File_Driver,"%f",&Row_float);    		
			*NodosMark_Radio = Row_float;		//05

			fscanf(File_Driver,"%f",&Row_float);    		
			*NodosLabel_Height = Row_float;	 	//06

			fscanf(File_Driver,"%f",&Row_float);    		
			*AristasLabel_Height = Row_float; 	//07	

			fclose(File_Driver);
			Status = LOADED;
		}		    		    
	}
	return Status;
}//Funtions END---------------------------------------------------------------------
