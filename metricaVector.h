/*
*------------------------------------------------
* metricaVector.h
*------------------------------------------------
*
*	01	metricaV_Arista
*	02	metricaV_Nodos
*/
//Function 01------------------------------------------------
void metricaV_Arista(	int **ptr,
						int n, 
						int *Max, 
						int *Min)
{
	int i;
	int Sample; 
	*Max = int (*(*ptr));
	*Min = int (*(*ptr));
	for (i=0;i<n;i++)
	{
		Sample = int(*((*ptr)+i));
		if (*Max < Sample )  *Max = Sample;
		if (*Min > Sample )  *Min = Sample;
	}
}
//Function 02------------------------------------------------
void metricaV_Nodos(float **ptr,
					int n, 
					float *Max, 
					float *Min)
{
	int i;
	float Sample;
	
	*Max = float (*(*ptr));
	*Min = *Max;
	
	//printf("Inicializacion (Max) - (Min) : %12.5f %12.5f\n", *Max,*Min);
	//printf("i   Sample (Max) (Min)\n");
	for (i=0;i<n;i++)
	{
		Sample = float(*((*ptr)+i));
		if (*Max < Sample )  *Max = Sample;
		if (*Min > Sample )  *Min = Sample;	
		//printf("%3i %12.5f %12.5f %12.5f\n",i,Sample,*Max,*Min);		
	}
}
//Function END------------------------------------------------
