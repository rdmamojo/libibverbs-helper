/*
 * Copyright (c) 2014 RDMAmojo.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <unistd.h>
#include <fcntl.h>
#include <infiniband/verbs.h>
#include <infiniband/verbs-helper.h>

static int modify_block_mode(int fd, int use_block)
{
	int orig_flags, flags;
	int rc;
	
	orig_flags = fcntl(fd, F_GETFL);
	if (use_block)
		flags = orig_flags & (~O_NONBLOCK);
	else
		flags = orig_flags | O_NONBLOCK;

	/* if there isn't anything to do */
	if (orig_flags == flags)
		return 0;

	rc = fcntl(fd, F_SETFL, flags);
	if (rc < 0)
		return rc;

	return 0;
}

int ibv_helper_modify_block_mode_comp_channel(struct ibv_comp_channel *channel,
					      int use_block)
{
	return modify_block_mode(channel->fd, use_block);
}

int ibv_helper_modify_block_mode_device(struct ibv_context *context,
					int use_block)
{
	return modify_block_mode(context->async_fd, use_block);
}
