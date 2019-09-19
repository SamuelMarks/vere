module Arvo.Event where

import UrbitPrelude hiding (Term)

import Arvo.Common (KingId(..), ServId(..))
import Arvo.Common (NounMap, NounSet)
import Arvo.Common (Desk, Mime)
import Arvo.Common (Header(..), HttpEvent)
import Arvo.Common (AmesDest, Ipv4, Ipv6, Port, Turf)
import Arvo.Common (ReOrg(..), reorgThroughNoun)

import qualified Network.HTTP.Types.Method as H


-- Misc Types ------------------------------------------------------------------

type Pass = Atom -- Public Key
type Rift = Atom -- Continuity number
type Life = Word -- Number of Azimoth key revs.
type Bloq = Atom -- TODO
type Ring = Atom -- Private Key
type Oath = Atom -- Signature


-- Parsed URLs -----------------------------------------------------------------

type Host = Either Turf Ipv4
type Hart = (Bool, Maybe Atom, Host)
type Pork = (Maybe Knot, [Cord])
type Quay = [(Cord, Cord)]

data PUrl = PUrl Hart Pork Quay
  deriving (Eq, Ord, Show)

deriveNoun ''PUrl


-- Dawn Records ----------------------------------------------------------------

data Seed = Seed Ship Life Ring (Maybe Oath)
  deriving (Eq, Ord, Show)

type Public = (Life, NounMap Life Pass)

data Dnses = Dnses { dPri::Cord, dSec::Cord, dTer::Cord }
  deriving (Eq, Ord, Show)

type EthAddr = Bytes -- 20 bytes
type ContNum = Word

data EthPoint = EthPoint
    { epOwn :: (EthAddr, EthAddr, EthAddr, EthAddr)
    , epNet :: Maybe (Life, Pass, ContNum, (Bool, Ship), Maybe Ship)
    , epKid :: Maybe (EthAddr, NounSet Ship)
    }
  deriving (Eq, Ord, Show)

data EthEventId = EthEventId
    { eeiBlock :: Atom
    , eeiLog   :: Atom
    }
  deriving (Eq, Ord, Show)

data EthBookmark = EthBookmark
    { ebHeard       :: NounSet EthEventId
    , ebLatestBlock :: Atom
    }
  deriving (Eq, Ord, Show)

data Snap = Snap (NounMap Ship Public)
                 (Dnses, NounMap Ship EthPoint)
                 EthBookmark
  deriving (Eq, Ord, Show)

data Dawn = MkDawn
    { dSeed :: Seed
    , dShip :: Ship
    , dCzar :: NounMap Ship (Rift, Life, Pass)
    , dTurf :: [Turf]
    , dBloq :: Bloq
    , dNode :: (Maybe PUrl)
    , dSnap :: (Maybe Snap)
    }
  deriving (Eq, Ord, Show)

deriveNoun ''EthEventId
deriveNoun ''EthBookmark
deriveNoun ''Dnses
deriveNoun ''EthPoint
deriveNoun ''Snap
deriveNoun ''Seed
deriveNoun ''Dawn


-- HTTP ------------------------------------------------------------------------

type ServerId = Atom

data Address
    = AIpv4 Ipv4
    | AIpv6 Ipv6
    | AAmes Ship
  deriving (Eq, Ord, Show)

data HttpRequest = HttpRequest
    { reqMeth :: H.StdMethod
    , reqUrl  :: Cord
    , reqHead :: [Header]
    , reqBody :: Maybe File
    }
  deriving (Eq, Ord, Show)

data HttpServerReq = HttpServerReq
    { hsrSecure  :: Bool
    , hsrAddress :: Address
    , hsrRequest :: HttpRequest
    }
  deriving (Eq, Ord, Show)

data HttpClientEv
    = HttpClientEvReceive (KingId, ()) ServerId HttpEvent
    | HttpClientEvBorn    (KingId, ()) ()
    | HttpClientEvCrud    Path       Cord Tang
  deriving (Eq, Ord, Show)

data HttpServerEv
    = HttpServerEvRequest       (ServId, UD, UD, ()) HttpServerReq
    | HttpServerEvCancelRequest (ServId, UD, UD, ()) ()
    | HttpServerEvRequestLocal  (ServId, UD, UD, ()) HttpServerReq
    | HttpServerEvLive          (ServId, ())         Port (Maybe Port)
    | HttpServerEvBorn          (KingId, ())         ()
    | HttpServerEvCrud          Path                 Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''Address
deriveNoun ''HttpClientEv
deriveNoun ''HttpRequest
deriveNoun ''HttpServerEv
deriveNoun ''HttpServerReq


-- Ames ------------------------------------------------------------------------

data AmesEv
    = AmesEvHear ()   AmesDest Bytes
    | AmesEvWake ()   ()
    | AmesEvWant Path Ship Path Noun
    | AmesEvCrud Path Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''AmesEv


-- Arvo Events -----------------------------------------------------------------

