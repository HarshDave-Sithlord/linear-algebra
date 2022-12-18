#include "obj.h"

void main(void)
{
    obj_t a, b, c;
    create_obj(24, 4, 24, 1, HLAS_NO_TRANSPOSE, HLAS_DOUBLE, HLAS_DOUBLE_SIZE, &a);
    create_obj(4, 8, 1, 4, HLAS_NO_TRANSPOSE, HLAS_DOUBLE, HLAS_DOUBLE_SIZE, &b);
    create_obj(24, 8, 24, 1, HLAS_NO_TRANSPOSE, HLAS_DOUBLE, HLAS_DOUBLE_SIZE, &c);

    randmz_obj(&a);
    randmz_obj(&b);
    randmz_obj(&c);

    disp_obj(&a);
    disp_obj(&b);
    disp_obj(&c);

    disp_obj_with_addr(&a);
    disp_obj_with_addr(&b);
    disp_obj_with_addr(&c);
}
