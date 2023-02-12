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

rpluss = 0;
splusw = 0;
uminusv = 0;

for i = 1:2
    rpluss(i) = r(i) + s(i);
end

for i = 1:2
    splusw(i) = s(i) + w(i);
end

for i = 1:2
    uminusv(i) = u(i) - v(i);
end

M = [-4 -2 -1 ;
      1  6 -2];

plot(M);