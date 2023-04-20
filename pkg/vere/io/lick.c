/// @file

#include "vere.h"
#include <sys/stat.h>
#include <sys/types.h>
#include "noun.h"

/* u3_chan: incoming control plane connection.
*/
  typedef struct _u3_chan {
    struct _u3_moor   mor_u;            //  message handler
    c3_l              coq_l;            //  connection number
    c3_o              liv_o;            //  connection live
    struct _u3_shan*  san_u;            //  server backpointer
    struct _u3_cran*  ran_u;            //  request list
  } u3_chan;

/* u3_shan: control plane server.
*/
  typedef struct _u3_shan {
    uv_pipe_t          pyp_u;            //  server stream handler
    c3_l               nex_l;            //  next connection number
    struct _u3_agent*  gen_u;            //  agent backpointer
    struct _u3_chan*   can_u;            //  connection list
  } u3_shan;


/* u3_device: description of a device
 */
  typedef struct _u3_agent {
    c3_c*              nam_c;            //  name of device
    struct _u3_shan*   san_u;            //  server reference
    struct _u3_lick*   lic_u;            //  device backpointer
    struct _u3_agent*  nex_u;            //  next pointer
  } u3_agent;

/* u3_lick: a list of devices
*/
  typedef struct _u3_lick {
    u3_auto            car_u;            //  driver
    c3_c*              fod_c;            //  IPC folder location
    u3_cue_xeno*       sil_u;            //  cue handle
    struct _u3_agent*          gen_u;            //  agent list
  } u3_lick;

static const c3_c URB_DEV_PATH[] = "/.urb/dev/";

/* _lick_send_noun(): jam and send noun over chan.
*/
static void
_lick_send_noun(u3_chan* can_u, u3_noun nun)
{
  c3_y* byt_y;
  c3_d  len_d;

  u3s_jam_xeno(nun, &len_d, &byt_y);
  u3z(nun);
  u3_newt_send((u3_mojo*)&can_u->mor_u, len_d, byt_y);
}


/* _lick_mote_free(): u3_moat-shaped close callback.
*/
static void
_lick_moat_free(void* ptr_v, ssize_t err_i, const c3_c* err_c)
{
  //c3_free(ptr_v);
}

/* _lick_close_cb(): socket close callback.
*/
static void
_lick_close_cb(uv_handle_t* had_u)
{
  //Freeing had_u gives an out of loom error. no idea why
  //c3_free(had_u);
}


/* _lick_poke_bail(): error function on failed poke
*/
static void
_lick_poke_bail(u3_ovum* egg_u, u3_noun lud)
{
  u3_lick*  lic_u = (u3_lick*)egg_u->car_u;
  u3_chan*  can_u;
  u3_noun   wir = egg_u->wir;
  u3_ovum_free(egg_u);
}


/* _lick_moor_poke(): called on message read from u3_moor.
*/
static void
_lick_moor_poke(void* ptr_v, c3_d len_d, c3_y* byt_y)
{
  u3_weak   put;
  u3_noun   dev, nam, dat, wir, cad;

  u3_chan*  can_u = (u3_chan*)ptr_v;
  u3_agent* gen_u = can_u->san_u->gen_u;
  u3_lick*  lic_u = gen_u->lic_u;
  c3_i      err_i = 0;
  c3_c*     err_c;
  c3_c*     tag_c;
  c3_c*     rid_c;

  put = u3s_cue_xeno_with(lic_u->sil_u, len_d, byt_y);
  if ( u3_none == put ) {
    can_u->mor_u.bal_f(can_u, -1, "cue-none");
    return;
  }
  if ( (c3n == u3r_cell(put, &nam, &dat)) )
  {
    err_i = -2; err_c = "put-bad";
    goto _moor_poke_out;
  }

  wir = u3nc(c3__lick, u3_nul);
  dev = u3i_string(gen_u->nam_c);
  cad = u3nt(c3__soak, dev, put);
  u3_auto_peer(
    u3_auto_plan(&lic_u->car_u,
                 u3_ovum_init(0, c3__l, wir, cad)),
    0, 0, _lick_poke_bail);
  return;
_moor_poke_out:
  if ( 0 != err_i ) {
    can_u->mor_u.bal_f(can_u, err_i, err_c);
  }
}

