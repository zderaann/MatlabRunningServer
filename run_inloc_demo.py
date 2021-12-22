import os
import sys

img_name = sys.argv[1]
answer = os.popen( 'matlab -nodisplay -nosplash -r "cd(\'/local/localization_service/Code/Matlab/SPRING/SPRING_Demo\');run_demo(\'' + img_name + '\')' + ';exit;"').read()
parsed = answer.split('\n')
linestart = 'Pose results: '
poseindex = [line.startswith(linestart) for line in parsed]
index = poseindex.index(1)
line = parsed[index]
rotation = line.split('q = (')[1].split(')')[0].split(', ')
translation = line.split('t = (')[1].split(')')[0].split(', ')

print('Rotation acquired: [' + ', '.join(rotation) + '], translation acquired: [' + ', '.join(translation) + ']')