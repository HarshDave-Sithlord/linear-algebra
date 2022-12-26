#include "obj.h"

void main(void)
{
	obj_t a, b, c;
	init_default_cntx();
    create_obj(58, 96, 58, 1, HLAS_NO_TRANSPOSE, HLAS_DOUBLE, HLAS_DOUBLE_SIZE, &a);
    create_obj(96, 202, 96, 1, HLAS_NO_TRANSPOSE, HLAS_DOUBLE, HLAS_DOUBLE_SIZE, &b);
    create_obj(58, 202, 58, 1, HLAS_NO_TRANSPOSE, HLAS_DOUBLE, HLAS_DOUBLE_SIZE, &c);

#if 0
    randmz_obj(&a);
    randmz_obj(&b);
    randmz_obj(&c);
#else
    set_obj(&a, 4.0);
    set_obj(&b, 10.0);
    set_obj(&c, 0.0);
#endif

    disp_obj(&a);
    disp_obj(&b);
    disp_obj(&c);

    disp_obj_with_addr(&a);
    disp_obj_with_addr(&b);
    disp_obj_with_addr(&c);
    init_default_cntx();
    do_gemm(&a, &b, &c);
    disp_obj(&c);
}
