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
