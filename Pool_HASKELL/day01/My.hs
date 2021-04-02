mySucc :: Int -> Int
mySucc a = a + 1

myIsNeg :: Int -> Bool
myIsNeg a = a < 0

myAbs :: Int -> Int
myAbs a = a * (-1)

myMin :: Int -> Int -> Int
myMin a b | a < b = a | otherwise = b

myMax :: Int -> Int -> Int
myMax a b | a > b = a | otherwise = b

myTuple :: a -> b -> (a, b)
myTuple a b = (a,b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a,b)  = a

mySnd :: (a, b) -> b
mySnd (a,b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead[] = error "liste vide"
myHead(a:_) = a

myTail :: [a] -> [a]
myTail[] = error "liste vide"
myTail (a:b) = b

myLength :: [a] -> Int
myLength foldr (\x -> (+) 1 ) 0