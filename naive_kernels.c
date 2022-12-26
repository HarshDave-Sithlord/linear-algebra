#include "obj.h"

/**
 * Here we try to mimic the very in-famous 5 loop GEMM algorithm
 */

void do_gemm(obj_t *a, obj_t *b, obj_t *c)
{
	dim_t len_a = a->length;
	dim_t wid_a = a->width;
	dim_t rs_a = a->row_stride;
	dim_t cs_a = a->col_stride;

	dim_t len_b = b->length;
	dim_t wid_b = b->width;
	dim_t rs_b = b->row_stride;
	dim_t cs_b = b->col_stride;

	dim_t len_c = c->length;
	dim_t wid_c = c->width;
	dim_t rs_c = c->row_stride;
	dim_t cs_c = c->col_stride;

	dim_t nc_off = 0;
	dim_t mc_off = 0;
	dim_t kc_off = 0;

	double *cc = (double *)c->buf;
	double *bb = (double *)b->buf;
	double *aa = (double *)a->buf;

	double *c_ = (double *)c->buf;
	double *a_ = (double *)a->buf;
	double *b_ = (double *)b->buf;

	double *c_nc = (double *)c->buf;
	double *a_nc = (double *)a->buf;
	double *b_nc = (double *)b->buf;

	double *c_kc = (double *)c->buf;
	double *a_kc = (double *)a->buf;
	double *b_kc = (double *)b->buf;

	double *c_mc = (double *)c->buf;
	double *a_mc = (double *)a->buf;
	double *b_mc = (double *)b->buf;

	for(dim_t i = 0; i < wid_c ; i += nc_off)
	{
		nc_off = get_ncblock(HLAS_DOUBLE, (wid_c - i));
		c_nc = cc + i * rs_c;
		b_nc = bb + i * rs_b;
		for(dim_t j = 0; j < len_b; j += kc_off)
		{
			a_kc = aa + j * rs_a;
			b_kc = b_nc + j * cs_a;

			kc_off = get_kcblock(HLAS_DOUBLE, (len_b - j));
			for(dim_t l = 0; l < len_a; l += mc_off)
			{
				c_mc = c_nc + l * cs_c;
				a_mc = a_kc + l * cs_a;

				c_ = c_mc;
				b_ = b_kc;
				a_ = a_mc;

				mc_off = get_mcblock(HLAS_DOUBLE, (len_a - l));

				for(dim_t jr = 0; jr < nc_off; jr++)
				{
					for(dim_t ir = 0; ir < mc_off; ir++)
					{
						for(dim_t kr = 0; kr < kc_off; kr ++)
						{
							*(c_+ (jr * rs_c + ir)) += *(a_ + (kr * rs_a + ir)) *
													 *(b_ + (kr + jr * rs_b));
						}//end of kr loop
					}//end of ir loop
				}//end of jr loop
			}//end of MC loop
		}//end of KC loop
	}//end of NC loop
}
