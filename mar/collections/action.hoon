::  /action/collections/mar
::
/-  collections
=,  api:collections
|_  act=action
::
++  grow
  |%
  ++  tank  >act<
  --
::
++  grab
  |%
  ++  noun  action
  ++  json
    =,  dejs:format
    =<  action
    |%
    ++  action
      %-  of  :~
        create+create
        delete+(se %da)
        submit+(ot col+(se %da) tit+so wat+wain ~)
        comment+(ot col+(se %da) top+(se %da) com+(se %da) wat+wain ~)
      ==
    ::
    ++  create
      (ot wat+(cu (hard kind) so) des+so pub+bo vis+bo ses+(as (se %p)) ~)
    ::
    ++  wain  (su (more (just '\0a') (cook crip (star prn))))
    ::
    ::
    ++  as  |*(a=fist (cu sy (ar a)))                     ::  array as set
    ++  se                                                ::  string as aura
      =,  wired
      |*  a=term
      %+  cu
        |=  b=cord  ^-  (odo:raid a)
        (slav a b)
      so
--  --
--
