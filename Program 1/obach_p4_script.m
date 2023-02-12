r = [-1
        -2];
s = [-3
         3];
u = [2
        -1];
v = [3
        1];
w = [1
        3];

M = [-1 -3  2  3  1;
     -2  3 -1  1  3];

plot(M);

rs = dot(r,s);
uv = dot(u,v);
sv = dot(s,v);

fileID = fopen('obach_p4_rs.txt','w');
fprintf(fileID,'%d', rs);
fclose(fileID);

fileID = fopen('obach_p4_sv.txt','w');
fprintf(fileID,'%d', sv);
fclose(fileID);

fileID = fopen('obach_p4_uv.txt','w');
fprintf(fileID,'%d', uv);
fclose(fileID);