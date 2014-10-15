{-# LANGUAGE NoImplicitPrelude, RankNTypes #-}

module Test where

import Base
--import Level0.Functions

data Vector2D a = V2D a a
data Vector3D a = V3D a a a

mapVec2D f (V2D x y) = V2D (f x) (f y)
mapVec3D f (V3D x y z) = V3D (f x) (f y) (f z)

zipVec2D f (V2D x y) (V2D x' y') = V2D (f x x') (f y y')
zipVec3D f (V3D x y z) (V3D x' y' z') = V3D (f x x') (f y y') (f z z')

foldVec2D f (V2D x y) = f x y
foldVec3D f (V3D x y z) = f (f x y) z

class LikeVectorClass v where
  vMap :: (a -> b) -> v a -> v b              
  vZip :: (a -> b -> c) -> v a -> v b -> v c
  vFold :: (a -> a -> a) -> v a -> a            

instance LikeVectorClass Vector2D where
  vMap = mapVec2D
  vZip = zipVec2D
  vFold = foldVec2D

class LikeNumberClass a where
  (+) :: a -> a -> a
  (*) :: a -> a -> a

instance LikeNumberClass Float where
  (+) = sumFloat
  (*) = mulFloat

infixr 9 .
(.) :: (b -> c) -> (a -> b) -> (a -> c)
(.) f g x = f (g x)

ginnerProduct :: (LikeVectorClass v, LikeNumberClass a) => v a -> v a -> a
--ginnerProduct x y = vFold (+) (vZip (*) x y)
ginnerProduct x = vFold (+) . vZip (*) x

x :: Float
x = ginnerProduct (V2D 1 1) (V2D 2 2)
