echo 
echo compiling...
echo 
g++ fractales.cpp -o fractales-cpp
g++ mandelbrot_zoom.cpp -o mandelbrot_zoom-cpp
g++ julia_set.cpp -o julia_set-cpp
echo 
echo running...
echo 
./fractales-cpp | lolcat
