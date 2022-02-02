echo 
echo compiling...
echo 
g++ fractales.cpp -o fractales-cpp
g++ julia_set.cpp -o julia_set-cpp
echo 
echo running...
echo 
./fractales-cpp | lolcat
