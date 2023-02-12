tr = r.'

ts = s.'

tv = v.'

tw = w.'

tu = u.'

fileID = fopen('obach_p6_mat1.txt','w');
fprintf(fileID,'%d', tr);
fclose(fileID);
fileID = fopen('obach_p6_mat2.txt','w');
fprintf(fileID,'%d', ts);
fclose(fileID);
fileID = fopen('obach_p6_mat3.txt','w');
fprintf(fileID,'%d', tu);
fclose(fileID);
 fileID = fopen('obach_p6_mat4.txt','w');
fprintf(fileID,'%d', tv);
fclose(fileID);
fileID = fopen('obach_p6_mat5.txt','w');
fprintf(fileID,'%d', tw);
fclose(fileID);