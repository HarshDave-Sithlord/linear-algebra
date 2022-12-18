#ifndef HLAS_UTILS_H_
#define HLAS_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum HLAS_DATATYPES{
	HLAS_DOUBLE = 0,
	HLAS_FLOAT,
	HLAS_DCOMPLEX,
	HLAS_SCOMPLEX
};


enum HLAS_DATASIZE{
	HLAS_DOUBLE_SIZE = 8,
	HLAS_FLOAT_SIZE = 4,
	HLAS_DCOMPLEX_SIZE = 16,
	HLAS_SCOMPLEX_SIZE = 8
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

#endif /* HLAS_UTILS_H_ */