data ArvoEv
    = ArvoEvWhom () Ship
    | ArvoEvWack () Word512
    | ArvoEvWarn Path Noun
    | ArvoEvCrud Path Cord Tang
    | ArvoEvVeer Atom Noun
  deriving (Eq, Ord, Show)

deriveNoun ''ArvoEv


-- Boat Events -----------------------------------------------------------------

data BoatEv
    = BoatEvBoat ()   ()
    | BoatEvCrud Path Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''BoatEv


-- Timer Events ----------------------------------------------------------------

data BehnEv
    = BehnEvWake ()           ()
    | BehnEvBorn (KingId, ()) ()
    | BehnEvCrud Path         Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''BehnEv


-- Newt Events -----------------------------------------------------------------

data NewtEv
    = NewtEvBarn (Atom, ()) ()
    | NewtEvCrud Path       Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''NewtEv


-- FileSystem Events -----------------------------------------------------------

data SyncEv
    = SyncEvInto (Nullable (KingId, ())) Desk Bool [(Path, Maybe Mime)]
    | SyncEvCrud Path                    Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''SyncEv


-- Terminal Events -------------------------------------------------------------

data LegacyBootEvent
    = Fake Ship
    | Dawn Dawn
  deriving (Eq, Ord, Show)

data ArrowKey = D | L | R | U
  deriving (Eq, Ord, Show)

data Belt
    = Aro ArrowKey
    | Bac ()
    | Ctl Cord
    | Del ()
    | Met Cord
    | Ret ()
    | Txt Tour
  deriving (Eq, Ord, Show)

data TermEv
    = TermEvBelt (UD, ()) Belt
    | TermEvBlew (UD, ()) Word Word
    | TermEvBoot (UD, ()) LegacyBootEvent
    | TermEvHail (UD, ()) ()
    | TermEvCrud Path       Cord Tang
  deriving (Eq, Ord, Show)

deriveNoun ''LegacyBootEvent
deriveNoun ''ArrowKey
deriveNoun ''Belt
deriveNoun ''TermEv


-- Events for Device Drivers ---------------------------------------------------

data BlipEv
    = BlipEvAmes       AmesEv
    | BlipEvArvo       ArvoEv
    | BlipEvBehn       BehnEv
    | BlipEvBoat       BoatEv
    | BlipEvHttpClient HttpClientEv
    | BlipEvHttpServer HttpServerEv
    | BlipEvNewt       NewtEv
    | BlipEvSync       SyncEv
    | BlipEvTerm       TermEv
  deriving (Eq, Ord, Show)

deriveNoun ''BlipEv


-- Boot Events -----------------------------------------------------------------

data Vane
    = VaneVane VaneEv
    | VaneZuse ZuseEv
  deriving (Eq, Ord, Show)

data VaneName
    = Ames | Behn | Clay | Dill | Eyre | Ford | Gall | Iris | Jael
  deriving (Eq, Ord, Show, Enum, Bounded)

data ZuseEv
    = ZEVeer () Cord Path BigCord
    | ZEVoid Void
  deriving (Eq, Ord, Show)

data VaneEv
    = VEVeer (VaneName, ()) Cord Path BigCord
    | VEVoid Void
  deriving (Eq, Ord, Show)

deriveNoun ''Vane
deriveNoun ''VaneName
deriveNoun ''VaneEv
deriveNoun ''ZuseEv


-- The Main Event Type ---------------------------------------------------------

data Ev
    = EvBlip BlipEv
    | EvVane Vane
  deriving (Eq, Ord, Show)

instance ToNoun Ev where
  toNoun = \case
    EvBlip v -> toNoun $ reorgThroughNoun (Cord "",     v)
    EvVane v -> toNoun $ reorgThroughNoun (Cord "vane", v)

instance FromNoun Ev where
  parseNoun = parseNoun >=> \case
    ReOrg ""     s t p v -> fmap EvBlip $ parseNoun $ toNoun (s,t,p,v)
    ReOrg "vane" s t p v -> fmap EvVane $ parseNoun $ toNoun (s,t,p,v)
    ReOrg _      _ _ _ _ -> fail "First path-elem must be ?($ %vane)"

-- Short Event Names -----------------------------------------------------------

{-
    In the case of the user hitting enter, the cause is technically a
    terminal event, but we don't display any name because the cause is
    really the user.
-}
getSpinnerNameForEvent :: Ev -> Maybe Text
getSpinnerNameForEvent = \case
    EvVane _ -> Nothing
    EvBlip b -> case b of
        BlipEvAmes _           -> Just "ames"
        BlipEvArvo _           -> Just "arvo"
        BlipEvBehn _           -> Just "behn"
        BlipEvBoat _           -> Just "boat"
        BlipEvHttpClient _     -> Just "iris"
        BlipEvHttpServer _     -> Just "eyre"
        BlipEvNewt _           -> Just "newt"
        BlipEvSync _           -> Just "clay"
        BlipEvTerm t | isRet t -> Nothing
        BlipEvTerm t           -> Just "term"
  where
    isRet (TermEvBelt _ (Ret ())) = True
    isRet _                       = False
