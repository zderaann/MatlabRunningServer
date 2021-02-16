# MatlabRunningServer
Example for a server in python running Matlab functions


Requires: flask (pip install flask)


Server is located in matlap_server.py and an example sending a POST request is in matlab_test.py.The tested Matlab function is located in test.m.


Run example: python matlab_server.py  --matlab_path "C:/Program^ Files/MATLAB/R2020a/bin/matlab.exe" --matlab_script_folder D:/Documents --matlab_function test


Run test example: python matlab_test.py
