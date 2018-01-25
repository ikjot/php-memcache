

/* $Id$ */

#ifndef MEMCACHE_QUEUE_H_
#define MEMCACHE_QUEUE_H_

/* request / server stack */
#define MMC_QUEUE_PREALLOC 25

typedef struct mmc_queue {
	void	**items;				/* items on queue */
	int		alloc;					/* allocated size */
	int		head;					/* head index in ring buffer */
	int		tail;					/* tail index in ring buffer */
	int		len;
} mmc_queue_t;

#define mmc_queue_release(q) memset((q), 0, sizeof(*(q)))
#define mmc_queue_reset(q) (q)->len = (q)->head = (q)->tail = 0
#define mmc_queue_item(q, i) ((q)->tail + (i) < (q)->alloc ? (q)->items[(q)->tail + (i)] : (q)->items[(i) - ((q)->alloc - (q)->tail)]) 

void mmc_queue_push(mmc_queue_t *, void *);
void *mmc_queue_pop(mmc_queue_t *);
int mmc_queue_contains(mmc_queue_t *, void *);
void mmc_queue_free(mmc_queue_t *);
void mmc_queue_copy(mmc_queue_t *, mmc_queue_t *);
void mmc_queue_remove(mmc_queue_t *, void *);

#endif /*MEMCACHE_QUEUE_H_*/

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
