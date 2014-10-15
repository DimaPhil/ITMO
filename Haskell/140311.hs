{-# LANGUAGE NoImplicitPrelude, RankNTypes #-}
module Test where

import Base

data LikeNumber n = LikeNumber 
    { sumNumber :: n -> n -> n
    , subNumber :: n -> n -> n
    , mulNumber :: n -> n -> n
    }

isInt = LikeNumber sumInt subInt mulInt
isFloat = LikeNumber sumFloat subFloat mulFloat

data LikeVector v = LikeVector
    { mapVector  :: forall a b . (a -> b) -> v a -> v b
    , zipVector  :: forall a b c . (a -> b -> c) -> v a -> v b -> v c
    , foldVector :: forall a . (a -> a -> a) -> v a -> a
    }

data Vector2D a = V2D a a
data Vector3D a = V3D a a a

map2D f (V2D x y)   = V2D (f x) (f y)
map3D f (V3D x y z) = V3D (f x) (f y) (f z)

zip2D f (V2D x y) (V2D x' y')      = V2D (f x x') (f y y')
zip3D f (V3D x y z) (V3D x' y' z') = V3D (f x x') (f y y') (f z z')

fold2D f (V2D x y)   = f x y
fold3D f (V3D x y z) = f (f x y) z

isVector2D = LikeVector map2D zip2D fold2D
isVector3D = LikeVector map3D zip3D fold3D

innerProduct :: LikeVector v -> LikeNumber n -> v n -> v n -> n
innerProduct lv ln v1 v2 = (foldVector lv) (sumNumber ln) ((zipVector lv) (mulNumber ln) v1 v2)

innerProduct2D = innerProduct isVector2D
innerProduct3D = innerProduct isVector3D

innerProductOverInteger = (\ln lv v1 v2 -> innerProduct lv ln v1 v2) isInteger
innerProductOverFloat   = (\ln lv v1 v2 -> innerProduct lv ln v1 v2) isFloat
