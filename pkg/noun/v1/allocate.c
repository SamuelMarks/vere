/// @file

#include "pkg/noun/allocate.h"
#include "pkg/noun/v1/allocate.h"

#include "pkg/noun/v1/hashtable.h"
#include "log.h"
#include "pkg/noun/v1/manage.h"
#include "options.h"
#include "retrieve.h"
#include "trace.h"
#include "vortex.h"

/* u3a_v1_reclaim(): clear ad-hoc persistent caches to reclaim memory.
*/
void
u3a_v1_reclaim(void)
{
  //  clear the memoization cache
  //
  u3h_free(u3R->cax.har_p);
  u3R->cax.har_p = u3h_new();
}

u3_noun
u3a_v1_rewritten_noun(u3_noun som)
{
  if ( c3y == u3a_is_cat(som) ) {
    return som;
  }
  u3_post som_p = u3a_v1_rewritten(u3a_v1_to_off(som));

  if ( c3y == u3a_is_pug(som) ) {
    som_p = u3a_v1_to_pug(som_p);  //  XX alias?
  }
  else {
    som_p = u3a_v1_to_pom(som_p);
  }

  return som_p;
}

/* u3a_v1_rewrite_compact(): rewrite pointers in ad-hoc persistent road structures.
 *                        XX need to version
*/
void
// u3a_v1_rewrite_compact(u3a_v1_road *rod_u)
u3a_v1_rewrite_compact(void)
{
  u3a_v1_rewrite_noun(u3R->ski.gul);
  u3a_v1_rewrite_noun(u3R->bug.tax);
  u3a_v1_rewrite_noun(u3R->bug.mer);
  u3a_v1_rewrite_noun(u3R->pro.don);
  u3a_v1_rewrite_noun(u3R->pro.day);
  u3a_v1_rewrite_noun(u3R->pro.trace);
  u3h_v1_rewrite(u3R->cax.har_p);

  u3R->ski.gul = u3a_v1_rewritten_noun(u3R->ski.gul);
  u3R->bug.tax = u3a_v1_rewritten_noun(u3R->bug.tax);
  u3R->bug.mer = u3a_v1_rewritten_noun(u3R->bug.mer);
  u3R->pro.don = u3a_v1_rewritten_noun(u3R->pro.don);
  u3R->pro.day = u3a_v1_rewritten_noun(u3R->pro.day);
  u3R->pro.trace = u3a_v1_rewritten_noun(u3R->pro.trace);
  u3R->cax.har_p = u3a_v1_rewritten(u3R->cax.har_p);
}
void
u3a_v1_rewrite_noun(u3_noun som)
{
  if ( c3n == u3a_is_cell(som) ) {
    return;
  }

  if ( c3n == u3a_rewrite_ptr(u3a_v1_to_ptr((som))) ) return;

  u3a_cell* cel = u3a_v1_to_ptr(som);

  u3a_v1_rewrite_noun(cel->hed);
  u3a_v1_rewrite_noun(cel->tel);

  cel->hed = u3a_v1_rewritten_noun(cel->hed);
  cel->tel = u3a_v1_rewritten_noun(cel->tel);
}
