{-# LANGUAGE FlexibleContexts #-}

recurse :: String -> [Integer] -> Integer
recurse string list = case string of
    ""        -> list !! 0
    'L':xs    -> recurse xs $ (take (div (length list) 2)) list
    _:xs      -> recurse xs $ (drop (div (length list) 2)) list