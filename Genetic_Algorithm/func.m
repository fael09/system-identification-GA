d = dados';
j = 1;
tau = 0.1244;
km = 24.8884;
erro = 0;
for i = 1:36000
    t = d(j,1);
    j = j+1;
    if d(i,4) ~= d(i+1,4)
        j = 1;
    end
    if d(i,4)>0
        d(i,4) = d(i,4)- 0.7567;
    else
        d(i,4) = d(i,4) + 0.7443;
    end
    
    x(i) = (1 - (exp(-t/tau)))*km*d(i,4);
    erro = erro + abs(d(i,2)-x(i));
    
end
fit = 1 - erro/5000000
