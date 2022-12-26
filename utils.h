#ifndef HLAS_UTILS_H_
#define HLAS_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HLASP2_FP_TYPES 4

enum HLAS_DATATYPES{
	HLAS_DOUBLE = 0,
	HLAS_FLOAT,
	HLAS_SCOMPLEX,
	HLAS_DCOMPLEX
};


enum HLAS_DATASIZE{
	HLAS_DOUBLE_SIZE = 8,
	HLAS_FLOAT_SIZE = 4,
	HLAS_SCOMPLEX_SIZE = 16,
	HLAS_DCOMPLEX_SIZE = 8
};

enum HLAS_TRANSPOSE{
	HLAS_NO_TRANSPOSE = 0,
	HLAS_TRANSPOSE,
	HLAS_CONJUGATE_TRANSPOSE,
	HLAS_HERMITION_TRANSPOSE
};

enum HLAS_STORE_TYPE{
	COL_MAJOR = 0,
	ROW_MAJOR,
	GENERAL /*long way to go.. LoL..*/
};

typedef unsigned int dim_t;
typedef unsigned int siz_t;
typedef unsigned char bool_t;
typedef unsigned char uint8_t;
typedef unsigned char element_type_t;
typedef unsigned char element_size_t;
typedef unsigned char trans_t;
typedef unsigned char store_type_t;

void micro_blksz_init(dim_t blk_index, dim_t dt, dim_t ft, dim_t sc_t, dim_t dc_t);
void macro_blksz_init(dim_t blk_index, dim_t dt, dim_t ft, dim_t sc_t, dim_t dc_t);
dim_t get_mcblock(element_type_t type, dim_t cur_dim);
dim_t get_kcblock(element_type_t type, dim_t cur_dim);
dim_t get_ncblock(element_type_t type, dim_t cur_dim);
void init_default_cntx(void);


#endif /* HLAS_UTILS_H_ */
