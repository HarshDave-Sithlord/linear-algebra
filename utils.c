#include "config.h"
#include "obj.h"

static blksz_t block_size_macro_loop[3] = {0};
static blksz_t block_size_micro_loop[2] = {0};

void macro_blksz_init(dim_t blk_index, dim_t dt, dim_t ft, dim_t sc_t, dim_t dc_t)
{
	block_size_macro_loop[blk_index].v[0] = dt;
	block_size_macro_loop[blk_index].v[1] = ft;
	block_size_macro_loop[blk_index].v[2] = sc_t;
	block_size_macro_loop[blk_index].v[3] = dc_t;
}

void micro_blksz_init(dim_t blk_index, dim_t dt, dim_t ft, dim_t sc_t, dim_t dc_t)
{
	block_size_micro_loop[blk_index].v[0] = dt;
	block_size_micro_loop[blk_index].v[1] = ft;
	block_size_micro_loop[blk_index].v[2] = sc_t;
	block_size_micro_loop[blk_index].v[3] = dc_t;
}

dim_t get_mcblock(element_type_t type, dim_t cur_dim)
{
	dim_t ret = -1;
	if(cur_dim > block_size_macro_loop[BLKSZ_MC].v[type])
	{
		ret = block_size_macro_loop[BLKSZ_MC].v[type];
	}
	else
	{
		ret = cur_dim;
	}
}

dim_t get_kcblock(element_type_t type, dim_t cur_dim)
{
	dim_t ret = -1;
	if(cur_dim > block_size_macro_loop[BLKSZ_KC].v[type])
	{
			ret = block_size_macro_loop[BLKSZ_KC].v[type];
	}
	else
	{
		ret = cur_dim;
	}
}

dim_t get_ncblock(element_type_t type, dim_t cur_dim)
{
	dim_t ret = -1;
	if(cur_dim > block_size_macro_loop[BLKSZ_NC].v[type])
	{
		ret = block_size_macro_loop[BLKSZ_NC].v[type];
	}
	else
	{
		ret = cur_dim;
	}
}