/* _lick_close_chan(): close given channel, freeing.
*/
static void
_lick_close_chan(u3_shan* san_u, u3_chan* can_u)
{
  u3_lick*  lic_u = san_u->gen_u->lic_u;
  u3_chan*  inn_u;
  // TODO Write close channel command it should give a disconnect mark to %lick
  //  remove chan from server's connection list.
  //
  if ( san_u->can_u == can_u ) {
    san_u->can_u = (u3_chan*)can_u->mor_u.nex_u;
  }
  else {
    for ( inn_u = san_u->can_u; inn_u; inn_u = (u3_chan*)inn_u->mor_u.nex_u ) {
      if ( (u3_chan*)inn_u->mor_u.nex_u == can_u ) {
        inn_u->mor_u.nex_u = can_u->mor_u.nex_u;
        break;
      }
    }
  }
  can_u->mor_u.nex_u = NULL;

  {
    //  send a close event to arvo and stop reading.
    //
    u3_noun wir, cad, dev, dat, mar;

    wir = u3nc(c3__lick, u3_nul);
    dev = u3i_string(san_u->gen_u->nam_c);
    mar = u3i_string("disconnect");
    
    cad = u3nq(c3__soak, dev, mar, u3_nul);

    u3_auto_peer(
      u3_auto_plan(&lic_u->car_u,
                   u3_ovum_init(0, c3__k, wir, cad)),
      0, 0, _lick_poke_bail);
  }

  u3_newt_moat_stop((u3_moat*)&can_u->mor_u, _lick_moat_free);
}


/* _lick_moor_bail(): error callback for u3_moor.
*/
static void
_lick_moor_bail(void* ptr_v, ssize_t err_i, const c3_c* err_c)
{
  u3_chan*  can_u = (u3_chan*)ptr_v;
  u3_shan*  san_u = can_u->san_u;

  if ( err_i != UV_EOF ) {
    u3l_log("lick: moor bail %zd %s", err_i, err_c);
    if ( _(can_u->liv_o) ) {
      _lick_send_noun(can_u, u3nq(0, c3__bail, u3i_word(err_i),
                      u3i_string(err_c)));
      can_u->liv_o = c3n;
    }
  }
  _lick_close_chan(san_u, can_u);
}

/* _lick_sock_cb(): socket connection callback.
*/
static void
_lick_sock_cb(uv_stream_t* sem_u, c3_i tas_i)
{
  u3_shan*  san_u = (u3_shan*)sem_u;
  u3_chan*  can_u;
  c3_i      err_i;

  can_u = c3_calloc(sizeof(u3_chan));
  can_u->mor_u.ptr_v = can_u;
  can_u->mor_u.pok_f = _lick_moor_poke;
  can_u->mor_u.bal_f = _lick_moor_bail;
  can_u->coq_l = san_u->nex_l++;
  can_u->san_u = san_u;
  err_i = uv_timer_init(u3L, &can_u->mor_u.tim_u);
  c3_assert(!err_i);
  err_i = uv_pipe_init(u3L, &can_u->mor_u.pyp_u, 0);
  c3_assert(!err_i);
  err_i = uv_accept(sem_u, (uv_stream_t*)&can_u->mor_u.pyp_u);
  c3_assert(!err_i);
  u3_newt_read((u3_moat*)&can_u->mor_u);
  can_u->mor_u.nex_u = (u3_moor*)san_u->can_u;
  san_u->can_u = can_u;
}


/* _lick_close_sock():  close an agent's socket
*/
static void
_lick_close_sock(u3_shan* san_u)
{
  c3_c* pax_c = u3_Host.dir_c;
  c3_w len_w = strlen(pax_c) + 2 + sizeof(URB_DEV_PATH) + strlen(san_u->gen_u->nam_c);
  c3_c* paf_c = c3_malloc(len_w);
  c3_i  wit_i;
  wit_i = snprintf(paf_c, len_w, "%s/%s/%s", pax_c, URB_DEV_PATH, san_u->gen_u->nam_c);

  u3l_log("lick: closing %s/%s/%s",pax_c, URB_DEV_PATH, san_u->gen_u->nam_c);

  c3_assert(wit_i > 0);
  c3_assert(len_w == (c3_w)wit_i + 1);

  if ( 0 != unlink(paf_c) ) {
    if ( ENOENT != errno ) {
      u3l_log("lick: failed to unlink socket: %s", uv_strerror(errno));
    }
  }
  else {
    // u3l_log("lick: unlinked %s", paf_c);
  }
  uv_close((uv_handle_t*)&san_u->pyp_u, _lick_close_cb);
  c3_free(paf_c);
}


