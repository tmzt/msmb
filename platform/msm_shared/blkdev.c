/*
 * Copyright (c) 2010 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <string.h>
 
#include <err.h>
#include <debug.h>
#include <platform.h>
#include "include/mmc.h"
#include <lib/bio.h>
#include <reg.h>

unsigned char mmc_slot = 0;

extern struct mmc_boot_host mmc_host;
extern struct mmc_boot_card mmc_card;
static bdev_t dev;

ssize_t read_block(struct bdev *dev, void *buf, bnum_t block, uint count)
{
	int mmc_ret;

	unsigned int *out = (unsigned int *)buf; // void *buf
	unsigned int data_addr = (unsigned long long)block * dev->block_size;
	unsigned int data_len = (unsigned int)count * dev->block_size;
	mmc_ret = mmc_boot_read_from_card( &mmc_host, &mmc_card, data_addr, data_len, out);
	
	if (mmc_ret == MMC_BOOT_E_SUCCESS)
		return count * dev->block_size;
	else
		return ERR_IO;
}

ssize_t write_block(struct bdev *dev, const void *buf, bnum_t block, uint count)
{
	/* write is not implemented */
	return ERR_IO;
}

int platform_init_blkdev_emmc(unsigned char slot, unsigned int base) {
{
	int mmc_ret;

    memset( (struct mmc_boot_host*)&mmc_host, 0, sizeof( struct mmc_boot_host ) );
    memset( (struct mmc_boot_card*)&mmc_card, 0, sizeof(struct mmc_boot_card) );

    mmc_slot = slot;
    mmc_boot_mci_base = base;

    /* Initialize necessary data structure and enable/set clock and power */
    dprintf(SPEW," Initializing MMC host data structure and clock!\n" );
    mmc_ret = mmc_boot_init( &mmc_host );
    if( mmc_ret != MMC_BOOT_E_SUCCESS )
    {
        dprintf(CRITICAL,  "MMC Boot: Error Initializing MMC Card!!!\n" );
        return -1;
    }

    /* Initialize and identify cards connected to host */
    mmc_ret = mmc_boot_init_and_identify_cards( &mmc_host, &mmc_card );
    if( mmc_ret != MMC_BOOT_E_SUCCESS )
    {
        dprintf(CRITICAL, "MMC Boot: Failed detecting MMC/SDC @ slot%d\n",slot);
        return -2;
    }

    mmc_display_csd();
    mmc_display_ext_csd();

    //mmc_ret = partition_read_table(&mmc_host, &mmc_card);
    
    /* now register the block device */
    
   	bio_initialize_bdev(&dev, "mmc0", 512, mmc_card.capacity / 512);

	// fill in hooks
	dev.read_block = &read_block;
	dev.write_block = &write_block;

	bio_register_device(&dev);
    
    return 0;
}

