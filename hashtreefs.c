#define FUSE_USE_VERSION 35
#define _FILE_OFFSET_BITS 64

#include <fuse3/fuse.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#include <assert.h>
#include <errno.h>

#include "uthash.h"

#define __BUFSIZE ( 1024 * 1024 ) * 30 // Максимальный размер буфера файла (30 мегабайт)

struct _file_ {
	const char		*path;
	void			*content;
	//struct _rwop_		*op;		/* read write ops */
	struct stat		st;
};

struct _node_ {
	struct _node_	*next;
	struct _node_	*prev;
	struct _node_	*parent;
	struct _node_	*child;

	struct fuse_pollhandle	*ph;

	struct _file_	*file;
	
	struct UT_hash_handle hh;
};

struct _node_ *create_node(const char *path, mode_t mode) 
{
	struct _node_ *n;
	assert ( ( n = ( struct _node_ * ) calloc (1, sizeof (struct _node_ ) ) ) );
	return n;
	//n->next = NULL;
}

void *__init (struct fuse_conn_info *conn, struct fuse_config *cfg) 
{
	struct _node_ *root = create_node ("/", S_IFDIR | 0775);
	return NULL;
}

struct fuse_operations fops = {
	.init = __init,
};

int main (int argc, char *argv[]) {
	int rc = 0;
	struct fuse_args args = FUSE_ARGS_INIT ( argc, argv ); 
	rc = fuse_main ( args.argc, args.argv, &fops, ( void * ) args.argv [args.argc] );

	//printf("info");
	return rc;
}