/* _lick_init_sock(): initialize socket device.
*/
static void
_lick_init_sock(u3_shan* san_u)
{
  
  //  the full socket path is limited to about 108 characters,
  //  and we want it to be relative to the pier. save our current
  //  path, chdir to the pier, open the socket at the desired
  //  path, then chdir back. hopefully there aren't any threads.
  //
  c3_c pax_c[2048];
  c3_i err_i;
  c3_c por_c[2048] = ".";
  u3_agent* gen_u = san_u->gen_u;

  if ( NULL == getcwd(pax_c, sizeof(pax_c)) ) {
    u3l_log("lick: getcwd: %s", uv_strerror(errno));
    u3_king_bail();
  }
  if ( 0 != chdir(u3_Host.dir_c) ) {
    u3l_log("lick: chdir: %s", uv_strerror(errno));
    u3_king_bail();
  }

  strcat(por_c, URB_DEV_PATH);
  strcat(por_c, gen_u->nam_c);

  if ( 0 != unlink(gen_u->nam_c) && errno != ENOENT ) {
    u3l_log("lick: unlink: %s", uv_strerror(errno));
    goto _lick_sock_err_chdir;
  }
  if ( 0 != (err_i = uv_pipe_init(u3L, &san_u->pyp_u, 0)) ) {
    u3l_log("lick: uv_pipe_init: %s", uv_strerror(err_i));
    goto _lick_sock_err_chdir;
  }

  if ( 0 != (err_i = uv_pipe_bind(&san_u->pyp_u, por_c)) ) {
    u3l_log("lick: uv_pipe_bind: %s", uv_strerror(err_i));
    u3l_log("lick: uv_pipe_bind: %s", por_c);
    goto _lick_sock_err_chdir;
  }
  if ( 0 != (err_i = uv_listen((uv_stream_t*)&san_u->pyp_u, 0,
                               _lick_sock_cb)) ) {
    u3l_log("lick: uv_listen: %s", uv_strerror(err_i));
    goto _lick_sock_err_unlink;
  }
  if ( 0 != chdir(pax_c) ) {
    u3l_log("lick: chdir: %s", uv_strerror(errno));
    goto _lick_sock_err_close;
  }
  u3l_log("lick: listening on %s/%s", u3_Host.dir_c, por_c);
  return;

_lick_sock_err_close:
  uv_close((uv_handle_t*)&san_u->pyp_u, _lick_close_cb);
_lick_sock_err_unlink:
  if ( 0 != unlink(gen_u->nam_c) ) {
    u3l_log("lick: unlink: %s", uv_strerror(errno));
  }
_lick_sock_err_chdir:
  if ( 0 != chdir(pax_c) ) {
    u3l_log("lick: chdir: %s", uv_strerror(errno));
  }
  u3_king_bail();
}


/* u3_lick_ef_spin(): Open an IPC port
*/
static void
_lick_ef_spin(u3_lick* lic_u, u3_noun wir_i, u3_noun nam)
{

  u3l_log("lick spin: %s", u3r_string(nam));

  u3_agent* gen_u = c3_calloc(sizeof(*gen_u));
  gen_u->san_u = c3_calloc(sizeof(*gen_u->san_u));
  gen_u->san_u->can_u = c3_calloc(sizeof(*gen_u->san_u->can_u));
  gen_u->nam_c = u3r_string(nam);
  gen_u->lic_u = lic_u;
  gen_u->san_u->gen_u = gen_u;

  u3_agent* hed_u = lic_u->gen_u;
  
  if( NULL == lic_u->gen_u )
  {
    _lick_init_sock(gen_u->san_u);
    lic_u->gen_u = gen_u;
  }
  else
  {
    u3_agent* las_u = lic_u->gen_u;

    while ( NULL != las_u->nex_u )
    {
      if( 0 == strcmp(las_u->nam_c, gen_u->nam_c) )
      {
        return;
      }
      las_u = las_u->nex_u;
    }

    if( 0 != strcmp(las_u->nam_c, gen_u->nam_c) )
    {
    u3l_log("lick last");
      _lick_init_sock(gen_u->san_u);
      las_u->nex_u = gen_u;
    }
  }

}

