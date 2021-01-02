/*
*------------------------------------------------
* allocater.h
*------------------------------------------------
*
*	int getmem_Aristas
*	getmem_Nodos
*
*/

//Function 01------------------------------------------------
int getmem_Aristas(	int **ptr, 
					int nElementos, 
					size_t *bloq_mem_sz) 
{
	int success = NO_ASSIGNED;
	*bloq_mem_sz =  size_t (nElementos * (size_t (sizeof (int))));
	*ptr = (int *) malloc ( int (*bloq_mem_sz));	
    if (ptr != NULL) 
	success = ASSIGNED;    
    return success;
}
//Function 02------------------------------------------------
int getmem_Nodos(	float **ptr, 
					int nElementos, 
					size_t *bloq_mem_sz) 
{
	int success = NO_ASSIGNED;
	*bloq_mem_sz =  size_t (nElementos * (size_t (sizeof (float))));
	*ptr = (float *) malloc ( int (*bloq_mem_sz));		
    if (ptr != NULL) 
	success = ASSIGNED ;    
    return success;
}
//Function END------------------------------------------------
