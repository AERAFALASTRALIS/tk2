--
-- EPITECH PROJECT, 2020
-- wolfram
-- File description:
-- wolfram
--

import System.Environment
import System.Exit

exitFail = exitWith (ExitFailure 84)

takeN :: Int -> [a] -> [a]
takeN n l = take (fromIntegral n) l

nextArgs :: [String] -> [String]
nextArgs [] = []
nextArgs (arg:args)
    | True = args
    | otherwise = []

verifyPositiveInt :: [Char] -> Bool
verifyPositiveInt [] = False
verifyPositiveInt y
    | length (filter (\x -> x >= '0' && x <= '9') y) == length y = True
    | otherwise = False

verifyInt :: [Char] -> Bool
verifyInt [] = False
verifyInt y
    | length (filter (\x -> x >= '0' && x <= '9' || x == '-') y) == length y = True
    | otherwise = False

ruleValid :: String -> Bool
ruleValid ruleValue
    | ruleValue == "30" = True
    | ruleValue == "90" = True
    | ruleValue == "110" = True
    | otherwise = False

checkRule :: [String] -> Bool
checkRule (x:xs)
    | x == "--rule" && ruleValid (xs!!0) = True
    | otherwise = False

checkStart :: String -> Bool
checkStart x
    | x == "--start" = True
    | otherwise = False

checkLine :: String -> Bool
checkLine x
    | x == "--lines" = True
    | otherwise = False

checkWindow :: String -> Bool
checkWindow x
    | x == "--window" = True
    | otherwise = False

checkMoove :: String -> Bool
checkMoove x
    | x == "--move" = True
    | otherwise = False

mainCheck :: [String] -> Int -> Int -> Int -> Int -> Int -> [Int]
mainCheck [] (-1) start line window moove = []
mainCheck [] rule start line window moove = [rule, start, line, window, moove]
mainCheck (arg:args) rule start line window moove
    | args == [] = []
    | verifyInt (args!!0) == False = []
    | checkRule (arg:args) = mainCheck (nextArgs args) (read (args!!0)) start line window moove
    | checkStart (arg) && isInteger = mainCheck (nextArgs args) rule (read (args!!0)) line window moove
    | checkLine (arg) && isInteger = mainCheck (nextArgs args) rule start (read (args!!0)) window moove
    | checkWindow (arg) && isInteger = mainCheck (nextArgs args) rule start line (read (args!!0)) moove
    | checkMoove (arg) = mainCheck (nextArgs args) rule start line window (read (args!!0))
    | otherwise = []
    where isInteger = verifyPositiveInt (args!!0)

fillSpace :: Int -> [Char] -> [Char]
fillSpace i tab
    | (i > 0) = fillSpace (i - 1) (tab ++ [' '])
    | True = tab

rule00 :: Char -> Char -> Char -> Bool
rule00 i j k
    | i == '*' && j == '*' && k == '*' = True
    | True = False

rule01 :: Char -> Char -> Char -> Bool
rule01 i j k
    | i == '*' && j == '*' && k == ' ' = True
    | True = False

rule02 :: Char -> Char -> Char -> Bool
rule02 i j k
    | i == '*' && j == ' ' && k == '*' = True
    | True = False

rule03 :: Char -> Char -> Char -> Bool
rule03 i j k
    | i == '*' && j == ' ' && k == ' ' = True
    | True = False

rule04 :: Char -> Char -> Char -> Bool
rule04 i j k
    | i == ' ' && j == '*' && k == '*' = True
    | True = False

rule05 :: Char -> Char -> Char -> Bool
rule05 i j k
    | i == ' ' && j == '*' && k == ' ' = True
    | True = False

rule06 :: Char -> Char -> Char -> Bool
rule06 i j k
    | i == ' ' && j == ' ' && k == '*' = True
    | True = False

rule07 :: Char -> Char -> Char -> Bool
rule07 i j k
    | i == ' ' && j == ' ' && k == ' ' = True
    | True = False

debug :: [Char] -> IO ()
debug [] = putChar 'E'
debug (x:xs) = do
    putChar x
    debug (xs)

create30Space :: [Char] -> Int -> Char
create30Space previousTab index
    | rule00 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule01 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule02 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule03 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule04 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule05 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule06 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule07 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | otherwise = ' '

create90Space :: [Char] -> Int -> Char
create90Space previousTab index
    | rule00 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule01 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule02 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule03 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule04 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule05 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule06 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule07 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | otherwise = ' '