/* _lick_io_kick(): apply effects.
*/
static c3_o
_lick_io_kick(u3_auto* car_u, u3_noun wir, u3_noun cad)
{
  u3_lick* lic_u = (u3_lick*)car_u;

  u3_noun tag, i_wir, par;
  u3_noun nam, dat, tmp;
  c3_o ret_o, dev_o;

  if (  (c3n == u3r_cell(wir, &i_wir, 0))
     || (c3n == u3r_cell(cad, &tag, &tmp))
     || (c3__lick != i_wir) )
  {
    return  c3n;
  }
  else {
    if ( (c3__spin == tag) ){
      nam = u3k(tmp); 
      _lick_ef_spin(lic_u, wir, nam); // execute spin command
      ret_o = c3y;

    } else if ( (c3__shut == tag) )
    {
      u3l_log("lick shut");
      ret_o=c3y;
    } else if ( c3__spit == tag )
    {
      u3l_log("lick: spit ");
      ret_o=c3y;
      
      if ( c3n == u3r_cell(tmp, &nam, &dat) ){
        return c3n;
      }
       
      c3_c* nam_c = u3r_string(nam);
      u3_agent* gen_u = NULL;
      u3_agent* cur_u = lic_u->gen_u;
      while (cur_u != NULL){
        if( 0 == strcmp(cur_u->nam_c, nam_c) ) {
          gen_u = cur_u;
          break;
        }
        cur_u = cur_u->nex_u;
      }
      if ( NULL == gen_u ){
        u3l_log("lick: spit: gen %s not found", nam_c);
        return c3n;
      }

      _lick_send_noun(gen_u->san_u->can_u, dat);
      /*if( c3y == u3r_qual(tmp, &wut, &cmd, &dat, &cnt) )
      {
        _lick_ef_rite(loc_u, wir, dev_d, wut, cmd, dat, cnt); // execute write command
        ret_o = c3y;
      } else { ret_o = c3n; }*/
    }
    else {
      ret_o = c3n;
    }
  }

  u3l_log("lick kick done");
  return ret_o;
}

/* _lick_born_news(): initialization complete on %born.
*/
static void
_lick_born_news(u3_ovum* egg_u, u3_ovum_news new_e)
{
  u3_auto* car_u = egg_u->car_u;

  if ( u3_ovum_done == new_e ) {
    car_u->liv_o = c3y;
  }
}

/* _lick_born_bail(): %born is essential, retry failures.
*/
static void
_lick_born_bail(u3_ovum* egg_u, u3_noun lud)
{

  u3l_log("lick: %%born failure;");
  u3z(lud);
  u3_ovum_free(egg_u);
}

/* _lick_io_talk(): notify %lick that we're live
 *                  pass it a list of device names
*/
static void
_lick_io_talk(u3_auto* car_u)
{
  u3_lick* lic_u = (u3_lick*)car_u;
  u3l_log("lick born");
  u3_noun  wir = u3nc(c3__lick, u3_nul);
  u3_noun  cad = u3nc(c3__born, u3_nul);

  u3_auto_peer(
    u3_auto_plan(car_u, u3_ovum_init(0, c3__l, wir, cad)),
    0,
    _lick_born_news,
    _lick_born_bail);

  car_u->liv_o = c3y;
}

/* _lick_io_exit(): close all open device files and exit
*/
static void
_lick_io_exit(u3_auto* car_u)
{
  u3_lick*          lic_u = (u3_lick*)car_u;
  c3_c*             pax_c = u3_Host.dir_c;

  u3_agent*         cur_u=lic_u->gen_u;
  u3_agent*         nex_u;
  while( NULL != cur_u )
  {
    _lick_close_sock(cur_u->san_u);
    nex_u = cur_u->nex_u;
    c3_free(cur_u);
    cur_u = nex_u;
  }

  //u3s_cue_xeno_done(lic_u->sil_u);
  c3_free(lic_u);
}


/* u3_lick(): initialize hardware control vane.
*/
u3_auto*
u3_lick_io_init(u3_pier* pir_u)
{
  u3_lick* lic_u = c3_calloc(sizeof(*lic_u));

  c3_c pax_c[2048];
  struct stat st = {0};
  strcat(pax_c, u3_Host.dir_c);
  strcat(pax_c, URB_DEV_PATH);

  if( -1 == stat(pax_c, &st) ) {
    u3l_log("lick init %s", lic_u->fod_c);
    mkdir(pax_c, 0700);
  }

  lic_u->fod_c = c3_calloc(strlen(pax_c));
  strcpy(lic_u->fod_c, pax_c);


  u3_auto* car_u = &lic_u->car_u;
  car_u->nam_m = c3__lick;

  car_u->liv_o = c3n;
  car_u->io.talk_f = _lick_io_talk;
  car_u->io.kick_f = _lick_io_kick;
  car_u->io.exit_f = _lick_io_exit;

  return car_u;
}
