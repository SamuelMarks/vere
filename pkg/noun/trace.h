/// @file

#ifndef U3_TRACE_H
#define U3_TRACE_H

#include "c3.h"
#include "types.h"

#ifdef U3_CPU_DEBUG
# include "options.h"
#endif

  /** Data structures.
  **/
    /* u3t_trace: fast execution flags.
    */
      typedef struct _u3t_trace {
        c3_o noc_o;                 //  now executing in nock interpreter
        c3_o glu_o;                 //  now executing in jet glue
        c3_o mal_o;                 //  now executing in allocator
        c3_o far_o;                 //  now executing in fragmentor
        c3_o coy_o;                 //  now executing in copy
        c3_o euq_o;                 //  now executing in equal
      } u3t_trace;

  /**  Macros.
  **/
#   ifdef U3_CPU_DEBUG
#     define u3t_on(var)  \
        (u3T.var = (u3C.wag_w & u3o_debug_cpu) \
                 ? (c3n == u3T.var) ? c3y : (abort(), 0) \
                 : u3T.var)
#   else
#     define u3t_on(var)
#endif

#   ifdef U3_CPU_DEBUG
#     define u3t_off(var) \
        (u3T.var = (u3C.wag_w & u3o_debug_cpu) \
                 ? (c3y == u3T.var) ? c3n : (abort(), 0) \
                 : u3T.var)
#   else
#     define u3t_off(var)
#endif


  /**  Functions.
  **/
    /* u3t_init(): initialize tracing layer.
    */
      void
      u3t_init(void);

      /// @return  Number of entries written to the JSON trace file.
      c3_w
      u3t_trace_cnt(void);

      /// @return  Number of times u3t_trace_close() has been called.
      c3_w
      u3t_file_cnt(void);

    /* u3t_push(): push on trace stack.
    */
      void
      u3t_push(u3_noun mon);

    /* u3t_mean(): push `[%mean roc]` on trace stack.
    */
      void
      u3t_mean(u3_noun roc);

    /* u3t_drop(): drop from meaning stack.
    */
      void
      u3t_drop(void);

    /* u3t_slog(): print directly.
    */
      void
      u3t_slog(u3_noun hod);

    /* u3t_heck(): profile point.
    */
      void
      u3t_heck(u3_atom cog);

    /* u3t_samp(): sample.
    */
      void
      u3t_samp(void);

    /* u3t_come(): push on profile stack; return yes if active push.  RETAIN.
    */
      c3_o
      u3t_come(u3_noun bat);

    /* u3t_flee(): pop off profile stack.
    */
      void
      u3t_flee(void);

    /* u3t_trace_open(): opens the path for writing tracing information.
    */
      void
      u3t_trace_open();

    /* u3t_trace_close(): closes the trace file. optional.
    */
      void
      u3t_trace_close();

    /* u3t_trace_time(): returns current time since system epoc,
     * whatever it is per system, in microseconds.
    */
      c3_d
      u3t_trace_time();

    /* u3t_nock_trace_push(): pushes a frame onto the trace stack;
    *  return yes if active push.
    */
      c3_o
      u3t_nock_trace_push(u3_noun lab);

    /* u3t_nock_trace_pop(): pop off trace stack.
    */
      void
      u3t_nock_trace_pop();

    /* u3t_event_trace(): record a lifecycle event.
    */
      void
      u3t_event_trace(const c3_c* name, c3_c type);

    /* u3t_damp(): print and clear profile data.
    */
      void
      u3t_damp(FILE* fil_u);

    /* u3t_boff(): turn profile sampling off.
    */
      void
      u3t_boff(void);

    /* u3t_boot(): turn sampling on.
    */
      void
      u3t_boot(void);

    /* u3t_slog_cap(): slog a tank with a caption with
    ** a given priority c3_l (assumed 0-3).
    */
      void
      u3t_slog_cap(c3_l pri_l, u3_noun cap, u3_noun tan);

    /* u3t_slog_trace(): given a c3_l priority pri and a raw stack tax
    ** flop the order into start-to-end, render, and slog each item
    ** until done.
    */
      void
      u3t_slog_trace(c3_l pri_l, u3_noun tax);

    /* u3t_slog_nara(): slog only the deepest road's trace with
    ** c3_l priority pri
    */
      void
      u3t_slog_nara(c3_l pri_l);

    /* u3t_slog_hela(): join all roads' traces together into one tax
    ** and pass it to slog_trace along with the given c3_l priority pri_l
    */
      void
      u3t_slog_hela(c3_l pri_l);

  /** Globals.
  **/
      /// Tracing profiler.
      extern u3t_trace u3t_Trace;
#     define u3T u3t_Trace


#endif /* ifndef U3_TRACE_H */
