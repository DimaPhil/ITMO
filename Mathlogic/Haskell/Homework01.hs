{-# LANGUAGE OverloadedStrings #-}
module Homework01 where
 
import System.IO
import Data.Char
import Data.List
import Text.ParserCombinators.Parsec

main = do
    handle <- openFile "task1.txt" ReadMode
    contents <- hGetContents handle
    let allLines = lines contents
        numberedLines = zipWith (\ n line -> show n ++ " - " ++ line) [0..] allLines
    putStr $ unlines numberedLines
    hClose handle
