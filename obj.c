#include "obj.h"

void debug_disp(obj_t *object)
{
	if(object)
	{
		printf("length :: %d && Width :: %d\n", object->length, object->width);
		printf("row stride :: %d && col stride :: %d\n", object->row_stride, object->col_stride);
		printf("transopse :: %d\n", object->transpose);
		printf("Element type :: %d\n", object->type);
		printf("Element size :: %d\n", object->size);
		printf("storage scheme is :: %d\n", object->storage_scheme);
	}
}


void create_obj(dim_t length, dim_t width,
            dim_t row_stride, dim_t col_stride, 
			trans_t transpose,
		   	element_type_t element_type, 
			element_size_t element_size,
			obj_t *object)
{
	/**
	 * TODO: What is already initialized object is passed to this function.
	 * Need to make sure that the object is already initialized and if so
	 * either free previously allocated buffer or simply return throwing error.
	 */
    if(object)
    {
        siz_t total_size_needed = 0;
        /**
         * Step 1:
         * Find out the storage scheme for given object.
         * Based on strides, it can be concluded that 
         * whether the object is row or col major stored.
        */
        if(row_stride == 1 && col_stride > 1)
        {
            object->storage_scheme = COL_MAJOR;
        }
        else if(col_stride == 1 && row_stride > 1)
        {
            object->storage_scheme = ROW_MAJOR;
        }
        /**
         * Step 2:
         * Based on storage scheme, total amount of memory
         * needed can be calculated for the given object.
        */
        if(object->storage_scheme == ROW_MAJOR)
        {
                total_size_needed = row_stride * width * element_size;
#if DEBUG_OBJ == 1
                printf("Object is row major stored.[%d][%d][%d]\n", col_stride, width, element_size);
#endif
        }
        else if(object->storage_scheme == COL_MAJOR)
        {
                total_size_needed = col_stride * length * element_size;
#if DEBUG_OBJ == 1
                printf("Object is row major stored.[%d][%d][%d]\n", row_stride, length, element_size);
#endif
        }
        else
        {
        	;
        }
#if DEBUG_OBJ == 1
        printf("Total memory needed is :: %d[%d]\n", total_size_needed, total_size_needed/element_size);
#endif
        object->length = length;
        object->width = width;
        object->row_stride = row_stride;
        object->col_stride = col_stride;
        object->size = element_size;
        object->type = element_type;
        object->transpose = transpose;
        object->buf = malloc(total_size_needed);
        if(object->buf)
        {
            memset(object->buf, 0, total_size_needed);
        }
    }
    else
    {
        ;//Error
    }
}



void disp_obj(obj_t *object)
{
    if(object)
    {
        if(object->storage_scheme == COL_MAJOR)
        {
            for(int i  = 0; i < object->width; i++)
            {
                for(int j = 0; j < object->length; j++)
                {
                    printf("%5.2f\t", *(double *)( object->buf + ( (j*object->col_stride + i)*object->size ) ) );
                }
                printf("\n");
            }
        }
        else if(object->storage_scheme == ROW_MAJOR)
        {
            for(int i  = 0; i < object->length; i++)
            {
                for(int j = 0; j < object->width; j++)
                {
                    printf("%5.2f\t", *(double *)( object->buf + ( (j*object->row_stride + i) * object->size ) ) );
                }
                printf("\n");
            }
        }
        else
        {
        	;//
        }
    }
    else
    {
    	;//
    }
    printf("\n");
}


void disp_obj_with_addr(obj_t *object)
{
    if(object)
    {
        if(object->storage_scheme == COL_MAJOR)
        {
            for(int i  = 0; i < object->width; i++)
            {
                for(int j = 0; j < object->length; j++)
                {
                    printf("%5.2f[%p]\t", (double *)( object->buf + ( (j*object->col_stride + i)*object->size ) ),
                    		*(double *)( object->buf + ( (j*object->col_stride + i)*object->size ) ) );
                }
                printf("\n");
            }
        }
        else if(object->storage_scheme == ROW_MAJOR)
        {
            for(int i  = 0; i < object->length; i++)
            {
                for(int j = 0; j < object->width; j++)
                {
                    printf("%5.2f[%p]\t", (double *)( object->buf + ( (j*object->row_stride + i) * object->size ) ),
                    		*(double *)( object->buf + ( (j*object->row_stride + i) * object->size ) ) );
                }
                printf("\n");
            }
        }
        else
        {
        	;//
        }
    }
    else
    {
    	;//
    }
    printf("\n");
}


void randmz_obj(obj_t *object)
{
    if(object)
    {
        if(object->storage_scheme == COL_MAJOR)
        {
            for(int i  = 0; i < object->width; i++)
            {
                for(int j = 0; j < object->length; j++)
                {
                    *(double *) (object->buf + ((j*object->col_stride + i)*object->size) ) = (double )rand()/(double)(RAND_MAX/69);
                }
            }
        }
        else if(object->storage_scheme == ROW_MAJOR)
        {
            for(int i  = 0; i < object->length; i++)
            {
                for(int j = 0; j < object->width; j++)
                {
                	*(double *) (object->buf + ((j*object->row_stride + i)*object->size) ) = (double )rand()/(double)(RAND_MAX/69);
                }
            }
        }
        else
        {
            ;//
        }
    }
}



void set_obj(obj_t *object, double value)
{
    if(object)
    {
        if(object->storage_scheme == COL_MAJOR)
        {
            for(int i  = 0; i < object->width; i++)
            {
                for(int j = 0; j < object->length; j++)
                {
                    *(double *) (object->buf + ((j*object->col_stride + i)*object->size) ) = value;
                }
            }
        }
        else if(object->storage_scheme == ROW_MAJOR)
        {
            for(int i  = 0; i < object->length; i++)
            {
                for(int j = 0; j < object->width; j++)
                {
                	*(double *) (object->buf + ((j*object->row_stride + i)*object->size) ) = value;
                }
            }
        }
        else
        {
            ;//
        }
    }
}
