g++-7 monster.cpp
./a.out < in > monster.out
g++-7 monster_brute.cpp
./a.out < in > monster_brute.out
diff monster.out monster_brute.out