create110Space :: [Char] -> Int -> Char
create110Space previousTab index
    | rule00 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule01 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule02 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule03 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | rule04 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule05 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule06 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = '*'
    | rule07 (previousTab!!(index - 1)) (previousTab!!index) (previousTab!!(index + 1)) == True = ' '
    | otherwise = ' '

printStartSpace :: Int -> [Char] -> Int -> Int -> IO ()
printStartSpace i tab startCtr start = do
    if (startCtr < start) then return ()
    else if (i <= 0) then return ()
    else do
        putChar ' '
        printStartSpace (i - 1) tab startCtr start

printEndSpace :: Int -> [Char] -> Int -> Int -> IO ()
printEndSpace i tab startCtr start = do
    if (startCtr < start) then return ()
    else if (i <= 0) then putStrLn ""
    else do
        putChar ' '
        printEndSpace (i - 1) tab startCtr start

printCharArray :: [Char] -> Int -> Int -> Int -> Int -> Int -> Int -> Int -> Int -> Int -> IO ()
printCharArray [' ', ' '] _ _ _ _ _ _ _ _ _ = return ()
printCharArray (x:xs) i firstCase secondCase window fixedMult fixedWindow startCtr start moove = do
    if (startCtr < start) then return ()
    else if (i == fixedMult || i + 1 == fixedMult) then printCharArray (xs) i firstCase secondCase window (fixedMult + 1) fixedWindow startCtr start moove
    else if (firstCase > 1) then printCharArray (xs) (i - 1) (firstCase - 1) secondCase (window + 1) fixedMult fixedWindow startCtr start (moove - 1)
    else if (window >= fixedWindow + secondCase - 1) then return ()
    else if (moove > 0) then printCharArray (xs) (i - 1) firstCase secondCase (window + 1) fixedMult fixedWindow startCtr start (moove - 1)
    else do
        putChar x
        printCharArray (xs) (i - 1) firstCase secondCase (window + 1) fixedMult fixedWindow startCtr start moove
fillArray :: [Char] -> [Char] -> Int -> Int -> Int -> Int -> [Char]
fillArray tab previous rule 0 fixedMult i = tab ++ [' ', ' ']
fillArray tab previous rule loop fixedMult i = do
    if (loop == fixedMult) then fillArray (tab ++ [' ', ' ']) previous rule loop (fixedMult + 1) i
    else do
        if (rule == 30) then
            if (previous == []) then fillArray (tab ++ ['*']) previous rule (loop - 1) fixedMult (i + 1)
            else fillArray (tab ++ [create30Space previous (i)]) previous rule (loop - 1) fixedMult (i + 1)
        else if (rule == 90) then
            if (previous == []) then fillArray (tab ++ ['*']) previous rule (loop - 1) fixedMult (i + 1)
            else fillArray (tab ++ [create90Space previous (i)]) previous rule (loop - 1) fixedMult (i + 1)
        else do
            if (previous == []) then fillArray (tab ++ ['*']) previous rule (loop - 1) fixedMult (i + 1)
            else fillArray (tab ++ [create110Space previous (i)]) previous rule (loop - 1) fixedMult (i + 1)

mainLoop :: [Int] -> [Char] -> Int -> Int -> IO ()
mainLoop args previous i mult = do
    let line = fillArray [] previous (args!!0) mult mult 1
    printStartSpace (args!!3 `div` 2 - i + args!!4) line i (args!!1)
    if ((-(args!!3 `div` 2) - args!!4) + i - ((args!!3 `div` 2) - args!!2) > 0) then
        printCharArray line mult ((mult - args!!3 + 1) `div` 2 - args!!4) ((mult - args!!3 + 1) `div` 2 - args!!4) 0 mult (args!!3) i (args!!1) ((-(args!!3 `div` 2) - args!!4) + i)
    else printCharArray line mult ((mult - args!!3 + 1) `div` 2 - args!!4) ((mult - args!!3 + 1) `div` 2 - args!!4) 0 mult (args!!3) i (args!!1) 0
    printEndSpace (args!!3 `div` 2 - i - 1) line i (args!!1)
    if (args!!2 == -1 || i < args!!2 + args!!1 - 1) then mainLoop args line (i + 1) (mult + 2)
    else return ()

main :: IO ()
main = do
    args <- getArgs
    let parsedIntArgs = mainCheck args (-1) 0 (-1) 80 0
    if (parsedIntArgs == []) then exitFail
    else do
        mainLoop parsedIntArgs [] 0 1
        if (parsedIntArgs == []) then exitFail
        else return ()