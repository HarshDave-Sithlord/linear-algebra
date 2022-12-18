#ifndef P2_OBJ_H_
#define P2_OBJ_H_

#include "utils.h"


typedef struct obj{
	dim_t length;
	dim_t width;
	dim_t row_stride;
	dim_t col_stride;
	trans_t transpose;
	store_type_t storage_scheme;
	element_type_t type;
	element_size_t size;
	void *buf;
}obj_t;

void create_obj(
			dim_t length, dim_t width,
			dim_t row_strtide, dim_t col_stride,
			trans_t transpose,
		   	element_type_t element_type, 
			element_size_t element_size,
			obj_t *object
		  );

void randmz_obj(obj_t *object);

store_type_t get_storage_scheme(obj_t *object);

dim_t get_row_stride(obj_t *object);

dim_t get_col_stride(obj_t *object);

void disp_obj(obj_t *object);

void disp_obj_with_addr(obj_t *object);


#endif /* P2_OBJ_H_ */
