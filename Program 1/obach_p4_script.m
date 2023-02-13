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
legend({'r','s','u','v','w'},'Location','southwest')

rs = 0;
uv = 0;
sv = 0;

for i = 1:2
    rs = rs + r(i)*s(i);
end

for i = 1:2
    uv = uv + u(i)*v(i);
end

for i = 1:2
    sv = sv + s(i)*v(i);
end

fileID = fopen('obach_p4_rs.txt','w');
fprintf(fileID,'%d', rs);
fclose(fileID);

fileID = fopen('obach_p4_sv.txt','w');
fprintf(fileID,'%d', sv);
fclose(fileID);

fileID = fopen('obach_p4_uv.txt','w');
fprintf(fileID,'%d', uv);
fclose(fileID);