#include "config.h"
#include "obj.h"

void init_default_cntx(void)
{								//  D   F   SC  DC
	macro_blksz_init(BLK_NC, 96, 96, 96, 96);
	macro_blksz_init(BLK_KC, 48, 48, 48, 48);
	macro_blksz_init(BLK_MC, 24, 24, 24, 24);
}
