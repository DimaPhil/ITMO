{-# LANGUAGE UnicodeSyntax, NoImplicitPrelude #-}

module Level0.Functions where

import Base

infixr 0 $
($) :: (a -> b) -> (a -> b)
($) f x = f x

-- f x (g y)
--Now can write f x $ g y

at :: a -> (a -> b) -> b
at x f = f x

plus = \x -> x

f = hole

g :: Int -> Float -> Double
g = hole

h :: Int -> Int -> Float
h = hole


x' = f $ g 1 $ h 1 2
x = 1 `at` plus

infixr 9 .
(.) :: (b -> c) -> (a -> b) -> (a -> c)
(.) f g x = f (g x)

--f . g = f(g(x))

(.>) :: (a -> c) -> (c -> d) -> (a -> d)
(.>) f g = g . f

infixl 0 `on`
on :: (b -> b -> c) -> (a -> b) -> a -> a -> c
on f g x y = f (g x) (g y)


{-fromIntToFloat :: Int -> Float
fromIntToFloat = hole

compareFloat :: Float -> Float -> Ordering
compareFloat = hole

compareInt :: Int -> Int -> Ordering
compareInt x y = compareFloat `on` fromIntToFloat

data Person = PersonDesc
  { name :: String
  , money :: Float
  } 

comparePerson :: Person -> Person -> Ordering
comparePerson = compareFloat `on` money -}

($$) :: (c -> d) -> (a -> b -> c) -> (a -> b -> d)
--($$) g f x y = g $ f x y
($$) g f = (g.). f

{- round :: Float -> Int
round = hole


sumRound :: Float -> Float -> Int
sumRound x y = ($$) round sumFloat x y -}