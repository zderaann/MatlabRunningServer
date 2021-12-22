# MatlabRunningServer
Example for a server in python running Matlab functions using command line


Requires: flask (pip install flask), libcurl for C++ example (https://curl.se/libcurl/)


Server is located in matlap_server.py and an example sending a POST request is in matlab_test.py.The tested Matlab function is located in test.m. Change the URL in the matlab_test file to the IP running on your server.
Change the MATLAB call depending on the system the server will be running on (commented section FOR LINUX and FOR WINDOWS).


Run example: 

              python matlab_server.py  --matlab_path "C:/Program^ Files/MATLAB/R2020a/bin/matlab.exe" --matlab_script_folder D:/Documents --matlab_function test


Run test example in python: 

                            python matlab_test.py

Run test example in C++ (using g++): 

                                     g++ -ggdb -g -c VS_test.cpp -o VS_test.o

                                     g++ -ggdb -g -o VS_test VS_test.o -lm -lcurl
                                     
                                     ./VS_test

# Running InLoc demo on mServer
To run SPRING InLoc demo on mServer, run the run_inloc_demo.py script. This script requires image path as a an argument.
Example:

                            python run_inloc_demo.py /local/imgs/img1.jpg
                            
